/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:20:33 by khorike           #+#    #+#             */
/*   Updated: 2023/07/01 16:11:56 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fr_strjoin_free_temp(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_kai(buffer, buf);
	if (buffer)
		free(buffer);
	return (temp);
}

char	*ft_left_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)ft_calloc_kai((ft_strlen_kai(buffer) - i + 1), sizeof(char));
	if (!line)
	{
		if (buffer)
			free(buffer);
		return (line);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_got_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc_kai(i + 2, sizeof(char));
	if (!line)
	{
		if (buffer)
			free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *one_fd_line)
{
	char	*buffer;
	long	byte_read;

	buffer = (char *)ft_calloc_kai(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (kusottare(&one_fd_line));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (kusottare(&one_fd_line));
		}
		buffer[byte_read] = '\0';
		one_fd_line = fr_strjoin_free_temp(one_fd_line, buffer);
		if (!one_fd_line || ft_strchr_kai(one_fd_line, '\n'))
			break ;
	}
	free(buffer);
	return (one_fd_line);
}

char	*get_next_line(int fd)
{
	static char	*many_fd[OPEN_MAX];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	many_fd[fd] = read_file(fd, many_fd[fd]);
	if (!many_fd[fd])
		return (NULL);
	line = ft_got_line(many_fd[fd]);
	many_fd[fd] = ft_left_line(many_fd[fd]);
	return (line);
}
