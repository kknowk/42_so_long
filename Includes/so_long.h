/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:14:14 by khorike           #+#    #+#             */
/*   Updated: 2023/06/29 15:29:25 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <mlx.h>

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_UP 126
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_RIGHT 124

typedef struct s_game
{
	ssize_t		hei;
	ssize_t		wid;
	char		*str_line;
	void		*mlx;
	void		*win;
	struct {
		void	*wall;
		void	*chest;
		void	*chara;
		void	*rune;
		void	*land;
	} s_img;
	ssize_t		player_x;
	ssize_t		player_y;
	ssize_t		kaigyou_count;
	ssize_t		item_count;
	ssize_t		total__item_count;
	ssize_t		error;
	int			counter;
	int			top;
	int			new_x;
	int			new_y;
	int			now_item_iti;
	int			item_error;
	int			esc;
}	t_game;

# define MAX_SIZE 1500

typedef struct s_Point{
	int	x;
	int	y;
}	t_Point;

char	*ft_strdup_without_newline(char *str);
char	*ft_strjoin_without_newline(char *s1, char *s2, t_game *game);
char	*ft_temp_sj(t_game *game, char *line, int fd);
int		ft_count_letter(char *str, char target);

int		setting_img(void *param);

char	*first_read(char *filename, t_game *game);
char	*map_read(char *filename, t_game *game);

void	move_player_up(t_game *game);
void	move_player_down(t_game *game);
void	move_player_right(t_game *game);
void	move_player_left(t_game *game);
void	exit_game(t_game *game);

void	draw_wall(t_game *game, size_t x, size_t y);
void	draw_chest(t_game *game, size_t x, size_t y);
void	draw_player(t_game *game, size_t x, size_t y);
void	draw_rune(t_game *game, size_t x, size_t y);
void	draw_land(t_game *game, size_t x, size_t y);

void	put_error(char	*s, t_game *game);
char	*ft_close(int fd);
char	*ft_free(char *line);
bool	ft_bool_free(char *line);
char	*ft_free_close(char *line, int fd, t_game *game);
char	*ft_free_close_2(char *line, int fd, t_game *game);

char	*check_read_map(t_game *game);
char	*check_read_map_2(t_game *game);
char	*check_read_map_3(t_game *game);

bool	isvalid(t_game *game, int x, int y);
bool	isvalid2(t_game *game, int x, int y);
void	process_neighbor(t_game *game, bool visited[], t_Point stack[]);
void	process_neighbor2(t_game *game, bool visited[], t_Point stack[]);
bool	can_reach_goal(t_game *game);
bool	can_reach_chara(t_game *game);

#endif