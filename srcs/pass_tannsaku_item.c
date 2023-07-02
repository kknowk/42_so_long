/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_tannsaku_item.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:30:54 by khorike           #+#    #+#             */
/*   Updated: 2023/06/28 20:18:34 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ischara(t_game *game, int x, int y)
{
	return (game->str_line[x + (y * game->wid)] == 'P');
}

static size_t	search_chara(t_game *game)
{
	if (!game->str_line)
		return (0);
	while (game->str_line[game->now_item_iti])
	{
		if (game->str_line[game->now_item_iti] == 'C')
			return (game->now_item_iti);
		game->now_item_iti++;
	}
	return (0);
}

static bool	find_path2(t_game *game, bool visited[], t_Point stack[])
{
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	int			i;
	t_Point		curr;

	while (game->top >= 0)
	{
		curr = stack[game->top];
		game->top--;
		if (ischara(game, curr.x, curr.y))
			return (true);
		i = 0;
		while (i < 4)
		{
			game->new_x = curr.x + dx[i];
			game->new_y = curr.y + dy[i];
			process_neighbor2(game, visited, stack);
			i++;
		}
	}
	return (false);
}

bool	turai_kitui(t_game *game)
{
	if (game->item_error == 0)
		return (true);
	return (false);
}

bool	can_reach_chara(t_game *game)
{
	t_Point	stack[MAX_SIZE];
	t_Point	start;
	bool	visited[MAX_SIZE * MAX_SIZE];
	size_t	start_index;
	int		i;

	i = 0;
	while (i++ < game->total__item_count)
	{
		start_index = search_chara(game);
		if (start_index == 0)
			game->item_error++;
		start.x = start_index % game->wid;
		start.y = start_index / game->wid;
		game->top = 0;
		game->new_x = 0;
		game->new_y = 0;
		ft_memset(visited, false, sizeof(visited));
		stack[game->top] = start;
		visited[start.x + (start.y * game->wid)] = true;
		if (!find_path2(game, visited, stack))
			game->item_error++;
		game->now_item_iti++;
	}
	return (turai_kitui(game));
}
