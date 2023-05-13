/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:45:27 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:40:20 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_remove_var(t_match match)
{
	char	**aux;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (g_shell.envp[len])
		len++;
	aux = ft_calloc(len, sizeof(char *));
	aux[len - 1] = NULL;
	if (!aux)
		ft_exit(NULL, 1, NULL);
	while (g_shell.envp[++i] != g_shell.envp[match.pos])
		aux[i] = ft_strdup(g_shell.envp[i]);
	while (g_shell.envp[++i] != NULL)
		aux[i - 1] = ft_strdup(g_shell.envp[i]);
	ft_arr_clear(g_shell.envp);
	g_shell.envp = aux;
	return (0);
}

int	ft_unset(char *var_env)
{
	t_match	match;

	if (var_env == NULL && var_env[0])
		return (1);
	if (ft_match(var_env, &match))
	{
		ft_remove_var(match);
		free (match.value);
	}
	return (0);
}
