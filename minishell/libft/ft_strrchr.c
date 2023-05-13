/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:44:11 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:24 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	The strchr() function returns a pointer to the first occurrence
*	of the character c in the string s.
*	PARAMETERS
*	#1 - The string on which to iterate.
*	#2 - The function to apply to each character.
*	RETURN VALUES
*	Return a pointer to the	matched character or NULL
*	if the character is not found.  The	terminating null byte is
*	considered part of the string, so that if c is specified as
*	'\0', these functions return a pointer to the terminator.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;
	int		last;

	ch = (char)c;
	i = 0;
	last = -1;
	while (s[i] >= 0)
	{
		if (s[i] == 0)
		{
			if (ch == 0)
				return ((char *)&s[i]);
			if (last != -1)
				return ((char *)&s[last]);
			return (NULL);
		}
		if (s[i] == ch)
			last = i;
		i++;
	}
	return (NULL);
}
