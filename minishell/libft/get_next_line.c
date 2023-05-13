/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 00:14:54 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:17 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*new_line(char **last_buf, char **read)
{
	size_t		len;
	char		*line;

	line = NULL;
	if (ft_strchr(*read, '\n'))
	{
		if (ft_strlen(ft_strchr(*read, '\n')) > 1)
		{
			*last_buf = ft_strdup(ft_strchr(*read, '\n') + 1);
			len = ft_strlen(*read);
			line = ft_substr(*read, 0, len - ft_strlen(*last_buf));
			free (*read);
			return (line);
		}
	}
	return (*read);
}

static char	*read_next_line(int fd, char *str_join, int rtrn, char *buf)
{
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rtrn = read(fd, buf, BUFFER_SIZE);
	buf[rtrn] = 0;
	if (rtrn >= 1)
	{
		temp = str_join;
		str_join = ft_strjoin(temp, buf);
		free (temp);
		if (!ft_strchr(str_join, '\n'))
		{
			free (buf);
			return (read_next_line(fd, str_join, rtrn, buf));
		}
	}
	free (buf);
	if (rtrn < 0)
	{
		free (str_join);
		return (NULL);
	}
	return (str_join);
}

char	*get_next_line(int fd)
{
	static char	*last_buf;
	char		*read;
	char		*buf;

	buf = NULL;
	read = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (last_buf)
	{
		read = ft_strdup(last_buf);
		free (last_buf);
		last_buf = NULL;
		if (!ft_strchr(read, '\n'))
			read = read_next_line(fd, read, 0, buf);
	}
	else
		read = read_next_line(fd, ft_strdup(""), 0, buf);
	if (read == NULL || !read[0])
	{
		free (read);
		free (last_buf);
		return (NULL);
	}
	return (new_line(&last_buf, &read));
}
