# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by marvin            #+#    #+#              #
#    Updated: 2022/01/25 15:40:32 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = GNL/get_next_line_utils.c \
	   GNL/get_next_line.c \
	   srcs/main.c srcs/open_images.c\
		srcs/read_map.c srcs/game_init.c \
		srcs/read_x_y.c srcs/check_map.c srcs/error_msg.c \
		srcs/key_hook.c srcs/player_coord.c \
		srcs/move_player.c srcs/counter_steps.c \
		srcs/count_collectible.c srcs/put_images.c \
		srcs/key_code.c

OBJS = ${SRCS:.c=.o}

NAME = solong

CC = cc
 
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		$(CC) $(OBJS) $(FLAGSMLX) $(CFLAGS) -o $(NAME)

%o:	%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all

.PHONY: all clean fclean re