# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmovahhe <mmovahhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 18:10:13 by jdescler          #+#    #+#              #
#    Updated: 2018/12/15 20:09:47 by mmovahhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRCS = src/main.c\
	   src/parse.c\
	   src/print.c\
	   src/print_algo.c\
	   src/error.c\
	   src/color.c\
	   src/event.c\
	   src/image.c\
	   src/bis.c\
	   src/event_modif.c\
	   src/set_all.c

OBJS = $(SRCS:.c=.o)

CC = gcc -Iincludes/

CFLAGS = -Wall -Werror -Wextra

MLX = -lmlx -framework OpenGL -framework AppKit -L ./minilibx_macos/

LIBFT = libft/libft.a

.PHONY: all lib clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	-rm -f $(OBJS)

fclean:clean
	@make fclean -C ./libft/
	-rm -f $(NAME)

re: fclean all
