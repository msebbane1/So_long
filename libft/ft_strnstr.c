/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:53:19 by marvin            #+#    #+#             */
/*   Updated: 2021/10/28 13:12:57 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * La fonction recherche la première occurrence d'une sous-chaîne(little) 
 * dans la chaîne de caractères principale (big). Où pas plus de len caractères
 * sont recherchés. 
 * Les caractères qui apparaissent après un caractère "\0" ne sont pas cherché.
 * 
 * Si ma sous chaine est vide alors elle retourne toute la chaine.
 * EXEMPLE : si little(hello) trouve la 1ere lettre dans big(salut hello) 
 * alors il continue de lire hello de little sinon il remet a 0 hello
 **/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (str);
	while (str[j] && little[i] && j < len)
	{
		if (little[i] == str[j])
			i++;
		else
		{
			j = j - i;
			i = 0;
		}
		j++;
	}
	if (little[i] == '\0')
		return (str + j - i);
	return (0);
}
