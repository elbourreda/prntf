# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 15:18:53 by rel-bour          #+#    #+#              #
#    Updated: 2020/03/02 10:57:56 by rel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c print_u_plus.c conc_hex.c print_utils.c print_utils2.c print_gx.c print_c.c print_p.c print_u.c print_x.c get_data.c print_s.c print_d.c print_pers.c print_p_plus.c print_u_plus.c printf_x_plus.c printf_gx_plus.c

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
