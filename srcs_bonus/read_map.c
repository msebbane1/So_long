/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 17:15:59 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

//----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"
// ---> x = caracteres et y = lignes

int	malloc_map(t_conf *conf)
{
	conf->map.ptr = malloc((conf->map.size.y + 1) * sizeof(char *));
	if (!conf->map.ptr)
		error_msg("Error, wrong file");
	return (0);
}

int	ft_read_map(char **argv, t_conf *conf)
{
	int		fd;
	int		line;

	malloc_map(conf);
	line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_msg("Error, file invalid");
	while (get_next_line(fd, &conf->map.ptr[line]))
		line++;
	close (fd);
	return (0);
}
