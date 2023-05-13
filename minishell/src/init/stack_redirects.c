/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:04:16 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 03:46:52 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Return the last redirect in the stack
*/
static t_red	*ft_get_last_red(t_red **red)
{
	t_red	*temp;
	t_red	*last;

	if (!*red)
		return (NULL);
	if (!(*red)->next)
		return (*red);
	temp = *red;
	while ((*red)->next)
		*red = (*red)->next;
	last = *red;
	*red = temp;
	return (last);
}

/*
	Add a new stack of redirects at the end
*/
static t_red	*ft_red_add(t_red **red)
{
	t_red	*new;
	t_red	*last;

	new = malloc(sizeof(t_red));
	if (!new)
		ft_exit(NULL, 1, NULL);
	last = ft_get_last_red(&*red);
	new->type = -1;
	new->prev = last;
	new->val = NULL;
	new->next = NULL;
	if (!*red)
	{
		*red = new;
		return (*red);
	}
	last->next = new;
	return (new);
}

/*
	Start list of redirects
*/
void	ft_init_red(t_exec *exec, char *str)
{
	size_t	i;
	int		start;
	t_red	*last;

	i = 0;
	while (i < ft_strlen(str))
	{
		last = ft_red_add(&exec->reds);
		if (last == NULL)
			ft_exit(NULL, 1, NULL);
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i] == '>' || str[i] == '<')
			i = ft_sep_redirect(str, i, last);
		start = i;
		i = ft_sep_string(str, start, 1);
		last->val = ft_substr(str, start, i - start);
	}
}
