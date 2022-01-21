/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 16:46:45 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_player
{
	int		counter;
	char	*count;
	int		coin;
	int		pos_x;
	int		pos_y;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	pos;
}				t_data;

typedef struct s_item {
	//t_coord	item_pos;
}	t_item;

typedef struct s_map {
	char		**ptr;
	t_coord		size;
}	t_map;

typedef struct s_tex
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
	char		*path;
}	t_tex;

typedef struct s_conf {
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_data		img;
	//t_tex		wall;
	//t_tex		door;
	//t_tex		item;
	//t_tex		avatar;
	//int		move_count;
	//t_coord size;
	//t_list	*item_list;
	//t_list	*exit_list;
	//t_coord	screen_res;
	//int		cube_size;
}	t_conf;

#endif