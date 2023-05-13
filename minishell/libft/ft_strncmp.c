/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:54:54 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:12:15 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*char_cmp1;
	unsigned char	*char_cmp2;

	i = -1;
	char_cmp1 = (unsigned char *)s1;
	char_cmp2 = (unsigned char *)s2;
	while (++i < n)
	{
		if (char_cmp1[i] != char_cmp2[i])
			return (char_cmp1[i] - char_cmp2[i]);
		if (!char_cmp1[i])
			break ;
	}
	return (0);
}
