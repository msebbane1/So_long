/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 12:22:35 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../GNL/get_next_line.h"
# include "struct.h"
# include "key_hook.h"

int		ft_check_map(t_conf *conf);
void	img_player(t_conf *conf, int keycode);
void	img_collectible(t_conf *conf);
void	img_exit(t_conf *conf);
int		win_closed(t_conf *conf);
void	img_background(t_conf *conf);
void	img_walls(t_conf *conf);
void	counter_steps(t_conf *conf);
int		key_hook(int keycode, t_conf *conf);
int		player_coord(t_conf *conf);
int		key_move_player(int keycode, t_conf *conf);
int		key_player_win(int keycode, t_conf *conf);
int		game_over(t_conf *conf);
char	error_msg(char *msg);
void	game_init(t_conf *conf);
int		open_images(t_conf	conf, int keycode);
void	img_player2(t_conf *conf, int keycode);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		read_x_y(char **argv, t_conf *conf);
int		count_lines_y(int fd);
int		ft_strlen(char *s);
char	*ft_itoa(int n);
int		ft_len_nb(long n);
int		count_lines_x(int fd);
int		main(int argc, char **argv);
int		ft_read_map(char **argv, t_conf *conf);
int		count_collectible(t_conf *conf);
int		key_player_lose(int keycode, t_conf *conf);
int		end_game(t_conf *conf);
int		key_right(t_conf *conf);
int		key_up(t_conf *conf);
int		key_down(t_conf *conf);
int		key_left(t_conf *conf);

#endif