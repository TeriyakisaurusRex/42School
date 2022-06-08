# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthiele <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 13:11:16 by jthiele           #+#    #+#              #
#    Updated: 2022/06/08 15:02:05 by jthiele          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/
PRINTF_A = ft_printf/libftprintf.a
CC = gcc
RM = rm -f

all:
	make -C $(PRINTF)
	make server
	make client

server:
	$(CC) $(CFLAGS) srcs/server.c srcs/utils.c $(PRINTF_A) -o server
	
client:
	$(CC) $(CFLAGS) srcs/client.c srcs/utils.c $(PRINTF_A) -o client

clean:
	make clean -C $(PRINTF)

fclean: clean
	$(RM) server client $(PRINTF_A)
	
re: fclean all

.PHONY: all clean fclean re
