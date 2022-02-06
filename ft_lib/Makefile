LIBNAME = libft.a

SRCN =ft_atoi.c ft_array.c ft_errno.c ft_isdigit.c ft_isspace.c ft_itoa.c \
		ft_list.c ft_stk_add.c ft_stk_del.c ft_stk_load.c ft_stk_prn.c ft_stk_opr.c ft_string.c

OBJ = ${SRCN:.c=.o}

DPDS = ${SRCN:.c=.d}

CC = gcc

RM	= rm -f

CFLAG = -Wall -Wextra -Werror

all:	${LIBNAME}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@

include ${wildcard ${DPDS}}

${LIBNAME}:	${OBJ}
	ar rcs $@ $?

clean:
	${RM} ${OBJ} ${DPDS}

fclean:	clean
	${RM} ${LIBNAME}

re:	fclean all

.PHONY: all bonus clean fclean re
