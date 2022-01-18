/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:02:56 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 15:06:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_images(t_conf	*conf);

void	game_init(t_conf *conf)
{
	conf->mlx = mlx_init();
	conf->win = mlx_new_window(conf->mlx, 500, 500, "GAME");
	open_images(conf);
}