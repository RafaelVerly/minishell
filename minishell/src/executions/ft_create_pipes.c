/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:03:29 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 17:02:28 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Create a pipe for each command
*/
int	ft_create_pipes(t_exec **exec)
{
	t_exec	*temp;
	int		flag;

	flag = 0;
	temp = *exec;
	while (*exec)
	{
		if ((*exec)->reds != NULL)
		{
			(*exec)->err_rd = ft_redirect(exec, (*exec)->reds);
			if ((*exec)->err_rd == 2)
				flag = 1;
		}
		if (pipe((*exec)->p_fd) == -1)
			ft_exit(NULL, 1, NULL);
		*exec = (*exec)->next;
	}
	*exec = temp;
	return (flag);
}
