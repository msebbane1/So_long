/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/01/18 15:36:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_hook(int keycode, t_vars vars)
{
	void	*img;
	int		img_width;
	int		img_height;

	img_width = 600;
	img_height = 450;
	if (keycode == W)
	{
		img = mlx_xpm_file_to_image(vars.mlx, "./images/george.xpm", &img_width, &img_height);
		mlx_put_image_to_window(vars.mlx, vars.win, img, 0, 0);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	t_conf	conf;
	//t_tex	size;
	//t_vars	vars;

	if (ft_check_map("maps/map_2.ber") || argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	ft_read_map(argv, &conf);
	game_init(&conf);
	 //Lire ma map avec argv
	//printf("%d", conf.size.x);
	//conf.mlx = mlx_init();
	//conf.win = mlx_new_window(conf.mlx, conf.size.x *64, conf.size.y *64, "GAME");
	//conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/Grass.xpm", &size.width, &size.height);
	//mlx_put_image_to_window(conf.mlx, conf.win, conf.img.img, 0, 0);
	//mlx_key_hook(mlx_win, key_hook, &vars);
	mlx_loop(conf.mlx);

}

/*
----> mettre map.ber dans un tableau a 2 dimensions (ft_read_map) compter les caractere d'une ligne et compter les lignes (x, y) et malloc
----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"
----> la taille * 64 (taille de l'image)
----> Lire la map, lire chaque caracteres / afficher l'image (sprite) sur un chiffre
----> map.ber correspond a 0 = Background 1 = Mur C = collectible, E for map exit and P = player
----> Deplacer le player mlx_key_hook
----> supprimer avec mlx_destroy
*/