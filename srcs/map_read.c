/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:07:20 by khorike           #+#    #+#             */
/*   Updated: 2023/06/30 13:14:30 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	game->item_error = 0;
	line = first_read(filename, game);
	if (!line)
		return (NULL);
	fd = open(filename, O_RDONLY);
	ft_free(get_next_line(fd));
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line && !ft_free_close(line, fd, game))
			return (ft_close(fd));
		if (line)
			game->str_line = ft_temp_sj(game, line, fd);
		if (game->error)
			return (ft_close(fd));
		free(line);
	}
	close(fd);
	game->total__item_count = ft_count_letter(game->str_line, 'C');
	return (filename);
}

char	*first_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		return (ft_close(fd));
	line = get_next_line(fd);
	if (!line)
		return (ft_close(fd));
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	if (!game->str_line || game->str_line[0] == '\0')
		return (ft_free_close_2(line, fd, game));
	free(line);
	close(fd);
	return (game->str_line);
}
