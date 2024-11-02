/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:37:35 by brivera           #+#    #+#             */
/*   Updated: 2024/10/30 17:51:22 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		ps[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t numele, size_t n)
{
	unsigned char	*p;
	size_t			total_size;

	if (n != 0 && numele >= SIZE_MAX / n)
		return (NULL);
	total_size = numele * n;
	p = malloc(total_size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, total_size);
	return (p);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	unsigned char	pc;
	char			*ps;
	int				i;

	i = 0;
	pc = (unsigned char)c;
	ps = (char *)s;
	while (s[i] != '\0')
	{
		if (ps[i] == pc)
			return (&ps[i]);
		i++;
	}
	if (pc == '\0' && ps[i] == '\0')
		return (&ps[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(len + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i++] != '\0')
		s3[i - 1] = s1[i - 1];
	j = 0;
	while (s2[j] != '\0')
	{
		s3[i - 1 + j] = s2[j];
		j++;
	}
	s3[i - 1 + j] = '\0';
	return (s3);
}
