# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:58:01 by aneekhra          #+#    #+#              #
#    Updated: 2024/05/17 19:35:56 by aneekhra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC	= so_long.c game_window.c exit.c read_map.c error.c check.c \
		player.c move.c

SRC_BONUS = so_long_bonus.c bonus/game_window.c bonus/exit.c bonus/read_map.c bonus/error.c \
			bonus/check.c bonus/player.c bonus/move.c bonus/frame.c

HEADER = so_long.h so_long_bonus.h

LIBFTFOLDER = Libft

LIBFT = $(LIBFTFOLDER)/libft.a

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = ${SRC_BONUS:%.c=%.o}

RM = rm -f

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME) -I/usr/include -Imlx -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
		@echo "Compilation complete. Run './$(NAME)'  'maps/your_map_name' to execute the program.";

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
		@$(CC) $(CFLAGS) $(SRC_BONUS) $(LIBFT) -o $(NAME_BONUS) -I/usr/include -Imlx -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
		@echo "Compilation complete. Run './$(NAME_BONUS)'  'maps/your_map_name' to execute the program.";

$(LIBFT):
		@make -C $(LIBFTFOLDER) --silent
		clear

clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJ_BONUS)
		@make fclean -C $(LIBFTFOLDER) --silent
		

fclean: clean
		@$(RM) $(NAME) $(LIBFT) $(NAME_BONUS)
		@$(RM) $(FIRST_MAKE_FLAG)

re: fclean all

.PHONY: all bonus library clean fclean re
