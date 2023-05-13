/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:44:51 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*alloc;

	alloc = malloc(nelem * elsize);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nelem * elsize);
	return (alloc);
}
