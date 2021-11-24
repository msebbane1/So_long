/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:25:12 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:28:14 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction permet de copier un bloc de mémoire spécifié(src), 
 * et dont la taille est spécifiée(n), dans un nouvel emplacement(dest).
 * En cas de chevauchement des deux blocs de mémoire (source et destination)
 * le comportement de la fonction memcpy n'est pas garanti. Dans ce cas,
 * il faut utiliser la fonction memmove.
 * Attention, contrairement à strcpy, aucun test sur une éventuelle valeur nulle
 * n'est réalisé pour stopper la copie. Seule la taille du bloc sera considérée.
 **/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newcopy;
	unsigned char	*original;

	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	newcopy = (unsigned char *)dest;
	original = (unsigned char *)src;
	while (i < n)
	{
		newcopy[i] = original[i];
		i++;
	}
	return (dest);
}
