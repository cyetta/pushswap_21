LIBNAME = libft.a

SRCN =ft_atoi.c ft_array.c ft_errno.c ft_isdigit.c ft_isspace.c ft_itoa.c ft_string.c \
		ft_listadd.c ft_listdel.c ft_listnew.c ft_listload.c ft_listprint.c

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
