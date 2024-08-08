# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:54:02 by ivbatist          #+#    #+#              #
#    Updated: 2023/04/06 22:54:04 by ivbatist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

NAMELIBFT = libft/libft.a

HDRS = minitalk.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_C = client.c
SRC_S = server.c

all: $(NAME)

$(NAMELIBFT):
	make all -C ./libft

$(NAME): $(NAMELIBFT)
	$(CC) $(CFLAGS) $(SRC_C) $(NAMELIBFT) -o client
	$(CC) $(CFLAGS) $(SRC_S) $(NAMELIBFT) -o server


clean:
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf client server

re: fclean all

