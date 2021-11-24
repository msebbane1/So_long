/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 23:22:27 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 11:28:52 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Cette fonction recherche la première occurrence du caractère(c)
 * dans la chaîne de caractères spécifiée(s). 
 * Elle doit retourner la chaine a partir de la 1ere occurence du caractere(c)
 * trouver dans la chaine.
 * 
 * Si elle ne trouve pas le caractere dans la chaine elle retourne NULL
 * (Ignore tous les caractères de str qui n'est pas egal au caractere(c)).
 * Des qu'il trouve le caractère il retourne la chaine + i(position de ch(3)).
 **/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = (char *)s;
	ch = (unsigned char)c;
	while (str[i] && str[i] != ch)
		i++;
	if (str[i] == ch)
	{
		return (str + i);
	}
	return (0);
}
