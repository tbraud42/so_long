# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbraud <tbraud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 18:10:28 by tbraud            #+#    #+#              #
#    Updated: 2024/04/17 02:16:38 by tbraud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= so_long

SRC_DIR	:= src
OBJ_DIR	:= obj

CC		:= clang
CFLAGS	:= -Wextra -Wall -Werror

INCLUDE	:= -I ./include

SRC		:= main.c
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

GREEN	:= \033[1;32m
NC		:= \033[0m

LIB 	:= make -sC mlx
LIB.A	:= mlx/libmlx_Linux.a

ifdef DEBUG
CFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIB)
	@$(CC) $(OBJ) $(LIB.A) -lXext -lX11 -lm -lz -o $(NAME) && printf "$(GREEN)✔️ $(NAME)$(NC) compiled\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE) && printf "$(GREEN)✔️ $(notdir $<)$(NC) compiled\n"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
