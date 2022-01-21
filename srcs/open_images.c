/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:22:23 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 15:19:39 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_images(t_conf conf, int line, int c)
{
	if (conf.map.ptr[line][c] == '1')
		conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/Rock.xpm",
				&conf.img.pos.x, &conf.img.pos.y);
	else if (conf.map.ptr[line][c] == '0')
		conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/Grass.xpm",
				&conf.img.pos.x, &conf.img.pos.y);
	else if (conf.map.ptr[line][c] == 'E')
		conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/door.xpm",
				&conf.img.pos.x, &conf.img.pos.y);
	else if (conf.map.ptr[line][c] == 'C')
		conf.img.img = mlx_xpm_file_to_image(conf.mlx,
				"./images/Sprite/Coin.xpm",
				&conf.img.pos.x, &conf.img.pos.y);
	else if (conf.map.ptr[line][c] == 'P')
		conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/Bush.xpm",
				&conf.img.pos.x, &conf.img.pos.y);
	mlx_put_image_to_window(conf.mlx, conf.win, conf.img.img, 16 * c, 16 * line);
	mlx_destroy_image(conf.mlx, conf.img.img);
	return (0);
}

int	open_images(t_conf conf)
{
	int		line;
	int		c;

	line = 0;
	while (line < conf.map.size.y / 16)
	{
		c = 0;
		while (c < conf.map.size.x / 16)
		{
			put_images(conf, line, c);
			c++;
		}
		line++;
	}
	return (0);
}
