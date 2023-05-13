/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:57:18 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 05:24:01 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	run_exec(t_exec *exec, char **paths)
{
	char	*path_aux;
	char	*temp;
	int		i;

	i = 0;
	execve(exec->arr_args[0], exec->arr_args, g_shell.envp);
	while (paths[i] != NULL)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		path_aux = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(path_aux, exec->arr_args[0]);
		execve(temp, exec->arr_args, g_shell.envp);
		free(temp);
		free(path_aux);
		i++;
	}
	ft_putendl_fd("minishell: command not found", 2);
	ft_arr_clear(paths);
	ft_exit(NULL, 127, &exec);
}

int	ft_find_function(t_exec *exec)
{
	char	**paths;
	t_match	match;
	int		rtn;

	ft_match("PATH", &match);
	paths = ft_split(match.value, ':');
	if (match.value != NULL)
		free(match.value);
	rtn = ft_builtin(exec);
	if (rtn == 1)
		run_exec(exec, paths);
	else if (rtn == 2)
	{
		ft_arr_clear(paths);
		ft_exit("exit\n", 0, &exec);
	}
	else if (rtn == 3)
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	ft_arr_clear(paths);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
