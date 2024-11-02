/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:46:55 by brivera           #+#    #+#             */
/*   Updated: 2024/10/31 12:30:48 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//------ LIBS ------//
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
//--- BUFFER_SIZE ---//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//-- GET NEXT LINE --//
char	*get_next_line(int fd);
char	*readmyfd(char *texread, int fd);
char	*createmyline(char *texread);
char	*update_texread(char *texread);
char	*freefree(char *texread, char *texread_print);
//
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t numele, size_t n);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
#endif
