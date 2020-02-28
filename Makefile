# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 15:18:53 by rel-bour          #+#    #+#              #
#    Updated: 2020/02/19 15:22:06 by rel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c print_utils.c print_gx.c print_C.c print_S.c

OBJS = *.o

FLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
