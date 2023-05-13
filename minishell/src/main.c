/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:39:27 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 20:36:35 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_shell	g_shell;

static char	*ft_format_string(void)
{
	char	*path;
	char	*temp;
	char	*print_path;

	path = getcwd(NULL, 0);
	if (path == NULL)
		ft_exit(NULL, 1, NULL);
	temp = ft_strjoin(CBLU, path);
	free (path);
	print_path = ft_strjoin(temp, "$> " CWHI);
	if (print_path == NULL)
		ft_exit(NULL, 1, NULL);
	free (temp);
	return (print_path);
}

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	char	*print_path;

	if (argc != 1 && argv)
		ft_exit("Wrong number of arguments\n", 1, NULL);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	g_shell.exit_status = 0;
	g_shell.envp = NULL;
	while (42)
	{
		print_path = ft_format_string();
		user_input = readline(print_path);
		free (print_path);
		if (!user_input)
			ft_exit("exit\n", 0, NULL);
		if (user_input[0] && !ft_check_trim(user_input))
			add_history(user_input);
		if (!g_shell.envp)
			ft_dup_envp(envp);
		if (!ft_check_input(user_input))
			ft_input_init(&user_input);
		else
			free(user_input);
	}
}
