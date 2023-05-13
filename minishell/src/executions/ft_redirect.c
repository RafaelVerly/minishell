/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:00:22 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 18:17:39 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	child_sig(int signal)
{
	(void)signal;
	rl_replace_line("", 0);
	rl_redisplay();
	rl_on_new_line();
	ft_exit(NULL, 130, NULL);
}

static void	heredoc_input(char *str, int fdout)
{
	char	*input;
	int		len;

	signal(SIGINT, child_sig);
	len = ft_strlen(str);
	clear_history();
	while (1)
	{
		input = readline("> ");
		if (!input)
		{
			free(input);
			ft_exit(NULL, 1, NULL);
		}
		if (!ft_strncmp(str, input, len) && ft_strlen(input) == (size_t)len)
			break ;
		ft_putendl_fd(input, fdout);
	}
	if (!input)
		free(input);
	close(fdout);
	free(str);
	ft_exit(NULL, 0, NULL);
}

static int	heredoc(t_red *red)
{
	int		fd[2];
	int		pid;
	int		wstatus;

	if (pipe(fd) == -1)
		ft_exit(NULL, 1, NULL);
	pid = fork();
	if (pid == -1)
		ft_exit(NULL, 1, NULL);
	signal(SIGINT, SIG_IGN);
	if (!pid)
	{
		close(fd[0]);
		heredoc_input(ft_strdup(red->val), fd[1]);
	}
	else
		close(fd[1]);
	waitpid(pid, &wstatus, 0);
	signal(SIGINT, SIG_DFL);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) == 130)
	{
		close(fd[0]);
		return (-1);
	}
	return (fd[0]);
}

int	ft_redirect(t_exec **exec, t_red *red)
{
	while (red)
	{
		if (red->type == RDRO)
			(*exec)->fd[1] = open(red->val, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (red->type == RDROO)
			(*exec)->fd[1] = open(red->val, O_CREAT | O_APPEND | O_RDWR, 0644);
		if (red->type == RDRI)
			(*exec)->fd[0] = open(red->val, O_RDONLY);
		if (red->type == RDRII)
			(*exec)->fd[0] = heredoc(red);
		if ((*exec)->fd[0] == -1)
			return (2);
		if ((*exec)->fd[1] == -1)
		{
			perror(red->val);
			return (1);
		}
		red = red->next;
	}
	return (0);
}
