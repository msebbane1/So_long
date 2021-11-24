/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:59:28 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/27 17:57:44 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Supprime et libère la mémoire de l’élément passé en
 * paramètre, et de tous les élements qui suivent, à
 * l’aide de del et de free(3)
 * Enfin, le pointeur initial doit être mis à NULL.
 **/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*alst;

	alst = *lst;
	while (alst)
	{
		ft_lstdelone(alst, del);
		alst = alst->next;
	}
	*lst = NULL;
}
