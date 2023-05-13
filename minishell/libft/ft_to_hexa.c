/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:21:02 by dameneze          #+#    #+#             */
/*   Updated: 2022/09/24 22:02:07 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_size(unsigned long nb)
{
	unsigned int	count;

	count = 0;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	return (count + 1);
}

char	*ft_to_hexa(unsigned long ad, int upper)
{
	char			*hex;
	char			*alloc;
	unsigned int	size;
	unsigned int	i;

	if (ad == 0)
		return ("0");
	hex = "0123456789abcdef";
	if (upper == 1)
		hex = "0123456789ABCDEF";
	size = ft_size(ad);
	i = size;
	alloc = malloc(sizeof(char) * (size + 1));
	alloc[i] = 0;
	while (ad > 0)
	{
		alloc[--i] = hex[ad % 16];
		ad /= 16;
	}
	return (alloc);
}
