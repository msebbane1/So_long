/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:28:04 by msebbane          #+#    #+#             */
/*   Updated: 2021/11/24 16:10:53 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size_max)
{
	size_t	i;
	size_t	size_src;

	i = 0;
	size_src = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size_max == 0)
		return (size_src);
	while (src[i] && i < (size_max - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}

char	*ft_strjoin(char *str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	tmp = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buf)) + 1));
	if (!tmp)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i] != '\0')
			tmp[i] = str[i];
	j = 0;
	while (buf[j] != '\0')
		tmp[i++] = buf[j++];
	tmp[ft_strlen(str) + ft_strlen(buf)] = '\0';
	free (str);
	return (tmp);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
