/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:44 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/16 17:24:42 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int64_t		ft_set(int64_t *a, int64_t b)
{
	*a = b;
	return (b);
}

static char	*ft_remove_line(char **str, t_util util)
{

	if (*str == NULL)
		return (ft_substr("", 0, 0));
	if (ft_strchr(*str, '\n'))
		util.out = ft_strchr(*str, '\n') - *str;
	else
		util.out = (size_t) - 1;
	util.ret = ft_substr(*str, 0, util.out);
	if (util.out != (size_t) - 1)
		util.tmp2 = ft_substr(*str, util.out + 1, (size_t) - 1);
	else
		util.tmp2 = ft_substr("", 0, 0);
	free(*str);
	*str = util.tmp2;
	return (util.ret);
}

static int	get_line(char **str, char **line, int fd, t_util util)
{
	util.aux = 1;
	while (ft_strchr(str[fd], '\n') == NULL && util.aux)
	{
		util.buffer = malloc(BUFF_SIZE + 1);
		if (ft_set(&util.aux, read(fd, util.buffer, BUFF_SIZE)) > 0)
		{
			util.buffer[util.aux] = '\0';
			util.tmp = ft_strjoin(str[fd], util.buffer);
			free(str[fd]);
			str[fd] = util.tmp;
		}
		else if (util.aux == -1)
		{
			free(util.buffer);
			*line = NULL;
			return (-1);
		}
		free(util.buffer);
	}
	*line = ft_remove_line(&(str[fd]), util);
	return ((str[fd] && ft_strlen(str[fd]) != 0) || util.aux);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[MAX_FD];
	t_util		util;

	if (fd < 0 || !line || fd == 1 || fd == 2 || fd >= MAX_FD)
		return (-1);
	return (get_line(str, line, fd, util));
}