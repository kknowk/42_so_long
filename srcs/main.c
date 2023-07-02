/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:21:04 by khorike           #+#    #+#             */
/*   Updated: 2023/07/01 12:34:24 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setting_img(void *param)
{
	t_game	*game;
	ssize_t	hei;
	ssize_t	wid;

	game = (t_game *)param;
	hei = -1;
	while (++hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->str_line[hei * game->wid + wid] == '1')
				draw_wall(game, wid, hei);
			else if (game->str_line[hei * game->wid + wid] == 'C')
				draw_chest(game, wid, hei);
			else if (game->str_line[hei * game->wid + wid] == 'P')
				draw_player(game, wid, hei);
			else if (game->str_line[hei * game->wid + wid] == 'E')
				draw_rune(game, wid, hei);
			else
				draw_land(game, wid, hei);
			wid++;
		}
	}
	return (0);
}

int	handle_key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
	{
		game->esc = 1;
		exit_game(game);
	}
	else if (key_code == KEY_W || key_code == KEY_ARROW_UP)
		move_player_up(game);
	else if (key_code == KEY_A || key_code == KEY_ARROW_LEFT)
		move_player_left(game);
	else if (key_code == KEY_S || key_code == KEY_ARROW_DOWN)
		move_player_down(game);
	else if (key_code == KEY_D || key_code == KEY_ARROW_RIGHT)
		move_player_right(game);
	return (0);
}

void	initialize_images(t_game *game)
{
	int		img_width;
	int		img_height;

	game->s_img.wall = mlx_xpm_file_to_image(game->mlx,
			"./images/wall.xpm", &img_width, &img_height);
	game->s_img.chest = mlx_xpm_file_to_image(game->mlx,
			"./images/chest.xpm", &img_width, &img_height);
	game->s_img.chara = mlx_xpm_file_to_image(game->mlx,
			"./images/chara.xpm", &img_width, &img_height);
	game->s_img.rune = mlx_xpm_file_to_image(game->mlx,
			"./images/cherry.xpm", &img_width, &img_height);
	game->s_img.land = mlx_xpm_file_to_image(game->mlx,
			"./images/land.xpm", &img_width, &img_height);
	game->hei = 0;
	game->wid = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->counter = 0;
	game->esc = 0;
	game->kaigyou_count = 0;
	game->item_count = 0;
	game->total__item_count = 0;
	game->error = 0;
	game->now_item_iti = 0;
	game->str_line = NULL;
}

int	handle_window_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free(game->str_line);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	main(int ac, char *av[])
{
	t_game	game;
	char	*filename;
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	game.mlx = mlx;
	filename = av[1];
	initialize_images(&game);
	if (ac != 2)
		put_error("Error\n", &game);
	if (!map_read(filename, &game) || (game.kaigyou_count != game.hei - 2))
		put_error("Error\n", &game);
	if (!check_read_map(&game) || !check_read_map_2(&game)
		|| !check_read_map_3(&game) || !can_reach_goal(&game)
		|| !can_reach_chara(&game))
		put_error("Error\n", &game);
	win = mlx_new_window(mlx, game.wid * 50, game.hei * 50, "my_mlx");
	mlx_hook(win, 17, 0, handle_window_close, &game);
	game.win = win;
	setting_img(&game);
	mlx_key_hook(game.win, handle_key_press, &game);
	mlx_loop_hook(mlx, setting_img, &game);
	mlx_loop(mlx);
	return (0);
}
