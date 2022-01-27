/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 10:36:24 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 10:47:17 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_collectible(t_conf *conf)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	conf->player.coin = 0;
	while (y < conf->map.size.y / 64)
	{
		x = 0;
		while (x < conf->map.size.x / 64)
		{
			if (conf->map.ptr[y][x] == 'C')
				conf->player.coin++;
			x++;
		}
		y++;
	}
	return (conf->player.coin);
}
