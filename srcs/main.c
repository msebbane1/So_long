/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:38:43 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 14:20:59 by msebbane         ###   ########.fr       */
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

//int malloc_map



/*int	ft_read(char **argv, t_conf *conf)
{
	int	fd;
	int	line;

	fd = open(argv[1], O_RDONLY);
	line = 0;
	//conf->map[line] = get_next_line(fd);
	printf("%s", get_next_line(fd));
	while (get_next_line(fd))
	{
		//printf("%s", get_next_line(fd));
		conf->map[line] = get_next_line(fd);
		line++;
	}
	close(fd);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_conf	conf;
	t_tex	size;
	//t_vars	vars;

	if (ft_check_map("maps/map_2.ber") || argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	ft_read_map(argv);
	conf.mlx = mlx_init();
		conf.win = mlx_new_window(conf.mlx, 500, 500, "GAME");
		conf.img.img = mlx_xpm_file_to_image(conf.mlx, "./images/Sprite/Grass.xpm", &size.width, &size.height);
		mlx_put_image_to_window(conf.mlx, conf.win, conf.img.img, 0, 0);
	//mlx_key_hook(mlx_win, key_hook, &vars);
		mlx_loop(conf.mlx);

}

/*
----> mettre map.ber dans un tableau a 2 dimensions
----> lire la map avec GNL et calculer la taille de ma map x et y jusqu'a un "\n"
----> la taille * 64 (taille de l'mage)
----> map.ber correspond a 0 = Background 1 = Mur C = collectible, E for map exit and P = player
----> Deplacer le player mlx_key_hook
----> supprimer avec mlx_destroy
*/