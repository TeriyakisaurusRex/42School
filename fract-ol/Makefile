# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthiele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:20:49 by jthiele           #+#    #+#              #
#    Updated: 2022/06/29 13:54:23 by jthiele          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OS = $(shell uname)

# directories
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj

# src
SRC 	=	main.c \
			imagewindow.c \
			key_hooks.c \
			mouse_hooks.c \
			plot_fractal.c \
			colour.c 

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
MLX		= ./mlx/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# build instructions
all: obj $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -lm -o $(NAME)

clean:
	rm $(NAME)
	rm -rf $(OBJDIR)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re fractol
