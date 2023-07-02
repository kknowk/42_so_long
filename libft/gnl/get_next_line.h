/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:34:39 by khorike           #+#    #+#             */
/*   Updated: 2023/06/29 12:27:38 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

# ifndef  BUFFER_SIZE

#  define  BUFFER_SIZE 2

# endif

char	*fr_strjoin_free_temp(char *buffer, char *buf);
char	*ft_left_line(char *buffer);
char	*ft_got_line(char *buffer);
char	*read_file(int fd, char *one_fd_line);
char	*get_next_line(int fd);

size_t	ft_strlen_kai(const char *s);
void	ft_bzero_kai(void *s, size_t n);
char	*ft_strchr_kai(const char *s, int c);
void	*ft_calloc_kai(size_t number, size_t size);
char	*ft_strjoin_kai(char const *s1, char const *s2);

char	*kusottare(char **one_fd_line);

#endif