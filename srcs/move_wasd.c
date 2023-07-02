/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:28:57 by khorike           #+#    #+#             */
/*   Updated: 2023/06/28 14:57:12 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->str_line);
	if (game->esc == 0)
	{
		game->counter++;
		ft_printf("%s%d\n", "clear score", game->counter);
	}
	exit(0);
}

void	move_player_up(t_game *game)
{
	if (game->player_y > 0 && game->str_line[(game->player_y - 1)
			* game->wid + game->player_x] != '1')
	{
		game->str_line[game->player_y * game->wid + game->player_x] = '0';
		game->player_y--;
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'E')
		{
			if (game->item_count != game->total__item_count)
			{
				game->player_y++;
				game->str_line[game->player_y
					* game->wid + game->player_x] = 'P';
				return ;
			}
			exit_game(game);
		}
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'C')
			game->item_count++;
		game->str_line[game->player_y * game->wid + game->player_x] = 'P';
		game->counter++;
		ft_printf("%d\n", game->counter);
		mlx_clear_window(game->mlx, game->win);
		setting_img(game);
	}
}

void	move_player_left(t_game *game)
{
	if (game->player_x > 0 && game->str_line[game->player_y
			* game->wid + (game->player_x - 1)] != '1')
	{
		game->str_line[game->player_y * game->wid + game->player_x] = '0';
		game->player_x--;
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'E')
		{
			if (game->item_count != game->total__item_count)
			{
				game->player_x++;
				game->str_line[game->player_y
					* game->wid + game->player_x] = 'P';
				return ;
			}
			exit_game(game);
		}
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'C')
			game->item_count++;
		game->str_line[game->player_y * game->wid + game->player_x] = 'P';
		game->counter++;
		ft_printf("%d\n", game->counter);
		mlx_clear_window(game->mlx, game->win);
		setting_img(game);
	}
}

void	move_player_down(t_game *game)
{
	if (game->player_y < game->hei - 1 && game->str_line[(game->player_y + 1)
			* game->wid + game->player_x] != '1')
	{
		game->str_line[game->player_y * game->wid + game->player_x] = '0';
		game->player_y++;
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'E')
		{
			if (game->item_count != game->total__item_count)
			{
				game->player_y--;
				game->str_line[game->player_y
					* game->wid + game->player_x] = 'P';
				return ;
			}
			exit_game(game);
		}
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'C')
			game->item_count++;
		game->str_line[game->player_y * game->wid + game->player_x] = 'P';
		game->counter++;
		ft_printf("%d\n", game->counter);
		mlx_clear_window(game->mlx, game->win);
		setting_img(game);
	}
}

void	move_player_right(t_game *game)
{
	if (game->player_x < game->wid - 1 && game->str_line[game->player_y
			* game->wid + (game->player_x + 1)] != '1')
	{
		game->str_line[game->player_y * game->wid + game->player_x] = '0';
		game->player_x++;
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'E')
		{
			if (game->item_count != game->total__item_count)
			{
				game->player_x++;
				game->str_line[game->player_y
					* game->wid + game->player_x] = 'P';
				return ;
			}
			exit_game(game);
		}
		if (game->str_line[game->player_y * game->wid + game->player_x] == 'C')
			game->item_count++;
		game->str_line[game->player_y * game->wid + game->player_x] = 'P';
		game->counter++;
		ft_printf("%d\n", game->counter);
		mlx_clear_window(game->mlx, game->win);
		setting_img(game);
	}
}
