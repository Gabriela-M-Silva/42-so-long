# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 23:17:06 by gde-mora          #+#    #+#              #
#    Updated: 2022/10/17 09:08:19 by gde-mora         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c validate_map.c validate_extension.c validate_rectangular.c \
	validate_walls.c validate_chars.c validate_path.c handle_game.c \
	handle_render.c handle_key.c handle_x.c handle_moves.c handle_direction.c

OBJ = $(SRC:.c=.o)

LIBFT_A = libft.a

LIBFT_COMPILE = cd libft && make

LIBFT_COPY = cp ./libft/libft.a $(LIBFT_A)

LIBFT_FCLEAN = cd libft && make fclean

HEADER = so_long.h

CCFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lX11 -lXext -lmlx

RM = rm -f

all: $(NAME)

.c.o:
	cc $(CCFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(OBJ) $(HEADER)
	$(LIBFT_COMPILE)
	$(LIBFT_COPY)
	cc $(CCFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) $(LIBFT_A)

clean:
	$(RM) $(OBJ)
	$(RM) $(LIBFT_A)
	$(LIBFT_FCLEAN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
