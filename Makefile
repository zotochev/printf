# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mscot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 21:10:56 by mscot             #+#    #+#              #
#    Updated: 2020/12/04 13:50:29 by mscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a

SRC		=	ft_printf.c		\
			format_parser.c		\
			print_utils.c		\
			print_processor.c	\
			format_len_utils.c	\
			format_utils.c		\
			print_string_utils.c

OBJ		=	$(SRC:.c=.o)

GFLG		=	-Wall -Wextra -Werror

CC		=	gcc $(GFLG)

all:		$(NAME)

$(NAME):	$(SRC) $(OBJ) ft_printf.c Makefile
			ar rc $@ $(OBJ)
			ranlib $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
