/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:10:48 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/28 11:29:17 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * La fonction concatène les chaînes dst et src, et place le résultat dans
 * la chaîne dst. Contrairement à la fonction strcat, strlcat garantie que 
 * la longueur totale de la chaîne résultat sera comprise entre la longueur 
 * initiale de dst et size. Le zéro de fin de chaîne est compatibilisé.
 * Elle retourne la longueur totale de la destination (sizedst + sizesrc).
 * Mais la destination ne depassera pas la len en parametre.
 *  
 * Cette fonction sert principalement à éviter les dépassement de taille 
 * du tableau de caractères.
 * 
 * EXEMPLE --------------> ft_strlcat(dest, src, 7)
 * dest = 1234 --- src = ABCD --- result = 1234AB
 * Ici elle concatene dest(4)+(2 + 1 ('\0'))src
 **/
size_t	ft_strlcat(char *dst, const char *src, size_t len_dst)
{
	size_t	i;
	size_t	j;
	size_t	size_src;
	size_t	size_dst;
	size_t	nb;

	i = 0;
	j = 0;
	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	nb = len_dst - size_dst - 1;
	if (len_dst <= size_dst)
		return (size_src + len_dst);
	while (dst[i])
		i++;
	while (j < nb && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (size_src + size_dst);
}
