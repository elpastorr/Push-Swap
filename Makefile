# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:52:12 by elpastor          #+#    #+#              #
#    Updated: 2022/03/11 17:17:19 by elpastor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c \
ft_sort.c \
ft_push_swap.c \
ft_rotate.c \
ft_rev_rotate.c \
ft_utils.c \
ft_utils2.c

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror

all:	${NAME}

.c.o:
	cc ${FLAGS} -c $^ -o $@

${NAME}: ${OBJS}
	cc ${FLAGS} ${OBJS} -o ${NAME}

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
