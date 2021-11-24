/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:21:19 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/28 11:28:20 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction permet de copier un bloc de mémoire spécifié(src), 
 * et dont la taille est spécifiée(n), dans un nouvel emplacement(dest).
 * 
 * Les deux zones peuvent se chevaucher : la copie se passe comme 
 * si les octets 
 * de src étaient d'abord copiés dans une zone temporaire qui 
 * ne chevauche ni src 
 * ni dest, et les octets sont ensuite copiés de la zone temporaire vers dest.
 * 
 * Attention, contrairement à strcpy, aucun test sur une éventuelle valeur 
 * nulle
 * n'est réalisé pour stopper la copie. Seule la taille du bloc sera 
 * considérée.
 **/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newcopy;
	unsigned char	*original;

	i = 0;
	newcopy = (unsigned char *)dest;
	original = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (newcopy > original)
	{
		while (n > 0)
		{
			n--;
			newcopy[n] = original[n];
		}
	}
	else
		ft_memcpy(newcopy, original, n);
	return (newcopy);
}
