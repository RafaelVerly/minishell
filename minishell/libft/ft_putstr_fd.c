/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 00:56:36 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:11:38 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = -1;
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	}
}