/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:15:07 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 03:46:45 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
	Free everything
*/
void	ft_stack_clear(t_exec **exec)
{
	t_exec	*temp;
	t_red	*temp_arg;

	while (*exec)
	{
		while ((*exec)->reds)
		{
			temp_arg = (*exec)->reds->next;
			if ((*exec)->reds->val != NULL)
				free((*exec)->reds->val);
			if ((*exec)->reds != NULL)
				free((*exec)->reds);
			(*exec)->reds = NULL;
			(*exec)->reds = temp_arg;
		}
		if ((*exec)->arr_args != NULL)
			ft_arr_clear((*exec)->arr_args);
		temp = (*exec)->next;
		free(*exec);
		*exec = NULL;
		(*exec) = temp;
	}
}

void	ft_arr_clear(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free (arr[i]);
			i++;
		}
		free (arr);
	}
}
