/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:03:40 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/31 13:45:43 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_double(t_conf *conf)
{
	int		y;
	int		x;
	int		c;
	int		end_line;
	int		end_char;

	c = 0;
	y = 0;
	end_line = conf->map.size.y / 64;
	end_char = conf->map.size.x / 64;
	count_collectible(conf);
	while (y < end_line)
	{
		x = 0;
		while (conf->map.ptr[y][x] != '\n' && x < end_char)
		{
			if (conf->map.ptr[y][x] == 'E' || conf->map.ptr[y][x] == 'P')
				c++;
			x++;
		}
		y++;
	}
	if (c != 2 || conf->player.coin == 0)
		return (1);
	return (0);
}

int	check_char(t_conf *conf)
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
		while (conf->map.ptr[y][x] != '\n' && x < end_char)
		{
			if (conf->map.ptr[y][x] != '0' && conf->map.ptr[y][x] != '1'
				&& conf->map.ptr[y][x] != 'P' && conf->map.ptr[y][x] != 'E'
				&& conf->map.ptr[y][x] != 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_rectangular(t_conf *conf)
{
	int	end_line_x;
	int	end_line_y;
	int	y;

	y = 0;
	end_line_x = conf->map.size.x / 64;
	end_line_y = conf->map.size.y / 64;
	while (conf->map.ptr[y])
	{
		if (y < end_line_y - 1)
		{
			if (ft_strlen(conf->map.ptr[y]) != end_line_x + 1)
				return (1);
		}
		else
			if (ft_strlen(conf->map.ptr[y]) != end_line_x)
				return (1);
		y++;
	}
	return (0);
}

int	check_walls(t_conf *conf)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while ((conf->map.ptr[y][x]) != '\0' && (conf->map.ptr[y][x]) != '\n')
	{
		if (conf->map.ptr[y][x] != '1')
			return (1);
		if (conf->map.ptr[conf->map.size.y / 64 - 1][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < conf->map.size.y / 64)
	{
		if (conf->map.ptr[y][0] != '1')
			return (1);
		else if (conf->map.ptr[y][conf->map.size.x / 64 - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_map(t_conf *conf)
{
	if (check_rectangular(conf))
		error_msg("Error, map must be rectangular");
	else if (check_walls(conf))
		error_msg("Error, invalid walls");
	else if (check_char(conf))
		error_msg("Error, invalid characters");
	else if (check_double(conf))
		error_msg("Error, too much player/exit or missing key");
	return (0);
}
