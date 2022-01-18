/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:03:40 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 13:48:01 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	check_char(char c)
{
	if (c != '0' && c != '1'
		&& c != 'P' && c != 'E'
		&& c != 'C')
		return (1);
	return (0);
}

int	cmp_nbline(int fd)
{
	char	*str;
	int		nbline;

	nbline = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		nbline++;
		str = get_next_line(fd);
	}
	return (nbline);
}

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
}

int	open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

int	ft_check_map(char *path)
{
	char	*str;
	int		nbline;
	int		total;
	int		fd;
	
	fd = open_map(path);
	if (fd < 0)
		return (0);
	total = cmp_nbline(fd);
	nbline = 1;
	fd = open_map(path);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (check_line(str, nbline, total))
			return (1);
		str = get_next_line(fd);
		nbline++;
	}
	return (0);
}
