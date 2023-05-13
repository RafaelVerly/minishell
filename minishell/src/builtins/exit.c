/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:04:27 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:38:44 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	finish(void)
{
	ft_arr_clear(g_shell.envp);
	clear_history();
	exit(g_shell.exit_status);
}

void	ft_exit(char *msg, int code, t_exec **exec)
{
	char	**args;

	if (msg != NULL)
		printf("%s", msg);
	g_shell.exit_status = code;
	if (exec != NULL)
	{
		args = (*exec)->arr_args;
		if (args != NULL)
		{
			if (!ft_strncmp(args[0], "exit", ft_strlen(args[0])))
			{
				if (!is_number(args[1]))
					g_shell.exit_status = ft_atoi(args[1]);
				else if (args[1] != NULL)
				{
					ft_putendl_fd("exit: numeric argument required", 2);
					g_shell.exit_status = 255;
				}
			}
		}
		ft_stack_clear(&*exec);
	}
	finish();
}
