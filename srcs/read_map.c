/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 14:25:32 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"


int	count_lines(char **argv)
{
	int		fd;
	int		lines;
	int		ret;
	char	c;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	lines = 1;
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, &c, 1);
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

char	**malloc_map(char **argv)
{
	char	**map;
	int		total_lines;

	total_lines = count_lines(argv);
	if (total_lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * total_lines + 2);
	if (!map)
		return (NULL);
	return (map);
}

char	**ft_read_map(char **argv)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	map = malloc_map(argv);
	i = 0;
	if (!map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd); //y = 0 x
	while (line)
	{
		//printf("%s", line);
		map[i++] = line;
		line = get_next_line(fd);
		//printf("%s", line);
	}
	//printf("%s", map[4]);
	//printf("%s", get_next_line(fd));
	close(fd);
	return (map);
}


/*
//conf->map[line] = get_next_line(fd);
	printf("%s", get_next_line(fd));
	while (get_next_line(fd))
	{
		//printf("%s", get_next_line(fd));
		conf->map[line] = get_next_line(fd);
		line++;
	}
*/