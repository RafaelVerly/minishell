/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:47:19 by dameneze          #+#    #+#             */
/*   Updated: 2022/11/19 19:04:45 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_size(unsigned int nb)
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

char	*ft_itoa(int n)
{
	char			*alloc;
	unsigned int	nbr;
	unsigned int	size;
	unsigned int	sign;

	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)(n);
	size = (unsigned int)ft_size(nbr);
	alloc = malloc(sizeof(char) * (size + 1 + sign));
	if (!alloc)
		return (NULL);
	if (n < 0)
		alloc[0] = '-';
	ft_create_string(nbr, alloc, size - 1 + sign);
	alloc[size + sign] = '\0';
	return (alloc);
}
