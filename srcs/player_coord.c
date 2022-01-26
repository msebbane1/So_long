/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_coord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:18:56 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 10:43:19 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_coord(t_conf *conf)
{
	int		y;
	int		x;
	int		end_line;
	int		end_char;

	y = 0;
	end_line = conf->map.size.y / 64;
	end_char = conf->map.size.x / 64;
	while (y < end_line)
	{
		x = 0;
		while (x <= end_char)
		{
			if (conf->map.ptr[y][x] == 'P')
			{
				conf->player.pos_x = x;
				conf->player.pos_y = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}
