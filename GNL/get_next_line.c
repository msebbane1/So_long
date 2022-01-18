/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:28:13 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 13:53:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

#define BUFFER_SIZE 1

/**
 * Cet fonction permet de copier ma save(taille du buffer)dans une nouvelle
 * chaine qui contient toute la chaine sans le '\n' 
 * (tout ce quíl y a avant le '\n')
 **/
char	*copy_save(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

char	*copy_after_line(char *buffer)
{
	int		i;
	char	*line2;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line2 = malloc(sizeof(char) + (ft_strlen(buffer) - i + 1));
	if (!line2)
		return (NULL);
	ft_strlcpy(line2, buffer + i + 1, ft_strlen(buffer));
	free(buffer);
	return (line2);
}

char	*get_next_line(int fd)
{
	int				ret;
	int				i;
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	static char		*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	ret = 1;
	while (ft_strchr(save, '\n') == NULL && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buffer[ret] = '\0';
		save = ft_strjoin(save, buffer);
	}
	line = copy_save(save);
	save = copy_after_line(save);
	return (line);
}
