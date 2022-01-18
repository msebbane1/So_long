/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:22:23 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/18 12:08:30 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_images(t_conf	*conf)
{
	t_tex	size;

	conf->img.img = mlx_xpm_file_to_image(conf->mlx, "./images/Sprite/Grass.xpm", &size.width, &size.height);
}