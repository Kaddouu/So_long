# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:02:48 by ilkaddou          #+#    #+#              #
#    Updated: 2025/01/05 19:52:40 by ilkaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -g3
LDFLAGS = -Llibft -lft

# Dossiers de sources
SRC_DIR = src
UTILS_DIR = utils
GNL_DIR = GNL
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L $(MLX_DIR) -lX11 -lXext -g3

URL := https://cdn.intra.42.fr/document/document/28246/minilibx-linux.tgz

# Fichiers sources
SRC_FILES = $(SRC_DIR)/check_map.c $(SRC_DIR)/init_map.c $(SRC_DIR)/main.c $(SRC_DIR)/render_game.c
UTILS_FILES = $(UTILS_DIR)/utils1.c $(UTILS_DIR)/floodfill.c $(UTILS_DIR)/handle_texture.c $(UTILS_DIR)/handle_move.c
GNL_FILES = $(GNL_DIR)/get_next_line.c

# Dossier des objets
OBJ_DIR = obj

# Fichiers objets (avec le chemin vers le dossier obj)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(UTILS_FILES:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o) \
            $(GNL_FILES:$(GNL_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
NAME = so_long

# Règles de compilation
all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	curl -O $(URL)
	tar -xf $(MLX_DIR).tgz
	make --directory=$(MLX_DIR)
	rm -rf $(MLX_DIR).tgz

# Compilation de l'exécutable final
$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)   # Compiler la libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(MLX_LIB) $(MLX_FLAGS) $(LDFLAGS)

# Compilation des fichiers objets à partir des fichiers sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Créer le répertoire des objets si nécessaire
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Règle pour nettoyer les fichiers objets
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

# Règle pour supprimer tous les fichiers générés (objets + exécutable)
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
