/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/21 16:59:39 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int	main(int argc, char **argv)
{
	t_conf	conf;

	if (argc > 2)
		error_msg("Error, too many arguments");
	else if (argc < 2)
		error_msg("Error, missing a file");
	read_x_y(argv, &conf);
	ft_read_map(argv, &conf);
	ft_check_map(&conf);
	game_init(&conf);
	player_coord(&conf);
	mlx_hook(conf.win, 2, 1L << 0, key_hook, &conf);
	//mlx_string_put(conf.mlx, conf.win, 50, 50, 0x00000000, "YOU WIN");
	//end_game(&conf);
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
*/