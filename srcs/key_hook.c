/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:35:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 16:58:09 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_conf *conf)
{
	key_move_player(keycode, conf);
	open_images(*conf);
	counter_steps(conf);
	return (0);
}

int	collectible(t_conf *conf)
{

	//conf->player.coin = 10; // compter les coolectible dan sune fonction
	while (conf->map.ptr[conf->player.pos_y][conf->player.pos_y] == 'C')
		conf->player.coin--;
	return (0);
}

/*
int	end_game(t_conf *conf)
{
	mlx_destroy_window(conf->mlx, conf->win);
	mlx_string_put(conf->mlx, conf->win, 500, 500, 0x00000000, "YOU WIN");
	
	if (conf->player.coin == 0)
	{
		mlx_destroy_window(conf->mlx, conf->win);
		mlx_string_put(conf->mlx, conf->win, 500, 500, 0x00000000, "YOU WIN");
	}
	return (0);
}*/