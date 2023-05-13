/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:01:04 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 18:45:38 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	Check if there is a redirect
*/
static int	ft_check_redirect(char *str)
{
	char	quote;
	int		i;

	i = -1;
	quote = 0;
	while (str[++i])
	{
		quote = ft_check_quote(str[i], quote);
		if ((str[i] == '>' || str[i] == '<') && !quote)
		{
			i = ft_sep_redirect(str, i, NULL);
			if (str[i] == '>' || str[i] == '<')
				return (1);
			if (str[i] == 0)
				return (2);
		}
	}
	return (0);
}

static int	check_quote_error(char *str)
{
	int		i;
	char	quote;
	int		quote_flag;

	i = -1;
	quote_flag = 0;
	while (str[++i] != '\0')
	{
		if (!quote_flag)
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				quote = str[i];
				quote_flag = 1;
				i++;
			}
		}
		if (quote_flag && str[i] == quote)
			quote_flag = 0;
	}
	if (quote_flag)
		return (1);
	return (0);
}

int	ft_check_trim(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] != ' ' && str[i] != '\t')
			count++;
	if (!count)
		return (1);
	return (0);
}

int	ft_check_input(char *str)
{
	if (ft_strnstr(str, "||||", ft_strlen(str))
		|| ft_strnstr(str, "|||", ft_strlen(str))
		|| ft_strnstr(str, ">>>", ft_strlen(str))
		|| ft_strnstr(str, "<<<", ft_strlen(str))
		|| ft_strnstr(str, "<<<<", ft_strlen(str))
		|| ft_check_redirect(str) != 0)
	{
		ft_putendl_fd("minishell: syntax error", 2);
		return (2);
	}
	if (ft_check_trim(str) == 1)
		return (1);
	if (check_quote_error(str))
	{
		ft_putendl_fd("minishell: syntax error: unexpected end of file", 2);
		return (2);
	}
	return (0);
}
