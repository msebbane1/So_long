/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:38:41 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 16:29:38 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
// P deviens '0'vide et quand il prend +1 il redeviens P
//P prend +1 a chaque fois qu'il va vers la droite, changer la position + 1
// prendre en compte les pas du joueur //conf->player.steps++ printf("Steps : %d\n", conf->player.steps);


int	key_down(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_y += 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	return (0);
}

int	key_left(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_x -= 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	return (0);
}

int	key_up(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_y -= 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	return (0);
}

int	key_right(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_x += 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	return (0);
}

int	key_move_player(int keycode, t_conf *conf)
{
	int	pos_x;
	int	pos_y;

	pos_x = conf->player.pos_x;
	pos_y = conf->player.pos_y;

	if (keycode == ESCAPE)
	{
		mlx_destroy_window(conf->mlx, conf->win);
		exit (0);
	}
	else if (keycode == D && conf->map.ptr[pos_y][pos_x + 1] != '1')
		key_right(conf);
	else if (keycode == W && conf->map.ptr[pos_y - 1][pos_x] != '1')
		key_up(conf);
	else if (keycode == A && conf->map.ptr[pos_y][pos_x - 1] != '1')
		key_left(conf);
	else if (keycode == S && conf->map.ptr[pos_y + 1][pos_x] != '1')
		key_down(conf);
	return (0);
}

//=&& (base->map.ptr[base->game.p_y][base->game.p_x + 1] != '1'))