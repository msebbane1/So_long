/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:47:47 by marvin            #+#    #+#             */
/*   Updated: 2021/10/26 14:02:30 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * La fonction strncmp compare les deux chaînes s1 et s2 et ne compare que 
 * les n (au plus) premiers caractères de s1 et s2.
 * 
 * Elle renvoie un entier négatif, nul, ou positif, si s1 est respectivement 
 * inférieure, égale ou supérieure à s2.
 **/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
	while (str1[i] && str2[i] && str1[i] == str2[i] && j < n)
	{
		i++;
		j++;
	}
	return (str1[i] - str2[i]);
}
