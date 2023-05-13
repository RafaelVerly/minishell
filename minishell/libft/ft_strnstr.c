/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 21:40:21 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:19 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	i = -1;
	if (!s2[0])
		return ((char *)s1);
	size = ft_strlen(s2);
	while (++i < n && s1[i] && size <= n - i)
		if (!ft_strncmp(s1 + i, s2, size))
			return ((char *)&s1[i]);
	return (NULL);
}
