# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/10 13:33:57 by andriamr          #+#    #+#              #
#    Updated: 2025/07/10 17:55:20 by andriamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = algo_utils1.c \
		algo_utils2.c \
		algo2.c \
		chek_error.c \
		instriction1.c \
		instruction2.c \
		list_utils.c \
		push_swap_list_add.c \
		push_swap_utils1.c \
		take_nbr.c \
		main.c \

CC = cc

FLAG = -Wall -Werror -Wextra

NAME = push_swap

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

$(NAME) : $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re		