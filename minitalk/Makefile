# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pin3dev <pinedev@outlook.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 22:54:02 by ivbatist          #+#    #+#              #
#    Updated: 2024/10/25 00:47:24 by pin3dev          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
RESET=\033[0m
BKGRAY=\033[47;90m
BKGRAYGREEN=\033[1;92m
BKGRAYRED=\033[1;91m

################################################################################
# 									Executable	 	 						   #
################################################################################

NAME_CLIENT = client
NAME_SERVER = server

################################################################################
# 							Dir	Path	Variables 							   #
################################################################################

SRCDIR = src
OBJDIR = obj

################################################################################
# 						Compiler and Flags	Variables						   #
################################################################################

CC = cc
CFLAGS = -Wall -Wextra -Werror -I inc -I $(FT_PRINTF_DIR)/inc -I $(LIBFT_DIR)/inc
RM = rm -f
RMD = rm -rf

################################################################################
# 							Libft&Printf Variables 							   #
################################################################################

FT_PRINTF_REPO = git@github.com:pin3dev/42_ft_Printf.git
FT_PRINTF_DIR = ../../42_ft_Printf/printf
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ../../42_Libft/libft
LIBFT = $(LIBFT_DIR)/libft.a

################################################################################
# 							Files	Path	Variables 						   #
################################################################################

SRC_CLIENT = $(SRCDIR)/client.c
SRC_SERVER = $(SRCDIR)/server.c

OBJ_CLIENT = $(OBJDIR)/client.o
OBJ_SERVER = $(OBJDIR)/server.o

################################################################################
# 							Manual	Targets		 							   #
################################################################################

all: $(FT_PRINTF_DIR) $(NAME_CLIENT) $(NAME_SERVER)

clean:
	@if [ -d "$(OBJDIR)" ]; then $(RMD) $(OBJDIR); fi
	@echo "${BKGRAY}Minitalk:${BKGRAYRED}- Obj${RESET}"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "${BKGRAY}Minitalk: ${BKGRAYRED}- Exec${RESET}"

re: fclean all

################################################################################
# 							Dependencies Targets							   #
################################################################################

$(LIBFT):
	@if [ ! -d ../../42_Libft ]; then \
		git clone $(LIBFT_REPO) ../../42_Libft > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}Libft:${RESET} "; 
	@$(MAKE) -C $(LIBFT_DIR) all
	
$(LIBFTPRINTF):
	@if [ ! -d $(FT_PRINTF_DIR) ]; then \
		git clone $(FT_PRINTF_REPO) ../../42_ft_Printf  > /dev/null 2>&1; \
	fi
	@printf "${BKGRAY}Printf:${RESET} "; 
	@$(MAKE) -C $(FT_PRINTF_DIR) all

################################################################################
# 						Auto Targets 				 						   #
################################################################################

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ_CLIENT): $(SRC_CLIENT) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC_CLIENT) -o $(OBJ_CLIENT)

$(OBJ_SERVER): $(SRC_SERVER) | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $(SRC_SERVER) -o $(OBJ_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFTPRINTF) $(LIBFT) -o $(NAME_CLIENT) & \
	./gui_load.sh "Minitalk_Client"
	@wait

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFTPRINTF) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFTPRINTF) $(LIBFT) -o $(NAME_SERVER) & \
	./gui_load.sh "Minitalk_Server"
	@wait

################################################################################
# 										PS		 	 						   #
################################################################################

.PHONY: all clean fclean re
