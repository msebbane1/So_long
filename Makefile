# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by marvin            #+#    #+#              #
#    Updated: 2022/01/18 15:24:25 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address
NAME= solong
SRCS =  srcs/main.c srcs/parsing.c GNL/get_next_line.c \
GNL/get_next_line_utils.c srcs/read_map.c srcs/game_init.c srcs/open_images.c
OBJS = ${SRCS:.c=.o}
LFLAGS = -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ${LFLAGS} ./libft/libft.a -o ${NAME}

fclean: clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}

clean:
	${MAKE} clean -C ./libft
	rm -f ${NAME} ${OBJS}

re: fclean clean all