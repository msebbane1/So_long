/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:35:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 13:28:04 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	key_hook(int keycode, t_conf *conf)
{
	if (keycode == D || keycode == S || keycode == A || keycode == W
		|| keycode == ESCAPE)
	{
		key_move_player(keycode, conf);
		open_images(*conf, keycode);
		counter_steps(conf);
	}
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

int	game_over(t_conf *conf)
{
	mlx_destroy_window(conf->mlx, conf->win);
	printf("\033[0;31m" "GAME OVER...\n" "\033[0m");
	exit (0);
}

int	win_closed(t_conf *conf)
{
	mlx_destroy_window(conf->mlx, conf->win);
	printf("\033[0;32m" "Windows closed !\n" "\033[0m");
	exit (0);
}
