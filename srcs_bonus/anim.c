/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:22:23 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 13:25:03 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	img_background(t_conf *conf)
{
	conf->img.img = mlx_xpm_file_to_image(conf->mlx,
			"./images/Sprite/back.xpm",
			&conf->img.pos.x, &conf->img.pos.y);
}

void	img_ennemy(t_conf *conf)
{
	static int	c = 0;

	if (c % 2)
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/ennemy.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	else
		conf->img.img = mlx_xpm_file_to_image(conf->mlx,
				"./images/Sprite/ennemy3.xpm",
				&conf->img.pos.x, &conf->img.pos.y);
	c++;
}

int	put_images(t_conf conf, int line, int c, int keycode)
{
	if (conf.map.ptr[line][c] == 'E')
		img_exit(&conf);
	else if (conf.map.ptr[line][c] == 'C')
		img_collectible(&conf);
	else if (conf.map.ptr[line][c] == 'P')
	{
		img_player(&conf, keycode);
		img_player2(&conf, keycode);
	}
	else if (conf.map.ptr[line][c] == 'S')
		img_ennemy(&conf);
	mlx_put_image_to_window(conf.mlx, conf.win, conf.img.img,
		64 * c, 64 * line);
	mlx_destroy_image(conf.mlx, conf.img.img);
	return (0);
}

int	open_images(t_conf conf, int keycode)
{
	int		line;
	int		c;

	line = 0;
	while (line < conf.map.size.y / 64)
	{
		c = 0;
		while (c < conf.map.size.x / 64)
		{
			put_images(conf, line, c, keycode);
			c++;
		}
		line++;
	}
	return (0);
}
