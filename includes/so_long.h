/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:14:57 by msebbane          #+#    #+#             */
/*   Updated: 2021/12/23 13:47:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "get_next_line.h"
# include "struct.h"
# include "define.h"

char	*get_next_line(int fd);
int		ft_check_map(char *path);
//int		main(int argc, char **argv);
//int		main(int argc, char **argv);
char	**ft_read_map(char **argv);

#endif