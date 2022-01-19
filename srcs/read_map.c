/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 09:53:33 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/19 17:06:02 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"
// ---> x = caracteres et y = lignes

/*
int	count_lines_x(char **argv)
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
	close(fd);
	return (lines - 1);
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
}*/


int	malloc_map(t_conf *conf)
{
	//int		total_lines;

	//printf("%d", conf->size.x);
	//total_lines = count_lines_y(argv);
	//if (conf->map.size.y <= 0)
		//return (0);
	//conf->map.ptr = malloc(sizeof(char *) * total_lines + 1);
	conf->map.ptr = malloc((conf->map.size.y + 1) * sizeof(char *));
	if (!conf->map.ptr)
		return (0);
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
		return (0);
	while (get_next_line(fd, &conf->map.ptr[line]))
		line++;
	close (fd);
	return (0);
}

/*int	ft_read_map(char **argv, t_conf *conf)
{
	int		fd;
	char	*line;
	int		i;

	malloc_map(conf);
	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd); //y = 0 x
	while (line)
	{
		conf->map.ptr[i] = line;
		//printf("%s", conf->map.ptr[i]);
		i++;
		line = get_next_line(fd);
		//printf("%s", line);
	}
	printf("%s", conf->map.ptr[i]);
	//printf("%s", map[4]);
	//printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}*/