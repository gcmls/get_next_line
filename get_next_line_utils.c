/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:37:51 by gcosta-m          #+#    #+#             */
/*   Updated: 2021/03/16 17:18:22 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		ret = malloc(1);
		ret[0] = '\0';
		return (ret);
	}
	size = ft_strlen(s + start);
	if (size > len)
		size = len;
	if (!ft_set((int64_t *)&ret, (int64_t)malloc(size + 1)))
		return (NULL);
	ret = ft_memcpy(ret, s + start, size);
	ret[size] = '\0';
	return (ret);
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t	i;

	if (!src && !dest)
		return (NULL);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size1;
	size_t	size2;

	if (!s2)
		return (NULL);
	if (!s1)
		size1 = 0;
	else
		size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (!ft_set((int64_t *)&join, (int64_t)malloc(size1 + size2 + 1)))
		return (NULL);
	ft_memcpy(join, s1, size1);
	ft_memcpy(join + size1, s2, size2 + 1);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (char)c != *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}