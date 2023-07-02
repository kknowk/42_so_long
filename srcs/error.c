/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:06:38 by khorike           #+#    #+#             */
/*   Updated: 2023/06/29 15:29:13 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_error(char	*s, t_game *game)
{
	free(game->mlx);
	if (s)
		write(STDOUT_FILENO, s, ft_strlen(s));
	exit (0);
}

char	*ft_close(int fd)
{
	close(fd);
	return (NULL);
}

char	*ft_free_close(char *line, int fd, t_game *game)
{
	(void)fd;
	if (ft_strlen(line) - 1 != 0)
	{
		if ((ft_strchr(line, '\n')
				&& ft_strlen(game->str_line) % (ft_strlen(line) - 1) != 0)
			|| (!ft_strchr(line, '\n')
				&& ft_strlen(game->str_line) % ft_strlen(line) != 0))
		{
			free(line);
			free(game->str_line);
			return (NULL);
		}
	}
	if (ft_strlen(line) - 1 == 0)
	{
		free(line);
		free(game->str_line);
		return (NULL);
	}
	return (line);
}

char	*check_read_map(t_game *game)
{
	if (51 < game->wid || 28 < game->hei)
		return (ft_free(game->str_line));
	if ((!ft_strchr(game->str_line, 'P') || !(ft_strchr(game->str_line, 'P')
				== ft_strrchr(game->str_line, 'P')))
		|| (!ft_strchr(game->str_line, 'E')
			|| !(ft_strchr(game->str_line, 'E')
				== ft_strrchr(game->str_line, 'E')))
		|| !ft_strchr(game->str_line, 'C'))
		return (ft_free(game->str_line));
	return (game->str_line);
}

char	*check_read_map_2(t_game *game)
{
	ssize_t	i;

	i = 0;
	while (i < (game->wid - 1) * (game->hei - 1))
	{
		if (!ft_strchr("10PEC", game->str_line[i]))
		{
			return (ft_free(game->str_line));
		}
		i++;
	}
	return (game->str_line);
}
