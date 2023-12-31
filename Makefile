# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anadal-g <anadal-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:37:35 by anadal-g          #+#    #+#              #
#    Updated: 2024/01/02 12:41:33 by anadal-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SOURCES = \
	fractol_init.c \
	fractol_render.c \
	fractol_utils.c \
	map_escale.c \
	main.c \
	events.c \
	ft_isdigit.c \

OBJS = $(SOURCES:%.c=%.o)
CC = gcc -g -O3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJS)
#	@make -sC mlx
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	
clean:
	rm -f $(OBJS) 

fclean: clean
#	@make clean -sC mlx
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re  