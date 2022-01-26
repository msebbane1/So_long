/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:22:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 12:47:37 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_player(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/p1.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_collectible(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/key.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_exit(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/door-closed.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_background(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/back.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_walls(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/tree.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}
