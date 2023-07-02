/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_tansaku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:36:05 by khorike           #+#    #+#             */
/*   Updated: 2023/06/28 19:33:23 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	isgoal(t_game *game, int x, int y)
{
	return (game->str_line[x + (y * game->wid)] == 'E');
}

static size_t	search_p(t_game *game)
{
	size_t	i;

	i = 0;
	if (!game->str_line)
		return (0);
	while (game->str_line[i])
	{
		if (game->str_line[i] == 'P')
			return (i);
		i++;
	}
	return (0);
}

static bool	find_path(t_game *game, bool visited[], t_Point stack[])
{
	static int	dx[] = {-1, 0, 1, 0};
	static int	dy[] = {0, 1, 0, -1};
	int			i;
	t_Point		curr;

	while (game->top >= 0)
	{
		curr = stack[game->top];
		game->top--;
		if (isgoal(game, curr.x, curr.y))
			return (true);
		i = 0;
		while (i < 4)
		{
			game->new_x = curr.x + dx[i];
			game->new_y = curr.y + dy[i];
			process_neighbor(game, visited, stack);
			i++;
		}
	}
	return (false);
}

bool	can_reach_goal(t_game *game)
{
	t_Point	stack[MAX_SIZE];
	t_Point	start;
	bool	visited[MAX_SIZE * MAX_SIZE];
	size_t	start_index;

	start_index = search_p(game);
	start.x = start_index % game->wid;
	start.y = start_index / game->wid;
	game->top = 0;
	game->new_x = 0;
	game->new_y = 0;
	ft_memset(visited, false, sizeof(visited));
	stack[game->top] = start;
	visited[start.x + (start.y * game->wid)] = true;
	return (find_path(game, visited, stack));
}
