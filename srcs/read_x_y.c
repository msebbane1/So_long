/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:07:34 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/27 12:18:48 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines_x(int fd)
{
	int		lines;
	int		ret;
	char	c;

	lines = 0;
	ret = 1;
	while (ret == 1 && c != '\n')
	{
		ret = read(fd, &c, 1);
		lines++;
	}
	return (lines - 1);
}

int	count_lines_y(int fd)
{
	int		lines;
	int		ret;
	char	c;
	int		i;

	lines = 1;
	ret = 1;
	i = 0;
	while (ret == 1)
	{
		ret = read(fd, &c, 1);
		if (c == '\n')
			lines++;
	}
	return (lines + 1);
}


int	read_x_y(char **argv, t_conf *conf)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("Error, invalid file");
	conf->map.size.x = (count_lines_x(fd) * 64);
	conf->map.size.y = (count_lines_y(fd) * 64);
	close(fd);
	return (0);
}
