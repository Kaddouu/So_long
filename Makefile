# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:02:48 by ilkaddou          #+#    #+#              #
#    Updated: 2025/01/17 20:18:58 by ilkaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ift_printf -g3
LDFLAGS = -Llibft -lft -Lft_printf -lftprintf
SRC_DIR = src
UTILS_DIR = utils
GNL_DIR = GNL
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
OBJ_DIR = obj
NAME = so_long

# Détection du système d'exploitation
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    MLX_DIR = minilibx_macos
    MLX_FLAGS = -framework OpenGL -framework AppKit
else
    MLX_DIR = minilibx-linux
    MLX_FLAGS = -Lmlx -lm -lbsd -lX11 -lXext
endif
MLX_LIB = $(MLX_DIR)/libmlx.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRC_FILES = $(SRC_DIR)/check_map.c \
            $(SRC_DIR)/init_map.c \
            $(SRC_DIR)/main.c \
            $(SRC_DIR)/render_game.c

UTILS_FILES = $(UTILS_DIR)/animations.c \
              $(UTILS_DIR)/floodfill.c \
              $(UTILS_DIR)/handle_move.c \
              $(UTILS_DIR)/handle_texture.c \
              $(UTILS_DIR)/init_map_utils.c \
              $(UTILS_DIR)/monster_init.c \
              $(UTILS_DIR)/monster_render.c \
              $(UTILS_DIR)/monster_update.c \
              $(UTILS_DIR)/monster_utils.c \
              $(UTILS_DIR)/player_directions.c \
              $(UTILS_DIR)/texture_decor.c \
              $(UTILS_DIR)/textures_utils.c \
              $(UTILS_DIR)/animations_utils.c \
              $(UTILS_DIR)/free_utils.c

GNL_FILES = $(GNL_DIR)/get_next_line.c

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(UTILS_FILES:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(GNL_FILES:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(MLX_LIB) $(PRINTF_LIB) $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Installing $(MLX_DIR)..."; \
		git clone https://github.com/42Paris/minilibx-$(UNAME).git $(MLX_DIR); \
		make -C $(MLX_DIR); \
	fi

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJ_FILES)
	@make -C $(LIBFT_DIR)
	$(CC) $(OBJ_FILES) $(MLX_LIB) -o $(NAME) $(MLX_FLAGS) -L$(PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@if [ -d "$(MLX_DIR)" ]; then \
		make clean -C $(MLX_DIR); \
	fi

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	@rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
