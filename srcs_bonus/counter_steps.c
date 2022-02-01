/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:08:35 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/31 16:24:36 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	counter_steps(t_conf *conf)
{
	conf->player.count = ft_itoa(conf->player.counter);
	mlx_string_put(conf->mlx, conf->win, 4, 15, 0x00000000, conf->player.count);
	mlx_string_put(conf->mlx, conf->win, 0, 0, 0x00000000, "steps : ");
	free(conf->player.count);
}
