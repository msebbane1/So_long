/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:51:15 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/28 11:03:10 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Applique la fonction ’f’ à chaque caractère de la chaine de caractères 
 * passée en argument pour créer une nouvelle chaine de 
 * caractères (avec malloc)
 * résultant des applications successives de ’f’. 
 **/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	unsigned int	size_s;

	if (!s)
		return (NULL);
	i = 0;
	size_s = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * size_s + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
