/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_fds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:05:53 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/24 15:37:01 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Dup the FDs for each command
*/
void	ft_dup_fds(t_exec **exec)
{
	if ((*exec)->fd[0] != -5)
		dup2((*exec)->fd[0], 0);
	else
	{
		if ((*exec)->prev && !(*exec)->next)
			dup2((*exec)->prev->p_fd[0], 0);
		if ((*exec)->next && (*exec)->prev)
			dup2((*exec)->prev->p_fd[0], 0);
	}
	if ((*exec)->fd[1] != -5)
		dup2((*exec)->fd[1], 1);
	else
	{
		if (!(*exec)->prev && (*exec)->next)
			dup2((*exec)->p_fd[1], 1);
		if ((*exec)->next && (*exec)->prev)
			dup2((*exec)->p_fd[1], 1);
	}
}
