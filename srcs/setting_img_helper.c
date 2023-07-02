/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:23:51 by khorike           #+#    #+#             */
/*   Updated: 2023/06/26 13:12:19 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->s_img.wall, x * 50, y * 50);
}

void	draw_chest(t_game *game, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->s_img.chest, x * 50, y * 50);
}

void	draw_player(t_game *game, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->s_img.chara, x * 50, y * 50);
	game->player_x = x;
	game->player_y = y;
}

void	draw_rune(t_game *game, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->s_img.rune, x * 50, y * 50);
}

void	draw_land(t_game *game, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->s_img.land, x * 50, y * 50);
}
