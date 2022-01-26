/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:22:17 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 17:38:22 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	img_player2(t_conf *conf, int keycode)
{
	static int	c = 0;

	if (keycode == A && c % 2)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p3.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == A)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p3-2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	if (keycode == S && c % 2)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p1.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == S)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p1-2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	c++;
}

void	img_player(t_conf *conf, int keycode)
{
	static int	c = 0;

	if (keycode == D && c % 2)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p4.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == D)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p4-2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	if (keycode == W && c % 2)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else if (keycode == W)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/p2-2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	c++;
}

void	img_collectible(t_conf *conf)
{
	static int	c = 0;

	if (c % 2)
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/key.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/key2.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	c++;
}

void	img_exit(t_conf *conf)
{
	if (count_collectible(conf) != 0)
	{
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/door-closed.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	}
	if (count_collectible(conf) == 0)
	{
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/door-open.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	}
}

void	img_walls(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/tree.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}
