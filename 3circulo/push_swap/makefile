# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 19:00:29 by nsueiro-          #+#    #+#              #
#    Updated: 2025/07/23 18:51:44 by nsueiro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
RM = rm -rf

SRCS = push_swap_cmd.c push_swap_init.c push_swap_lst.c push_swap_lst2.c \
push_swap_moves.c push_swap_rot.c push_swap_smallest.c push_swap_sort_big.c \
push_swap_sort.c push_swap_steps.c push_swap_utils.c push_swap.c \
push_swap_rotations.c 

BONUS = push_swap_checker_utils.c push_swap_checker.c

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	make -C ./libft
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@echo "Compile $< a $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(BONUS_OBJ) -o $(NAME)

.PHONY: all bonus clean fclean re
