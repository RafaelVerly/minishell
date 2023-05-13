/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:47:12 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_array_size(char const *s, char c)
{
	int				check;
	size_t			i;
	unsigned int	count;

	i = -1;
	check = 1;
	count = 0;
	while (++i <= ft_strlen(s))
	{
		if ((s[i] != c && check) || !s[i])
		{
			count++;
			check = 0;
		}
		else if (s[i] == c && !check)
			check = 1;
	}
	return (count);
}

static char	**ft_strings(char const *s, char **split, char c)
{
	int				check;
	size_t			i;
	size_t			count;
	size_t			start;

	i = -1;
	check = 1;
	count = -1;
	start = 0;
	while (++i <= ft_strlen(s) && ft_strlen(s))
	{
		if (s[i] != c && check)
		{
			if (s[i])
				count++;
			start = i;
			check = 0;
		}
		else if ((s[i] == c && !check) || !s[i])
		{
			split[count] = ft_substr(s, start, i - start);
			check = 1;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_array_size(s, c);
	split = (char **)malloc(size * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_strings(s, split, c);
	split[size - 1] = NULL;
	return (split);
}
