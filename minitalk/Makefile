# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:54:02 by ivbatist          #+#    #+#              #
#    Updated: 2024/09/27 19:14:50 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I $(FT_PRINTF_DIR)/inc -I ../../42_Libft/libft/inc
CFLAGS = -Wall -Wextra -Werror -I inc
RM = rm -f
RMD = rm -rf

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRCDIR = src
OBJDIR = obj
FT_PRINTF_DIR = ../../42_ft_Printf/printf

################################################################################
# 							Files	Path	Variables 						   #
################################################################################

SRC_CLIENT = $(SRCDIR)/client.c
SRC_SERVER = $(SRCDIR)/server.c

OBJ_CLIENT = $(OBJDIR)/client.o
OBJ_SERVER = $(OBJDIR)/server.o

################################################################################
# 							Libft Variables 								   #
################################################################################

FT_PRINTF_REPO = git@github.com:pin3dev/42_ft_Printf.git

LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT = ../../42_Libft/libft/libft.a


################################################################################
# 							Manual	Targets		 							   #
################################################################################

all: $(FT_PRINTF_DIR) $(NAME_CLIENT) $(NAME_SERVER)

clean:
	$(RMD) $(OBJDIR)
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(RMD) ../../42_Libft
	@$(RMD) ../../42_ft_Printf

re: fclean all

################################################################################
# 						Auto Targets 				 						   #
################################################################################

$(FT_PRINTF_DIR):
	@if [ ! -d $(FT_PRINTF_DIR) ]; then \
		echo "Cloning ft_printf repository..."; \
		git clone $(FT_PRINTF_REPO) ../../42_ft_Printf; \
	fi
	@$(MAKE) -C $(FT_PRINTF_DIR) all

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ_CLIENT): $(SRC_CLIENT) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC_CLIENT) -o $(OBJ_CLIENT)

$(OBJ_SERVER): $(SRC_SERVER) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC_SERVER) -o $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFTPRINTF) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFTPRINTF) $(LIBFT) -o $(NAME_SERVER)

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
