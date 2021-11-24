/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 11:09:25 by marvin            #+#    #+#             */
/*   Updated: 2021/10/26 14:47:19 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * La fonction strdup renvoie un pointeur sur une nouvelle chaîne de 
 * caractères(dest) qui est dupliquée depuis s. La mémoire occupée par 
 * cette nouvelle chaîne est obtenue en appelant malloc(3).
 **/
char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*dest;

	i = 0;
	size = ft_strlen(s);
	dest = (char *) malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
