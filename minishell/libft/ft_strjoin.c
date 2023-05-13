/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:46:47 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s2_len;
	size_t	s1_len;
	char	*alloc;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	alloc = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!alloc)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		alloc[i++] = s1[j++];
	j = 0;
	while (s2[j])
		alloc[i++] = s2[j++];
	alloc[i] = 0;
	return (alloc);
}
