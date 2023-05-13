/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:47:19 by dameneze          #+#    #+#             */
/*   Updated: 2022/09/24 18:30:07 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_size(unsigned int nb)
{
	unsigned int	count;

	count = 0;
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

static void	ft_create_string(unsigned int nbr, char *alloc, int size)
{
	if (nbr >= 10)
		ft_create_string(nbr / 10, alloc, size - 1);
	alloc[size] = (char)((nbr % 10) + 48);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*alloc;
	unsigned int	size;

	size = ft_size(n);
	alloc = malloc(sizeof(char) * (size + 1));
	if (!alloc)
		return (NULL);
	ft_create_string(n, alloc, size - 1);
	alloc[size] = '\0';
	return (alloc);
}
