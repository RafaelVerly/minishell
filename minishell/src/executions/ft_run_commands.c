/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:59:41 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 17:20:16 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Fork for each command, unless there
	is only one execution and its a builtin.
	returns 0 for child process
	returns 1 for parent process
*/
static int	run_processes(t_exec **exec)
{
	t_exec	*temp;

	temp = *exec;
	while (*exec)
	{
		if (temp->next != NULL || ft_is_builtin((*exec)->arr_args))
		{
			(*exec)->pid = fork();
			if (((*exec)->err_rd == 1 && (*exec)->pid == 0)
				|| (*exec)->pid == -1)
				ft_exit(NULL, 1, NULL);
		}
		if ((*exec)->err_rd == 1 && temp->next == NULL)
			return (1);
		if ((*exec)->pid == 0 || ((*exec)->next == NULL && (*exec)->pid == -5))
		{
			ft_dup_fds(exec);
			ft_close_fds(&temp);
			ft_find_function(*exec);
			return (0);
		}
		*exec = (*exec)->next;
	}
	*exec = temp;
	return (1);
}

/*
	Wait for processes to finish
*/
static void	wait_pids(t_exec **exec)
{
	int		wstatus;
	t_exec	*temp;

	temp = *exec;
	wstatus = 0;
	while (*exec)
	{
		if ((*exec)->pid != -5)
		{
			waitpid((*exec)->pid, &wstatus, 0);
			if (WIFEXITED(wstatus))
				g_shell.exit_status = WEXITSTATUS(wstatus);
			else if (WIFSIGNALED(wstatus))
				g_shell.exit_status += 128 + WIFSIGNALED(wstatus);
		}
		*exec = (*exec)->next;
	}
	*exec = temp;
}

/*
	Run the commands in the stack
*/
void	ft_run_commands(t_exec **exec)
{
	int		fd[2];
	t_exec	*temp;
	int		rtn;

	temp = *exec;
	fd[0] = dup(0);
	fd[1] = dup(1);
	if (!ft_create_pipes(exec))
	{
		rtn = run_processes(&temp);
		if (rtn == 1)
			ft_close_fds(&temp);
		else if ((*exec)->next != NULL || (!rtn && temp->next != NULL))
			ft_exit(NULL, 0, NULL);
		else
		{
			dup2(fd[0], 0);
			dup2(fd[1], 1);
		}
	}
	close(fd[0]);
	close(fd[1]);
	wait_pids(&temp);
}
