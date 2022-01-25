/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:22:23 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/25 16:05:42 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_win(t_conf *conf)
{
	if (count_collectible(conf) == 0)
		mlx_string_put(conf->mlx, conf->win, 50, 50, 0x00000000, "YOU WIN !");
}

int	put_images(t_conf conf, int line, int c, int keycode)
{
	if (conf.map.ptr[line][c] == '0')
		img_background(&conf);
	else if (conf.map.ptr[line][c] == '1')
		img_walls(&conf);
	else if (conf.map.ptr[line][c] == 'E')
		img_exit(&conf);
	else if (conf.map.ptr[line][c] == 'C')
		img_collectible(&conf);
	else if (conf.map.ptr[line][c] == 'P')
		img_player(&conf, keycode);
	img_win(&conf);
	mlx_put_image_to_window(conf.mlx, conf.win, conf.img.img,
		16 * c, 16 * line);
	mlx_destroy_image(conf.mlx, conf.img.img);
	return (0);
}

int	open_images(t_conf conf, int keycode)
{
	int		line;
	int		c;

	line = 0;
	while (line < conf.map.size.y / 16)
	{
		c = 0;
		while (c < conf.map.size.x / 16)
		{
			put_images(conf, line, c, keycode);
			c++;
		}
		line++;
	}
	return (0);
}
