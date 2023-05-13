/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_match.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:07:12 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:47:49 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_is_builtin(char **arr_args)
{
	int	size;

	if (arr_args == NULL || arr_args[0] == NULL)
		return (2);
	size = ft_strlen(arr_args[0]);
	if ((!ft_strncmp(arr_args[0], "exit", size) && size == 4)
		|| (!ft_strncmp(arr_args[0], "pwd", size) && size == 3)
		|| (!ft_strncmp(arr_args[0], "cd", size) && size == 2)
		|| (!ft_strncmp(arr_args[0], "echo", size) && size == 4)
		|| (!ft_strncmp(arr_args[0], "env", size) && size == 3)
		|| (!ft_strncmp(arr_args[0], "export", size) && size == 6)
		|| (!ft_strncmp(arr_args[0], "unset", size) && size == 5))
		return (0);
	else
		return (1);
}

int	ft_builtin(t_exec *exec)
{
	int	size;

	size = ft_strlen(exec->arr_args[0]);
	if (!ft_strncmp(exec->arr_args[0], "exit", size) && size == 4)
	{
		if (exec->args_size > 2)
			return (3);
		return (2);
	}
	else if (!ft_strncmp(exec->arr_args[0], "pwd", size) && size == 3)
		g_shell.exit_status = ft_pwd();
	else if (!ft_strncmp(exec->arr_args[0], "cd", size) && size == 2)
		g_shell.exit_status = ft_cd(exec->arr_args[1]);
	else if (!ft_strncmp(exec->arr_args[0], "echo", size) && size == 4)
		g_shell.exit_status = ft_echo(exec->arr_args);
	else if (!ft_strncmp(exec->arr_args[0], "env", size) && size == 3)
		g_shell.exit_status = ft_env(exec->arr_args);
	else if (!ft_strncmp(exec->arr_args[0], "export", size) && size == 6)
		g_shell.exit_status = ft_export(exec->arr_args[1]);
	else if (!ft_strncmp(exec->arr_args[0], "unset", size) && size == 5)
		g_shell.exit_status = ft_unset(exec->arr_args[1]);
	else
		return (1);
	return (0);
}

int	change_pwd(char *old_pwd)
{
	t_match	match;
	char	*tmp;

	tmp = getcwd(NULL, 0);
	if (ft_match("OLDPWD", &match))
	{
		free(g_shell.envp[match.pos]);
		g_shell.envp[match.pos] = NULL;
		free(match.value);
		g_shell.envp[match.pos] = ft_strjoin("OLDPWD=", old_pwd);
	}
	if (ft_match("PWD", &match))
	{
		free(g_shell.envp[match.pos]);
		free(match.value);
		g_shell.envp[match.pos] = ft_strjoin("PWD=", tmp);
		free(tmp);
	}
	return (0);
}
