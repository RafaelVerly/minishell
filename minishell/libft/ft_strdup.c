/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:45:02 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*   Allocates sufficient memory for the copy of string s1,
*   copy and returns a pointer to it.
*	PARAMETERS
*	#1 - The string to duplicate.
*	RETURN VALUES
*   On success, returns a pointer to the duplicated string.
*   It returns NULL if insufficient memory was available.
*/

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		size;
	char	*dest;

	size = ft_strlen(src);
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, src, size);
	dest[size] = 0;
	return (dest);
}
