/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:48:49 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:51:06 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	iter_env_var(char *arg, int *i, t_match match)
{
	int	j;

	if (match.match)
	{
		j = -1;
		while (g_shell.envp[match.pos][++j] != '=')
			(*i)++;
		return (0);
	}
	else
	{
		while (42)
		{
			j = -1;
			while (CH_FORBIDDEN[++j])
				if (!arg[*i] || arg[*i] == CH_FORBIDDEN[j])
					return (1);
			(*i)++;
		}
	}
}

int	check_expansion(char *arg, int *i)
{
	int		size;
	t_match	match;

	size = 0;
	if (arg[*i + 1] != '?')
	{
		(*i)++;
		if (!arg[*i])
			return (size + 1);
		if (ft_match(&arg[*i], &match))
			size = ft_strlen(match.value);
		iter_env_var(arg, i, match);
		free(match.value);
	}
	else
		size = size_exit_status(i);
	return (size);
}

int	size_exit_status(int *i)
{
	char	*exit_status;
	int		size;

	exit_status = ft_itoa(g_shell.exit_status);
	*i += 2;
	size = ft_strlen(exit_status);
	free(exit_status);
	return (size);
}

void	expansion_exit_status(char **new_arg, int *i, int *j)
{
	char	*exit_status;
	int		z;

	z = 0;
	exit_status = ft_itoa(g_shell.exit_status);
	while (exit_status[z] != '\0')
	{
		(*new_arg)[*j] = exit_status[z];
		z++;
		(*j)++;
	}
	(*i)++;
	free(exit_status);
}

void	get_expansion(char *arg, char **new_arg, int *i, int *j)
{
	t_match	match;
	int		z;

	z = -1;
	(*i)++;
	if (arg[*i] == '?')
		expansion_exit_status(new_arg, i, j);
	else
	{
		if (!arg[*i])
		{
			(*new_arg)[*j] = '$';
			(*j)++;
			return ;
		}
		if (ft_match(&arg[*i], &match))
			build_expansion(&match, new_arg, j);
		iter_env_var(arg, i, match);
		free(match.value);
	}
}
