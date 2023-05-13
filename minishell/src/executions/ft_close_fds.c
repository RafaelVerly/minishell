/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:04:51 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/24 15:36:33 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Close the FDs for each command
*/
void	ft_close_fds(t_exec **exec)
{
	t_exec	*temp;

	temp = *exec;
	while (*exec)
	{
		close((*exec)->p_fd[0]);
		close((*exec)->p_fd[1]);
		if ((*exec)->fd[0] != -5)
			close((*exec)->fd[0]);
		if ((*exec)->fd[1] != -5)
			close((*exec)->fd[1]);
		*exec = (*exec)->next;
	}
	*exec = temp;
}
