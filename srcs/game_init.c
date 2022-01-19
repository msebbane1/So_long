/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:02:56 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/19 16:48:59 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_conf *conf)
{
	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, conf->map.size.x, conf->map.size.y, "GAME");
	open_images(*conf);
}