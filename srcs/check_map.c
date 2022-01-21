/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:03:40 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 12:10:20 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_char(t_conf *conf)
{
	int		y;
	int		x;
	int		end_line;
	int		end_char;

	y = 0;
	end_line = conf->map.size.y / 16;
	end_char = conf->map.size.x / 16;
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
		else if (conf->map.ptr[conf->map.size.y / 16 - 1][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (y < conf->map.size.y / 16)
	{
		if (conf->map.ptr[y][0] != '1')
			return (1);
		else if (conf->map.ptr[y][conf->map.size.x / 16 - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_map(t_conf *conf)
{
	if (check_walls(conf))
		error_msg("error invalid walls");
	else if (check_char(conf))
		error_msg("error invalid characters");
	return (0);
}



/*
int	ft_check_map(char **argv, t_conf *conf)
{
	char	*str;
	int		line;
	int		total;
	int		fd;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	total = cmp_nbline(fd, conf);
	line = 1;
	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd, &conf->map.ptr[line]);
	if (check_line(str, line, total))
			error_msg("error, map no valid");
	//while (str != NULL)
	//{
		//if (check_line(str, line, total))
			error_msg("error, map no valid");
		//str = get_next_line(fd, &conf->map.ptr[line]);
		//line++;
	//}
	return (0);
}*/

/*
int	check_line(char *str, int nbline, int total)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (1);
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (nbline == 1 && str[i] != '1')
			return (1);
		else if (nbline == total && str[i] != '1')
			return (1);
		else if (check_char(str[i]))
			return (1);
		i++;
	}
	if (str[i - 1] != '1')
		return (1);
	return (0);
}*/

/*
int	ft_check_map(char **argv, t_conf *conf)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	count_lines_y(fd);
	//read_x_y(argv, &conf);
	
	
	
	//ft_read_map(argv, &conf);
	
	
}*/

/*
int	cmp_nbline(int fd, t_conf *conf)
{
	char	*str;
	int		line;

	line = 0;
	str = get_next_line(fd, &conf->map.ptr[line]);
	while (str != NULL)
	{
		line++;
		str = get_next_line(fd, &conf->map.ptr[line]);
	}
	//printf("%d", line);
	return (line);
}
*/
