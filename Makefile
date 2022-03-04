# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by marvin            #+#    #+#              #
#    Updated: 2022/02/01 11:37:30 by msebbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

FLAGSMLX = -lmlx -framework OpenGL -framework AppKit -lz

SRCS = GNL/get_next_line_utils.c \
	   GNL/get_next_line.c \
	   	srcs/main.c srcs/open_images.c\
		srcs/read_map.c srcs/game_init.c \
		srcs/read_x_y.c srcs/check_map.c srcs/error_msg.c \
		srcs/key_hook.c srcs/player_coord.c \
		srcs/move_player.c srcs/lib.c\
		srcs/count_collectible.c srcs/put_images.c \
		srcs/key_code.c

SRCS_BONUS = GNL/get_next_line_utils.c \
	   	GNL/get_next_line.c \
	   	srcs_bonus/main_bonus.c srcs_bonus/open_images_bonus.c\
		srcs_bonus/read_map_bonus.c srcs_bonus/game_init_bonus.c \
		srcs_bonus/read_x_y_bonus.c srcs_bonus/check_map_bonus.c \
		srcs_bonus/error_msg_bonus.c srcs_bonus/counter_steps_bonus.c\
		srcs_bonus/key_hook_bonus.c srcs_bonus/player_coord_bonus.c \
		srcs_bonus/move_player_bonus.c srcs_bonus/lib_bonus.c\
		srcs_bonus/count_collectible_bonus.c srcs_bonus/put_images_bonus.c \
		srcs_bonus/key_code_bonus.c \

RM = rm -f

ifndef BONUS
SOURCES	= ./srcs
OBJS	= $(SRCS:.c=.o)
else
SOURCES	= ./srcs_bonus
OBJS	= $(SRCS_BONUS:.c=.o)
endif

all: ${NAME}

bonus:
	@echo "\033[1;32m""Compilation de ${NAME}..."
	@make BONUS=1 ${NAME}

${NAME}: ${OBJS}
		@echo "\033[1;36m""Compilation de ${NAME}..."
		$(CC) $(OBJS) $(FLAGSMLX) $(CFLAGS) -o $(NAME)

${OBJECTS}/%.o: ${SOURCES}/%.c
	@echo "Compilation de ${notdir $<}."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@echo "\033[1;32m""Supression des fichiers binaires (.o)..."
		${RM} ${OBJS} $(SRCS_BONUS:.c=.o)

fclean: clean
		@echo "\033[1;32m""Supression des executables et librairies..."
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all

.PHONY: all bonus clean fclean re