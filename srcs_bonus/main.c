/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/26 16:01:17 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
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

int	main(int argc, char **argv)
{
	t_conf	conf;

	if (argc > 2)
		error_msg("Error, too many arguments");
	else if (argc < 2)
		error_msg("Error, missing a file");
	else if (ft_strncmp(".ber", argv[1] + ft_strlen(argv[1]) - 4, 4))
		error_msg("Error, missing .ber");
	read_x_y(argv, &conf);
	ft_read_map(argv, &conf);
	ft_check_map(&conf);
	count_collectible(&conf);
	game_init(&conf);
	player_coord(&conf);
	mlx_hook(conf.win, 2, 1L << 0, key_hook, &conf);
	mlx_hook(conf.win, 17, 1L << 0, win_closed, &conf);
	mlx_loop(conf.mlx);
}

/*
----> mettre map.ber dans un tableau a 2 dimensions (ft_read_map) compter les caractere d'une ligne et compter les lignes (x, y) et malloc
----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"
----> la taille * 64 (taille de l'image)
----> Lire la map, lire chaque caracteres / afficher l'image (sprite) sur un chiffre
----> map.ber correspond a 0 = Background 1 = Mur C = collectible, E for map exit and P = player
----> Faire les msg d'erreur
----> faire la gestion d' erreur
----> Deplacer le player mlx_key_hook, prendre les coordoner du P
----> Connaitre la position de P du player
----> Regle du jeu collect toute les pieces pour exit // compter les pieces
----> supprimer avec mlx_destroy
----> gerer si il y a pas de P, lettres reourner une erreur
----> S pour enemies
*/