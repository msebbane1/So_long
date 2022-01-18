/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/18 16:33:47 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"


int count_lines_x(char **argv)
{
	int		fd;
	int		lines;
	int		ret;
	char	c;
		
	lines = 0;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (-1);
	ret = 1;
	while (ret == 1 && c != '\n')
	{
		ret = read(fd, &c, 1);
		lines++;
	}
	return (lines);
}

int	count_lines_y(char **argv)
{
	int		fd;
	int		lines;
	int		ret;
	char	c;

	fd = open(argv[1], O_RDONLY);
	if (!fd) // si il ne s'ouvre pas
		return (-1);
	lines = 1;
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, &c, 1); // lis le fichier lettre par lettre
		if (c == '\n') // jusqu'a la 2eme ligne 
			lines++; // compte toute les lignes
	}
	close(fd);
	return (lines); // lines = au nombre total de mes lignes
}

char	**malloc_map(char **argv, t_conf *conf)
{
	//char	**map;
	//int		total_lines;

	conf->size.y = count_lines_y(argv);
	conf->size.x = count_lines_x(argv);
	//printf("%d", conf->size.y);
	if (conf->size.y <= 0)
		return (NULL);
	conf->map = malloc(sizeof(char *) * (conf->size.y + 1));
	if (!conf->map)
		return (NULL);
	return (0);
}

char	**ft_read_map(char **argv, t_conf *conf)
{
	int		fd;
	//char	**map; //map en 2D lire un fichier
	char	*line;
	int		i;

	conf->map = malloc_map(argv, conf);
	i = 0;
	if (!conf->map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd); //y = 0 x
	while (line)
	{
		//printf("%s", line);
		conf->map[i++] = line;
		line = get_next_line(fd);
		//printf("%s", line);
	}
	//printf("%s", map[4]);
	//printf("%s", get_next_line(fd));
	close(fd);
	return (0);
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