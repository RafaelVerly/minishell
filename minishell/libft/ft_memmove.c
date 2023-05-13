/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:27:39 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:14 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (s < d)
		while (++i <= n)
			d[n - i] = s[n - i];
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
