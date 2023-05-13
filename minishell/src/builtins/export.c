/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:46:21 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 20:24:51 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	copy_envp(char **new, t_match match, char *var_env)
{
	int	i;

	i = 0;
	while (g_shell.envp[i] != NULL)
	{
		new[i] = ft_strdup(g_shell.envp[i]);
		i++;
	}
	if (!match.match)
		new[i] = ft_strdup(var_env);
}

/*
static int	ft_add_var(char *var_env, t_match match)
{
	char	**aux;
	int		len;

	len = 0;
	while (g_shell.envp[len] != NULL)
			len++;
	if (!match.match)
		len++;
	else
	{
		free(g_shell.envp[match.pos]);
		g_shell.envp[match.pos] = ft_strdup(var_env);
	}
	aux = malloc((len + 1) * sizeof(char *));
	if (!aux)
		return (1);
	aux[len + 1] = NULL;
	copy_envp(aux, g_shell.envp);
	if (!match.match)
	{
		aux[len] = ft_strdup(var_env);
		//aux[len + 1] = NULL;
	}
	int i;
	i = 0;
	while(aux[i] != NULL)
	{
		printf("i: %i\n", i);
		i++;
	}
	printf("len: %i\n", len);
	ft_arr_clear(g_shell.envp);
	g_shell.envp = aux;
	return (0);
}
*/

int	parse_var_env(char *var_env)
{
	int	i;

	i = 0;
	while (var_env[i])
	{
		if (!ft_isalnum(var_env[i]) && var_env[i] != '_')
			break ;
		i++;
	}
	if (!var_env[i])
		return (1);
	if (var_env[i] == '=' && var_env[i + 1] != '=' && var_env[0] != '=')
		return (0);
	if (var_env[i] != '=')
		ft_putendl_fd("export: not valid in this context", 2);
	if (var_env[0] == '=' && !var_env[1])
		ft_putendl_fd("zsh: bad assignment", 2);
	if (var_env[0] == '=' && var_env[1])
		ft_putendl_fd("zsh: not found", 2);
	if (var_env[i] == '=' && var_env[i + 1] == '=' && var_env[i + 2])
		ft_putendl_fd("zsh: not found", 2);
	return (1);
}

void	ft_add_var(char *var_env, t_match match)
{
	int		len;
	char	**new_envp;

	len = 0;
	if (g_shell.envp != NULL)
		while (g_shell.envp[len] != NULL)
			len++;
	if (!match.match)
		len++;
	new_envp = ft_calloc((len + 3), sizeof(char *));
	new_envp[len] = NULL;
	if (match.match)
	{
		free(g_shell.envp[match.pos]);
		g_shell.envp[match.pos] = ft_strdup(var_env);
		copy_envp(new_envp, match, var_env);
	}
	else
		copy_envp(new_envp, match, var_env);
	ft_arr_clear(g_shell.envp);
	g_shell.envp = new_envp;
}

int	ft_export(char *var_env)
{
	t_match	match;

	if (var_env == NULL)
	{
		ft_env(NULL);
		return (0);
	}
	if (!parse_var_env(var_env))
	{
		ft_match(var_env, &match);
		ft_add_var(var_env, match);
		free(match.value);
	}
	else
		return (1);
	return (0);
}
