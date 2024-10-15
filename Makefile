# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:37:35 by anadal-g          #+#    #+#              #
#    Updated: 2024/10/15 19:06:43 by anadal-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = fractol

# SOURCE FILES
SRC_DIR = src/

SRC_FILES = main.c \
            fractol_init.c \
            fractol_render.c \
            fractol_utils.c \
            map_escale.c \
            events.c \
            ft_isdigit.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_DIR = objs/
OBJ_FILES = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# COMPILER
CC = gcc -g -O3 #-fsanitize=address
FLAGS = -Wall -Wextra -Werror
MLX = -L minilibx-linux -lmlx -lXext -lX11 -lm
INCLUDE = -I includes -I minilibx-linux
RM = rm -rf

# COLORS
RED = \033[91;1m
GREEN = \033[92;1m
YELLOW = \033[93;1m
BLUE = \033[94;1m
PINK = \033[95;1m
CLEAR = \033[0m

# MAKEFILE RULES

all: $(NAME)

# Solo compilar MinilibX si no está el archivo libmlx.a (o libmlx.so)
minilibx-linux/libmlx.a:
	@echo "$(YELLOW)Compiling MinilibX library$(CLEAR)"
	@make -sC minilibx-linux

$(NAME): minilibx-linux/libmlx.a $(OBJ_FILES)
	@echo "$(GREEN)Compiling the FRACTOL program.$(CLEAR)"
	$(CC) $(FLAGS) $(INCLUDE) $(OBJ_FILES) $(MLX) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	$(RM) $(OBJ_DIR)
	@echo "$(BLUE)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@echo "$(BLUE)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME) minilibx-linux/libmlx.a
	@echo "$(BLUE)Object files and binary removed correctly\n$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re

