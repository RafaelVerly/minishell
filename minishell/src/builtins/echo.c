/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:47:16 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/24 14:47:17 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	is_attribute(char **arr_exec, int *flag_n)
{
	int	n;
	int	i;

	i = 1;
	n = 0;
	if (arr_exec[i][n] == '-')
	{
		n++;
		while (arr_exec[i][n] == 'n')
			n++;
		if (arr_exec[i][n] == '\0' && arr_exec[i][n - 1] == 'n')
			*flag_n = 1;
	}
}

int	ft_echo(char **arr_exec)
{
	int	i;
	int	flag_n;

	i = 1;
	flag_n = 0;
	if (arr_exec[i] == NULL)
	{
		printf("\n");
		return (0);
	}
	is_attribute(arr_exec, &flag_n);
	if (flag_n == 1)
		i++;
	while (arr_exec[i] != NULL)
	{
		printf("%s", arr_exec[i]);
		i++;
		if (arr_exec[i])
			printf(" ");
	}
	if (!flag_n)
		printf("\n");
	return (0);
}
