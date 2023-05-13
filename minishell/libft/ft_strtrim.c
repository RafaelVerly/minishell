/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:47:04 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:27 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*   Applies the function ’f’ to each character of the
*   string ’s’, and passing its index as first argument
*   to create a new string (with malloc(3)) resulting
*   from successive applications of ’f’.
*	PARAMETERS
*	#1 - The string to be trimmed.
*	#2 -  The reference set of characters to trim.
*	RETURN VALUES
*   The trimmed string.
*   NULL if the allocation fails.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end)
		end--;
	str = ft_substr(s1, start, end - start + 1);
	return (str);
}
