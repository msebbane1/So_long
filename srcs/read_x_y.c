/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_x_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:07:34 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/20 11:12:48 by msebbane         ###   ########.fr       */
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

	lines = 1;
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, &c, 1); // lis le fichier lettre par lettre
		if (c == '\n') // jusqu'a la 2eme ligne 
			lines++; // compte toute les lignes
	}
	return (lines + 1); // lines = au nombre total de mes lignes
}


int	read_x_y(char **argv, t_conf *conf)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	conf->map.size.x = (count_lines_x(fd) * 16);
	conf->map.size.y = (count_lines_y(fd) * 16);
	close(fd);
	return (0);
}
