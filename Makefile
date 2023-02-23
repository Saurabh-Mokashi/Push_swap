# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smokashi <smokashi@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 00:55:41 by smokashi          #+#    #+#              #
#    Updated: 2023/02/13 00:55:41 by smokashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = push_swap.c instructions_a.c instructions_b.c tog_instr.c ft_split.c\
		misc.c multiparser.c postparser.c find.c delalloc.c \
		instructions_a1.c instructions_b1.c sort.c misc2.c sort2.c misc3.c\
		misc4.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

NAME = push_swap

all : $(NAME)


$(NAME) : $(OBJS)
			$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all
