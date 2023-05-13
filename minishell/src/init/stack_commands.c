/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:04:16 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 00:54:44 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Return the last stack of command
*/
static t_exec	*ft_get_last_stk(t_exec **exec)
{
	t_exec	*temp;
	t_exec	*last;

	if (!*exec)
		return (NULL);
	if (!(*exec)->next)
		return (*exec);
	temp = *exec;
	while ((*exec)->next)
		*exec = (*exec)->next;
	last = *exec;
	*exec = temp;
	return (last);
}

/*
	Add a stack for the command with the arguments
*/
static t_exec	*ft_stack_add(t_exec **exec)
{
	t_exec	*new;
	t_exec	*last;

	new = NULL;
	new = malloc(sizeof(t_exec));
	if (!new)
		ft_exit(NULL, 1, NULL);
	last = ft_get_last_stk(&*exec);
	new->prev = last;
	new->next = NULL;
	new->reds = NULL;
	new->arr_args = NULL;
	new->fd[0] = -5;
	new->fd[1] = -5;
	new->err_rd = 0;
	new->pid = -5;
	if (!*exec)
	{
		*exec = new;
		return (*exec);
	}
	last->next = new;
	return (new);
}

/*
	Create an array with the arguments
*/
static void	ft_arr_add(t_exec **exec, char *str, int i, int j)
{
	int		start;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		start = i;
		if (str[i] == '>' || str[i] == '<')
		{
			ft_init_red(*exec, &str[i]);
			break ;
		}
		else if (str[i])
		{
			i = ft_sep_string(str, start, 1);
			(*exec)->arr_args[j] = ft_substr(str, start, i - start);
			if ((*exec)->arr_args[j] == NULL)
				ft_exit(NULL, 1, NULL);
			j++;
		}
	}
}

/*
	Start lists for each pipe
*/
void	ft_init_stks(char *str, t_exec **exec)
{
	size_t	i;
	int		start;
	char	*arg;
	t_exec	*new;

	i = -1;
	arg = NULL;
	while (++i < ft_strlen(str))
	{
		start = i;
		new = ft_stack_add(&*exec);
		if (new == NULL)
			ft_exit(NULL, 1, NULL);
		i = ft_sep_string(str, start, 0);
		arg = ft_substr(str, start, i - start);
		if (arg == NULL)
			ft_exit(NULL, 1, NULL);
		new->args_size = ft_args_size(arg);
		new->arr_args = malloc((new->args_size + 1) * sizeof(char *));
		if (new->arr_args == NULL)
			ft_exit(NULL, 1, NULL);
		new->arr_args[new->args_size] = NULL;
		ft_arr_add(&new, arg, 0, 0);
		free (arg);
	}
}
