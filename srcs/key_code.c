/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:38:56 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/31 10:44:46 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_down(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_y += 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	printf("Steps : %d\n", conf->player.counter);
	return (0);
}

int	key_left(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_x -= 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	printf("Steps : %d\n", conf->player.counter);
	return (0);
}

int	key_up(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_y -= 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	printf("Steps : %d\n", conf->player.counter);
	return (0);
}

int	key_right(t_conf *conf)
{
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = '0';
	conf->player.pos_x += 1;
	conf->map.ptr[conf->player.pos_y][conf->player.pos_x] = 'P';
	conf->player.counter++;
	printf("Steps : %d\n", conf->player.counter);
	return (0);
}
