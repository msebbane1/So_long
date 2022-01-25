/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:35:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/25 16:04:51 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_conf *conf)
{
	key_move_player(keycode, conf);
	open_images(*conf, keycode);
	counter_steps(conf);
	return (0);
}

int	end_game(t_conf *conf)
{
	if (count_collectible(conf) == 0)
	{
		mlx_destroy_window(conf->mlx, conf->win);
		printf("\033[0;32m" "Congrats you win !\n" "\033[0m");
		exit (0);
	}
	return (0);
}
