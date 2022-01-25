/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:41:28 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/25 15:30:39 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	error_msg(char *msg)
{
	printf("\033[0;31m" "%s\n" "\033[0m", msg);
	exit (0);
	return (0);
}
