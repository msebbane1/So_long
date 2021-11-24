/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:31:29 by msebbane          #+#    #+#             */
/*   Updated: 2021/10/28 13:04:22 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * Ajoute l’élément new à la fin de la liste.
 * (alst)L’adresse du pointeur vers le premier élément
 * de la liste.
 * (new)L’adresse du pointeur vers l’élément à rajouter
 * à la liste.
 **/
void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*n;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	n = ft_lstlast(*(alst));
	n->next = new;
}
