/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:18:27 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:28:07 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction permet de comparer le contenu de deux blocs de 
 * mémoire (s1 && s2) et size, permet de spécifier le nombre d'octets sur 
 * lequel comparer les deux blocs.
 * 
 * Elle renvoie un entier négatif, nul, ou positif, si s1 est respectivement 
 * inférieure, égale ou supérieure à s2.
 * 
 * Attention, contrairement à strcpy, aucun test sur une éventuelle valeur nulle 
 * n'est réalisé pour stopper la comparaison. Seule la taille du bloc sera 
 * considérée.
 **/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	j = 1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && j < n)
	{
		i++;
		j++;
	}
	return (str1[i] - str2[i]);
}
