/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 00:26:56 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 13:00:20 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Check if the quote is starting or ending.
	returns 0 if its ending
	returns quote if its starting
*/
int	ft_check_quote(char c, char quote)
{
	if (c == 34 || c == 39)
	{
		if (c == quote)
			quote = 0;
		else if (!quote)
			quote = c;
	}
	return (quote);
}

/*
	Returns the position (i) to separete the string
*/
int	ft_sep_string(char *str, int i, int type)
{
	char	quote;

	quote = 0;
	while (str[i])
	{
		quote = ft_check_quote(str[i], quote);
		if (str[i])
		{
			if (((type == 0 && str[i] != '|' && !quote) || quote) && str[i])
				i++;
			else if (type == 1 && str[i] != ' ' && str[i] != '\t' && !quote)
			{
				if (str[i] == '>' || str[i] == '<')
					break ;
				i++;
			}
			else
				break ;
		}
	}
	return (i);
}

/*
	Returns the size of arguments, before a redirect
*/
int	ft_args_size(char *str)
{
	int		count;
	int		i;
	char	quote;
	int		state;

	state = 0;
	i = -1;
	count = 0;
	quote = 0;
	while (str[++i])
	{
		quote = ft_check_quote(str[i], quote);
		if ((str[i] == '<' || str[i] == '>') && !quote)
			break ;
		if ((str[i] == ' ' || str[i] == '\t') && !quote)
			state = 0;
		else if (!state)
		{
			state = 1;
			count++;
		}
	}
	return (count);
}

/*
	Returns the position of the next word after the redirect
*/
int	ft_sep_redirect(char *str, int i, t_red *red)
{
	if (str[i] == '<' && str[i + 1] == '<')
	{
		i++;
		if (red != NULL)
			red->type = RDRII;
	}
	else if (str[i] == '<')
		if (red != NULL)
			red->type = RDRI;
	if (str[i] == '>' && str[i + 1] == '>')
	{
		i++;
		if (red != NULL)
			red->type = RDROO;
	}
	else if (str[i] == '>')
		if (red != NULL)
			red->type = RDRO;
	i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	return (i);
}

int	ft_match(char *var, t_match *match)
{
	int	pos;
	int	i;

	pos = 0;
	while (g_shell.envp[pos])
	{
		i = 0;
		while (g_shell.envp[pos][i] != '=')
			i++;
		if (ft_strncmp(var, g_shell.envp[pos], i) == 0)
		{
			match->pos = pos;
			match->match = 1;
			match->value = ft_strdup(ft_strchr(g_shell.envp[pos], '=') + 1);
			return (1);
		}
		pos++;
	}
	match->value = NULL;
	match->match = 0;
	return (0);
}
