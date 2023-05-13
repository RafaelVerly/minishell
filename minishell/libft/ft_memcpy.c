/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:27:36 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:11 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (!dst && !src)
		return (NULL);
	i = -1;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (++i < n)
		d[i] = s[i];
	return (dst);
}
