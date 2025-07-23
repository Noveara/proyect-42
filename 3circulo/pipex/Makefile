# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 19:35:13 by nsueiro-          #+#    #+#              #
#    Updated: 2025/07/09 18:18:52 by nsueiro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
RM = rm -rf

SRCS = pipex.c utils.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)  # Compila libft
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Pipex compiled!"

clean:
	@$(RM) $(OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re 
