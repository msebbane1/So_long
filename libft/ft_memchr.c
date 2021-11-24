/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:37:28 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:28:01 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Recherche la première occurence d'une valeur typée int(c), mais interprétée 
 * en tant que char, dans un bloc de mémoire. Comme on traite un bloc de mémoire 
 * et non pas une chaîne de caractères AZT, nous devons aussi 
 * spécifier à la fonction la taille du bloc de mémoire dans lequel réaliser 
 * la recherche.
 **/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	ch;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (str[i] && str[i] != ch)
		i++;
	while (i < n)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (0);
}
