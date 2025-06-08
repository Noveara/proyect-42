# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noa <noa@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:37:33 by mokhan            #+#    #+#              #
#    Updated: 2025/06/08 14:39:37 by noa              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I $(LIBFT_DIR)

SRC = push_swap.c push_swap_cmd.c push_swap_init.c push_swap_lst.c push_swap_lst2.c push_swap_moves.c push_swap_rot.c push_swap_smallest.c push_swap_sort_big.c push_swap_sort.c push_swap_steps.c push_swap_utils.c
BONUS_SRC = push_swap_checker.c push_swap_checker_utils.c push_swap_cmd.c push_swap_init.c push_swap_lst.c push_swap_lst2.c push_swap_moves.c push_swap_smallest.c push_swap_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

RM = rm -f

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

.PHONY: all clean fclean re bonus libft
