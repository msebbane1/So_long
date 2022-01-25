/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:22:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/25 16:08:18 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_player(t_conf *conf, int keycode)
{
	if (keycode == D)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/Coin.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == W)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/Bush.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == A)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/door.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == S)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/Bush.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/Bush.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
}

void	img_collectible(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/Coin.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_exit(t_conf *conf)
{
	if (count_collectible(conf) != 0)
	{
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/door.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	}
	if (count_collectible(conf) == 0)
	{
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/Rock.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	}
}

void	img_background(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/Grass.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_walls(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/Rock.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}
