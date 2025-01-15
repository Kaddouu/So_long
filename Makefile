# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:02:48 by ilkaddou          #+#    #+#              #
#    Updated: 2025/01/15 20:10:42 by ilkaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -g3
LDFLAGS = -Llibft -lft

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	MLX_DIR = minilibx_macos
	MLX_LIB = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit
else  # Linux
	MLX_DIR = minilibx-linux
	MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
	MLX_FLAGS = -Lmlx -lm -lbsd -lX11 -lXext
endif


SRC_DIR = src
UTILS_DIR = utils
GNL_DIR = GNL
LIBFT_DIR = libft

SRC_FILES = $(SRC_DIR)/check_map.c $(SRC_DIR)/init_map.c $(SRC_DIR)/main.c $(SRC_DIR)/render_game.c
UTILS_FILES = $(wildcard $(UTILS_DIR)/*.c)
GNL_FILES = $(GNL_DIR)/get_next_line.c

OBJ_DIR = obj

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(UTILS_FILES:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(GNL_FILES:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = so_long

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MLX_LIB) $(MLX_FLAGS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

# Règle pour recompiler tout
re: fclean all

# Règle pour uniquement compiler la libft
libft:
	make -C $(LIBFT_DIR)

# Règle par défaut
.PHONY: all clean fclean re libft
