/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:44:25 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:44 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	ch = (unsigned char)c;
	i = -1;
	while (s[++i])
		if (s[i] == ch)
			return ((char *)&s[i]);
	if (!ch)
		return ((char *)&s[i]);
	return (NULL);
}
