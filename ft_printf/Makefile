# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 12:41:24 by ilkaddou          #+#    #+#              #
#    Updated: 2025/01/17 20:20:38 by ilkaddou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc -Wall -Wextra -Werror
SOURCES = ft_itoa_signed.c ft_itoa_unsigned.c ft_printf.c \
      print_char_int.c print_hex_pointer.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

# Créer l'archive libftprintf.a
$(NAME): $(OBJECTS)
	@echo "Création de l'archive $@\n"
	ar rcs $(NAME) $(OBJECTS)

# Compilation des fichiers .c en fichiers .o
%.o: %.c
	@echo "\nCompilation de $<"
	$(CC) -c $< -o $@

clean:
	@echo "\nSuppression des fichiers objets"
	rm -f $(OBJECTS)

fclean: clean
	@echo "\nSuppression de l'archive $(NAME)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
