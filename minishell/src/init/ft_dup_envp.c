/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:48:49 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:51:18 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_dup_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	g_shell.envp = ft_calloc((i + 1), sizeof(char *));
	if (!g_shell.envp)
		ft_exit(NULL, 1, NULL);
	g_shell.envp[i] = NULL;
	i = -1;
	while (envp[++i] != NULL)
		g_shell.envp[i] = ft_strdup(envp[i]);
	return (0);
}

void	build_expansion(t_match *match, char **new_arg, int *j)
{
	int	z;

	z = -1;
	while (match->value[++z] != '\0')
	{
		(*new_arg)[*j] = match->value[z];
		(*j)++;
	}
}
