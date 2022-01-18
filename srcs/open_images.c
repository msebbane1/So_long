/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:22:23 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/18 16:56:00 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	put_images(t_conf *conf, int line, int c)
{
	t_tex	size;
	
	if (conf->map[line][c] == '0')
		conf->img.img = mlx_xpm_file_to_image(conf->mlx, "./images/Sprite/Grass.xpm", &size.width, &size.height);
	mlx_put_image_to_window(conf->mlx, conf->win, conf->img.img, 64 * c, 64 * line);
	return (0);
}

void	open_images(t_conf	*conf)
{
	int		line;
	int		c;

	line = 0;
	while (line < conf->size.y / 64)
	{
		c = 0;
		while (c < conf->size.x / 64)
		{
			put_images(conf, line, c);
			c++;
		}
		line++;
	}
}
