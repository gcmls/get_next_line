/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:44 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/02/23 17:39:19 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**Description: Write a function which returns
**a line read from a file descriptor, without the newline.
**Parameters:
**	1. file descriptor for reading
**	2. The value of what has been read
**Return value:
**	1 : A line has been read
**	0 : EOF has been reached
**	-1 : An error happened
*/

static char	ft_lineread(char *ptr, char **line, char **str)
{
	char	*mem;

	*line = ft_substr(*str, 0, ft_strlen(*str) - ft_strlen(ptr));
	mem = *str;
	*str = ft_substr(*str, ft_strlen(*line) + 1, ft_strlen(*str));
	ft_strdel(&mem);
	return (1);
}

static char	ft_endread(char **str, char **line)
{
	if (ft_strlen(*str) > 0)
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*mem;
	char		*ptr;
	int			out;

	mem = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	ptr = ft_strchr(str, '\n');
	if (ptr)
		return (ft_lineread(ptr, line, &str));
	while ((out = read(fd, buff, BUFF_SIZE)) != -1)
	{
		buff[out] = '\0';
		if (!out)
			break ;
		mem = str;
		str = ft_strjoin(str, buff);
		ft_strdel(&mem);
		ptr = ft_strchr(buff, '\n');
		if (ptr)
			return (ft_lineread(ptr, line, &str));
	}
	if (out == -1)
		return (-1);
	return (ft_endread(&str, line));
}

