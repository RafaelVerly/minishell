/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:46:38 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*   Allocates (with malloc(3)) and returns a substring
*   from the string ’s’.
*   The substring begins at index ’start’ and is of
*   maximum size ’len’.
*	PARAMETERS
*   #1 - s: The string from which to create the substring.
*   #2 - start: The start index of the substring in the string ’s’.
*   #3 - len: The maximum length of the substring.
*	RETURN VALUES
*   The substring.
*   NULL if the allocation fails.
*/

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	s_len;
	size_t	size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	size = len + 1;
	if (start >= s_len)
	{
		alloc = malloc(sizeof(char));
		alloc[0] = 0;
		return (alloc);
	}
	else if (len >= s_len)
		size = s_len - start + 1;
	alloc = malloc(sizeof(char) * size);
	if (!alloc)
		return (NULL);
	ft_strlcpy(alloc, (char *)s + start, size);
	return (alloc);
}
