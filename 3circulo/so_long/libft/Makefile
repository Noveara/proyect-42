# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 19:50:15 by nsueiro-          #+#    #+#              #
#    Updated: 2025/01/16 14:19:03 by nsueiro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente normales
SRC = ft_memset.c ft_bzero.c ft_strlen.c ft_atoi.c ft_isdigit.c ft_isalpha.c \
      ft_isprint.c ft_isascii.c ft_isalnum.c ft_memchr.c ft_memcpy.c \
      ft_memcmp.c ft_memmove.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
      ft_strncmp.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strrchr.c ft_calloc.c \
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
      ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Archivos fuente bonus
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
        ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# Archivos de objetos generados
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

# Nombre de la biblioteca estática
NAME = libft.a

# Regla por defecto para crear la biblioteca con solo los archivos normales
all: $(NAME)

# Regla para crear la biblioteca libft.a con solo los archivos normales
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

# Regla para compilar archivos .c en archivos .o
%.o: %.c
	@echo "Compilando $< a $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto generados
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Limpiar todos los archivos, incluyendo la biblioteca
fclean: clean
	rm -f $(NAME)

# Limpiar y recompilar todo
re: fclean all

# Regla para compilar y agregar tanto los objetos normales como los bonus a la biblioteca
bonus: $(OBJ) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all bonus clean fclean re
