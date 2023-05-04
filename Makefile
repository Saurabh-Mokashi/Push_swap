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


NAME = push_swap
SRCS = push_swap.c instructions_a.c instructions_b.c tog_instr.c ft_split.c\
		misc.c multiparser.c postparser.c find.c delalloc.c \
		instructions_a1.c instructions_b1.c sort.c misc2.c sort2.c misc3.c\
		misc4.c temp.c

OBJS = $(SRCS:.c=.o)
INCLUDES = -I./ft_printf/includes -I./includes

FT_PRINTF = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf


.c.o:
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

all : $(NAME)


$(NAME) : $(FT_PRINTF) $(OBJS)
			${CC} ${CFLAGS} ${OBJS} ${FT_PRINTF} -o ${NAME}

$(FT_PRINTF) : 
	@make -C ft_printf

clean:
	$(RM) $(OBJS)
	@ make -C ft_printf clean
fclean: clean
	$(RM) $(NAME)
	@ make -C ft_printf fclean

re: fclean all

.PHONY: 	all clean fclean re