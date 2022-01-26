/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:08:35 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 13:32:50 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_len_nb(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len_nb(nb);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[len--] = '\0';
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

void	counter_steps(t_conf *conf)
{
	conf->player.count = ft_itoa(conf->player.counter);
	mlx_string_put(conf->mlx, conf->win, 4, 15, 0x00000000, conf->player.count);
	mlx_string_put(conf->mlx, conf->win, 0, 0, 0x00000000, "steps : ");
	free(conf->player.count);
}
