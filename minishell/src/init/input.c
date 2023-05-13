/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:11:19 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/24 23:59:38 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	Function that gets only the text before ||
*/
static char	*ft_before_pipes(char *str)
{
	int		i;
	char	*new_str;

	new_str = NULL;
	i = -1;
	while (str[++i])
		if (str[i] == '|' && str[i + 1] == '|')
			new_str = ft_substr(str, 0, i - 1);
	if (new_str == NULL)
	{
		new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
		if (new_str == NULL)
			ft_exit(NULL, 1, NULL);
		ft_strlcpy(new_str, str, ft_strlen(str) + 1);
	}
	return (new_str);
}

/*
	Get the input from user and organize
*/
void	ft_input_init(char **input)
{
	char	*new_str;
	t_exec	*exec;

	exec = NULL;
	new_str = ft_before_pipes(*input);
	free (*input);
	ft_init_stks(new_str, &exec);
	free (new_str);
	ft_new_args(&exec);
	ft_run_commands(&exec);
	ft_stack_clear(&exec);
}
