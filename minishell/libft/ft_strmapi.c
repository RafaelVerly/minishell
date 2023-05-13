/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:54:10 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	Applies the function ’f’ to each character of the
*	string ’s’, and passing its index as first argument
*	to create a new string (with malloc(3)) resulting
*	from successive applications of ’f’.
*	PARAMETERS
*	#1 - The string on which to iterate.
*	#2 - The function to apply to each character.
*	RETURN VALUES
*	The string created from the successive applications of ’f’.
*	Returns NULL if the allocation fails.
*/

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*alloc;
	size_t	i;

	if (!s)
		return (NULL);
	alloc = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!alloc)
		return (NULL);
	i = -1;
	while (s[++i])
		alloc[i] = (*f)(i, s[i]);
	alloc[i] = 0;
	return (alloc);
}
