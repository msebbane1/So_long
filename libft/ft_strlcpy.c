/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:39:09 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/26 12:11:12 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * strlcpy(dest,src,lenMax) doit copier le plus de caractères possible de 
 * src dans dest, la taille max dans dest est lenMax.
 * Contrairement à strncpy(dest,src,lgMax) elle doit garantir que 
 * le terminateur est toujours écrit dans dest[] (si src est trop longue, 
 * il sera à la position dest[lgMax-1], sinon dest sera une simple copie de src).
 * La fonction doit retourner la longueur de src.
 **/
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
	while (src[i] && i < size_max - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size_src);
}
