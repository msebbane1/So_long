/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2022/02/01 10:45:24 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	malloc_map(t_conf *conf)
{
	conf->map.ptr = malloc((conf->map.size.y) * sizeof(char *));
	if (!conf->map.ptr)
		error_msg("Error\nWrong map");
	return (0);
}

int	ft_read_map(char **argv, t_conf *conf)
{
	int		fd;
	int		fd2;
	int		line;

	malloc_map(conf);
	line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("Error\nFile invalid");
	fd2 = open(argv[1], O_DIRECTORY);
	if (fd2 != -1)
		error_msg("Error\nFile invalid");
	conf->map.ptr[line] = NULL;
	while (get_next_line(fd, &conf->map.ptr[line]))
	{
		line++;
	}
	conf->map.size.y = line * 64;
	close (fd);
	return (0);
}
