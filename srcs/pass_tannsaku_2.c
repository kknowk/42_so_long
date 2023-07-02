/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_tannsaku_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:29:19 by khorike           #+#    #+#             */
/*   Updated: 2023/06/28 19:43:04 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	isvalid(t_game *game, int x, int y)
{
	return (x >= 0 && x < game->wid && y >= 0
		&& y < game->hei && game->str_line[x + (y * game->wid)] != '1');
}

bool	isvalid2(t_game *game, int x, int y)
{
	return (x >= 0 && x < game->wid && y >= 0
		&& y < game->hei && game->str_line[x + (y * game->wid)] != '1'
		&& y < game->hei && game->str_line[x + (y * game->wid)] != 'E');
}

void	process_neighbor(t_game *game, bool visited[], t_Point stack[])
{
	t_Point	next;

	next.x = game->new_x;
	next.y = game->new_y;
	if (isvalid(game, game->new_x, game->new_y)
		&& !visited[game->new_x + (game->new_y * game->wid)])
	{
		game->top++;
		stack[game->top] = next;
		visited[game->new_x + (game->new_y * game->wid)] = true;
	}
}

void	process_neighbor2(t_game *game, bool visited[], t_Point stack[])
{
	t_Point	next;

	next.x = game->new_x;
	next.y = game->new_y;
	if (isvalid2(game, game->new_x, game->new_y)
		&& !visited[game->new_x + (game->new_y * game->wid)])
	{
		game->top++;
		stack[game->top] = next;
		visited[game->new_x + (game->new_y * game->wid)] = true;
	}
}
