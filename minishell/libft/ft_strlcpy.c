/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:27:44 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:01 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = -1;
	if (n)
	{
		while (src[++i] && i < n - 1)
			dest[i] = src[i];
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
