/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:02:56 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/18 15:28:21 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_conf *conf)
{
	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, conf->size.x *64, conf->size.y *64, "GAME");
	open_images(conf);
}