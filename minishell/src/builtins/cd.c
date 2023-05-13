/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:37:17 by dameneze          #+#    #+#             */
/*   Updated: 2023/04/25 19:43:14 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*path_oldpwd(void)
{
	t_match	match;
	char	*tmp;

	if (ft_match("OLDPWD", &match))
	{
		tmp = ft_strdup(match.value);
		free(match.value);
	}
	else
	{
		ft_putendl_fd("OLDPWD not set", 2);
		tmp = getcwd(NULL, 0);
	}
	return (tmp);
}

char	*path_til(char *str)
{
	char	*home;
	t_match	match;
	char	*temp;

	if (ft_match("HOME", &match))
	{
		home = ft_strdup(match.value);
		free(match.value);
	}
	else
		return (NULL);
	if (str[1])
	{
		temp = ft_strjoin(home, &str[1]);
		free(home);
	}
	else
	{
		temp = ft_strdup(home);
		free(home);
	}
	return (temp);
}

int	get_directory(char *path, char *pwd)
{
	if (chdir(path) == -1)
	{
		ft_putendl_fd("cd: no such file or directory", 2);
		free(pwd);
		free(path);
		return (1);
	}
	else
	{
		change_pwd(pwd);
		free(path);
	}
	return (0);
}

char	*empty_path(void)
{
	char	*temp;
	t_match	match;

	if (ft_match("HOME", &match))
		temp = ft_strdup(match.value);
	else
	{
		return (NULL);
	}
	free(match.value);
	return (temp);
}

int	ft_cd(char *str)
{
	char	*pwd;
	char	*tmp;

	pwd = getcwd(NULL, 0);
	if (!str)
		tmp = empty_path();
	else
	{
		if (!ft_strncmp(str, "-", ft_strlen(str)))
			tmp = path_oldpwd();
		else if (!ft_strncmp(str, "~", 1))
			tmp = path_til(str);
		else
			tmp = ft_strdup(str);
	}
	if (tmp == NULL)
	{
		free(pwd);
		return (1);
	}
	if (get_directory(tmp, pwd))
		return (1);
	free(pwd);
	return (0);
}
