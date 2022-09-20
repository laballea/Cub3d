# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laballea <laballea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 15:19:20 by laballea          #+#    #+#              #
#    Updated: 2019/12/02 18:00:17 by laballea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c libftsrc/*.c cub3dsrc/*.c

CFLAGS = -I /usr/local/include/ -I /Users/laballea/Documents/Cub3d/include/ ${SRC} -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

OBJ = $(subst .c,.o,$(SRC))

all:
	gcc $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean

re: fclean all

.PHONY : fclean re clean