#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/03 08:44:05 by mdarty            #+#    #+#              #
#    Updated: 2014/01/19 21:27:52 by mdarty           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	wolf3d

SRCS	=	main.c ft_image.c ft_wolf.c ft_strsub.c ft_mem.c ft_str.c\
			ft_error.c get_next_line.c ft_map.c ft_nbrsplit_first_line.c\
			ft_atoi.c ft_charsplit.c ft_distance.c ft_memcpy.c

OBJ		=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):
			gcc -c $(CFLAGS) $(SRCS);
			gcc -o $(NAME) $(CFLAGS) $(OBJ) -L/usr/X11/lib -lmlx -lXext -lX11;

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
