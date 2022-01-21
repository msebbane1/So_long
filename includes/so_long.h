/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:57 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/20 15:19:14 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "../GNL/get_next_line.h"
# include "struct.h"
# include "define.h"

int		ft_check_map(t_conf *conf);
char	error_msg(char *msg);
void	game_init(t_conf *conf);
int		open_images(t_conf	conf);
int		read_x_y(char **argv, t_conf *conf);
int		count_lines_y(int fd);
int		count_lines_x(int fd);
int		main(int argc, char **argv);
int		ft_read_map(char **argv, t_conf *conf);

#endif