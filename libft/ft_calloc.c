/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:59:27 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:27:13 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction alloue un bloc de mémoire en initialisant tous ces 
 * octets à la valeur 0. 
 * Bien que relativement proche de la fonction malloc, deux aspects les 
 * différencient :
 *  - L'initialisation : calloc met tous les octets du bloc à la valeur 0 
 *    alors que malloc ne modifie pas la zone de mémoire.
 *  - Les paramètres d'appels : calloc requière deux paramètres 
 *    (le nombre d'éléments consécutifs à allouer et la taille d'un élément)
 *    alors que malloc attend la taille totale du bloc à allouer.
 **/
void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	total;

	total = count * size;
	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (total));
	return (str);
}
