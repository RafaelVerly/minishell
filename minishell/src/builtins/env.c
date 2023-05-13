/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:41:08 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 05:40:12 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(char **args)
{
	int	i;

	i = -1;
	if (args != NULL)
	{
		if (args[1] != NULL)
		{
			ft_putendl_fd("env: No such file or directory", 2);
			return (127);
		}
	}
	if (g_shell.envp != NULL)
		while (g_shell.envp[++i])
			printf("%s\n", g_shell.envp[i]);
	return (0);
}
