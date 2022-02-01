/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:54:31 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/31 15:44:31 by msebbane         ###   ########.fr       */
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
	void	*img2;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	pos;
}				t_data;

typedef struct s_map {
	char		**ptr;
	t_coord		size;
}	t_map;

typedef struct s_conf {
	t_map		map;
	t_player	player;
	void		*mlx;
	void		*win;
	t_data		img;
}	t_conf;

#endif