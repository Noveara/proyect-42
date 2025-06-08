# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noa <noa@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 12:49:53 by noa               #+#    #+#              #
#    Updated: 2025/06/08 13:49:19 by noa              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

SRC = main.c utils.c 
BONUS_SRC = main_bonus.c utils_bonus.c


.PHONY: all clean fclean re bonus libft

all: libft $(NAME)

libft:
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -L $(LIBFT_DIR) -lft -o $(NAME)

bonus: libft $(BONUS)
	
$(BONUS): $(BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_SRC) -L $(LIBFT_DIR) -lft -o $(BONUS)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f *.o

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS)

re: fclean all
