/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:44:35 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:10:31 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (str[i] == ch)
			return (&str[i]);
	}
	return (NULL);
}
