/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:44 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/23 16:13:32 by gcosta-m         ###   ########.fr       */
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

static int	get_line(char **str, char **line, int fd, t_util util)
{
	char	*tmp;

	util.aux = 0;
	while (str[fd][util.aux] && str[fd][util.aux] != '\n')
		util.aux++;
	*line = ft_substr(str[fd], 0, util.aux);
	if (!str[fd][util.aux])
	{
		tmp = str[fd];
		str[fd] = NULL;
		free(tmp);
		return (EOF_R);
	}
	else
	{
		tmp = str[fd];
		str[fd] = ft_strdup((str[fd]) + util.aux + 1);
		free(tmp);
	}
	if (!*line || !str[fd])
		return (ERROR);
	if (util.out || (util.out == 0 && str[fd] != NULL))
		return (LINE);
	return (ERROR);
	
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	t_util		util;
	char		*tmp;

	util.buffer = NULL;
	if (fd < 0 || !line || fd == 1 || fd == 2 || fd >= MAX_FD || !(util.buffer = malloc(BUFF_SIZE + 1)))
		return (ERROR);
	if (!str[fd])
		if (!(str[fd] = ft_strdup("")))
			return (ERROR);
	while (( util.out = read(fd, util.buffer, BUFF_SIZE)))
	{
		tmp = str[fd];
		util.buffer[util.out] = '\0';
		if (!(str[fd] = ft_strjoin(str[fd], util.buffer)))
			return (-1);
		free(tmp);
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
	}
	free(util.buffer);
	return (get_line(str, line, fd, util));
}
