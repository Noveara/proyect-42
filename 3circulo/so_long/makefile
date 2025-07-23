# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 15:42:19 by nsueiro-          #+#    #+#              #
#    Updated: 2025/07/23 16:40:01 by nsueiro-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS =  main.c map_reader.c map_validate.c map_checker.c sprites_load.c \
		game_render.c player_moves.c
OBJDIR = obj
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fPIC
CC = cc
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -Ilibft
MINILIBX = ./minilibx-linux/libmlx.a

.PHONY: all clean fclean re libft_clean libft_fclean
all: $(LIBFT) $(NAME)
$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MINILIBX)  -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)
	chmod +x $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(MINILIBX):
	@make -C minilibx-linux
clean: libft_clean
	rm -rf $(OBJDIR)
fclean: clean libft_fclean
	rm -f $(NAME)
re: fclean all
libft_clean:
	$(MAKE) -C $(LIBFT_DIR) clean
libft_fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
$(OBJDIR)/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	