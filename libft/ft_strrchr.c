/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:02:01 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:29:57 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction recherche la première occurrence du caractère(c)
 * dans la chaîne de caractères spécifiée(s).
 * 
 * La différence entre strchr et strrchr est le fait que strchr renvoi 
 * la position de la première occurrence du caractère(c) alors que strrchr 
 * renvoi la dernière occurrence.
 **/
char	*ft_strrchr(const char *s, int c)
{
	int				size_s;
	char			*str;
	unsigned char	ch;

	size_s = ft_strlen(s);
	str = (char *)s;
	ch = (unsigned char)c;
	while (size_s > 0)
	{
		if (str[size_s] == ch)
		{
			return (str + size_s);
		}
		size_s--;
	}
	if (str[size_s] == ch)
		return (str);
	return (0);
}
