/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:59:45 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 15:40:34 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_quote(char *arg, int *i, char *quote)
{
	if (arg[*i] == '\'' || arg[*i] == '\"')
	{
		if (arg[*i] == *quote)
		{
			*quote = 0;
			(*i)++;
			return (1);
		}
		else if (!*quote)
		{
			*quote = arg[*i];
			(*i)++;
			return (1);
		}
	}
	return (0);
}

char	*build_arg(char *arg, int size)
{
	char	*new_arg;
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	new_arg = malloc((size + 1) * sizeof(char));
	new_arg[size] = '\0';
	while (arg[i] != '\0')
	{
		check_quote(arg, &i, &quote);
		if (quote != '\'')
			while (arg[i] == '$')
				get_expansion(arg, &new_arg, &i, &j);
		if (arg[i] && !check_quote(arg, &i, &quote))
			new_arg[j++] = arg[i++];
	}
	return (new_arg);
}

char	*no_quotes_arg(char *arg)
{
	int		i;
	char	quote;
	char	*new_arg;
	int		size;

	size = 0;
	i = 0;
	quote = 0;
	while (arg[i] != '\0')
	{
		check_quote(arg, &i, &quote);
		if (quote != '\'')
			while (arg[i] == '$')
				size += check_expansion(arg, &i);
		if (arg[i] && !check_quote(arg, &i, &quote))
		{
			i++;
			size++;
		}
	}
	new_arg = build_arg(arg, size);
	return (new_arg);
}

int	remove_quotes(char **arg)
{
	char	*new_arg;

	new_arg = no_quotes_arg(*arg);
	free(*arg);
	*arg = ft_strdup(new_arg);
	free(new_arg);
	return (0);
}

void	ft_new_args(t_exec **exec)
{
	t_exec	*exec_aux;
	t_red	*red_aux;
	int		i;

	exec_aux = *exec;
	if (*exec != NULL)
	{
		while (*exec)
		{
			i = -1;
			while ((*exec)->arr_args[++i] != NULL)
				remove_quotes(&(*exec)->arr_args[i]);
			red_aux = (*exec)->reds;
			while ((*exec)->reds)
			{
				remove_quotes(&(*exec)->reds->val);
				(*exec)->reds = (*exec)->reds->next;
			}
			(*exec)->reds = red_aux;
			*exec = (*exec)->next;
		}
		*exec = exec_aux;
	}
}
