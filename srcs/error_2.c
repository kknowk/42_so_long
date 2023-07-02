/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:34:23 by khorike           #+#    #+#             */
/*   Updated: 2023/06/30 12:59:22 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free_close_2(char *line, int fd, t_game *game)
{
	if (game->str_line[0] == '\0')
		free(game->str_line);
	close(fd);
	free(line);
	return (NULL);
}

char	*ft_free(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

bool	ft_bool_free(char *line)
{
	free(line);
	return (false);
}

char	*check_read_map_3(t_game *game)
{
	ssize_t	x;
	ssize_t	y;
	ssize_t	i;

	y = -1;
	i = 0;
	while (++y < game->hei)
	{
		x = -1;
		while (++x < game->wid)
		{
			if ((y == 0 && game->str_line[x] != '1')
				|| (x == 0 && game->str_line[i] != '1') || ((x == game->wid - 1
						|| y == game->hei - 1) && game->str_line[i] != '1'))
				return (ft_free(game->str_line));
			i++;
		}
	}
	return (game->str_line);
}
