# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:02:48 by ilkaddou          #+#    #+#              #
#    Updated: 2024/12/30 22:42:02 by ilkaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -g3
LDFLAGS = -Llibft -lft

# Dossiers de sources
SRC_DIR = src
UTILS_DIR = utils
GNL_DIR = GNL_github
LIBFT_DIR = libft

# Fichiers sources
SRC_FILES = $(SRC_DIR)/check_map.c $(SRC_DIR)/init_map.c $(SRC_DIR)/main.c
UTILS_FILES = $(UTILS_DIR)/utils1.c
GNL_FILES = $(GNL_DIR)/get_next_line.c

# Fichiers objets
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.c=.o) $(UTILS_FILES:.c=.o) $(GNL_FILES:.c=.o)

# Nom de l'exécutable
NAME = solong

# Règles de compilation
all: $(NAME)

# Compilation de l'exécutable final
$(NAME): $(OBJ_FILES)
	make -C $(LIBFT_DIR)   # Compiler la libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LDFLAGS)

# Compilation des fichiers objets à partir des fichiers sources
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

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
