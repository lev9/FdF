# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laskolin <laskolin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/09 08:30:56 by laskolin          #+#    #+#              #
#    Updated: 2020/07/16 16:47:59 by laskolin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c keys.c reader.c image.c draw.c user.c actions.c actions2.c color.c

OBJ = $(subst .c,.o,$(SRC))

REST = -L /usr/local/lib -lmlx -I /usr/X11/include -L/usr/X11/lib -lX11 \
	-lXext -framework OpenGL -framework Appkit -L./libft -lft

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I libft/ -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(REST)

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all
