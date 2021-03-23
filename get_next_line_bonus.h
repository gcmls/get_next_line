/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:48 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/23 15:41:09 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

# define MAX_FD 4096
# define LINE 1
# define EOF_R 0
# define ERROR -1

typedef	struct		s_util
{
	char	*buffer;
	int64_t	out;
	int64_t	aux;
}					t_util;


int			get_next_line(const int fd, char **line);

/*
** utils
*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif