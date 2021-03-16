/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:48 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/16 17:22:01 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE 10
# endif

# define MAX_FD 4096

typedef	struct		s_util
{
	char	*buffer;
	char	*tmp;
	char	*tmp2;
	char	*ret;
	int64_t	out;
	int64_t	aux;
}					t_util;


int64_t		ft_set(int64_t *a, int64_t b);
int			get_next_line(const int fd, char **line);

/*
** utils
*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif