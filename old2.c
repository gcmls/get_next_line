/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:44 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/16 16:26:52 by gcosta-m         ###   ########.fr       */
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

static int	ft_add_line(char **str, char **line)
{
	char	*tmp;
	size_t		i;
	
	i = 0;
	while ((*str)[i] != '\0' && (*str)[i] !='\n')
		i++;
	if ((*str[i] == '\n'))
	{
		*line = ft_substr(*str, 0, i);
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	ft_out(char **str, char **line, int out, int fd)
{
	if (out < 0)
		return (-1);
	else if (out == 0 && str[fd] == NULL)
		return (0);
	else
		return (ft_add_line(&str[fd], line));	
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			out;

	if (fd < 0 || !line || fd == 1 || fd == 2 || BUFF_SIZE <= 0)
		return (ERROR);
	while ((out = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[out] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;			
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ft_out(str, line, out, fd));
}

