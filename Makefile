PRJ_N = push_swap
BNS_N = checker

SRC_P = main.c ft_is_sort.c ft_stk_oprra.c ft_stk_oprrb.c  ft_stk_opswp.c ft_stk_sort.c ft_weight.c
SRC_B = main.c ft_strcmp.c ft_gnl.c

P_PRJ = ./project/
P_BON = ./bonus/
P_FTL = ./ft_lib/
INCPATH = ${P_FTL} ${P_PRJ} ${P_BON}

SRCS_P = ${addprefix ${P_PRJ}, ${SRC_P}}
SRCS_B = ${addprefix ${P_BON}, ${SRC_B}}

OBJ_P = ${SRCS_P:.c=.o}
OBJ_B = ${SRCS_B:.c=.o}

DPDS = ${SRCS_P:.c=.d} ${SRCS_B:.c=.d}

CC = gcc

RM = rm -f

CFLAG = -Wall -Wextra -Werror

all:	${PRJ_N}

%.o : %.c
	${CC} ${CFLAG} -MMD -c $< -o $@  -I"${INCPATH}"

include ${wildcard ${DPDS}}

libft:
	${MAKE} -C ${P_FTL}

${PRJ_N}:	libft ${OBJ_P}
	${CC} ${CFLAG} -o $@ -L${P_FTL} ${OBJ_P} -lft

${BNS_N}:	libft ${OBJ_B}
	${CC} ${CFLAG} -o $@ -L${P_FTL} ${OBJ_B} -lft

debug:
	${MAKE} CFLAG="${CFLAG} -g3" bonus

bonus:	${PRJ_N} ${BNS_N}

clean:
	${RM} ${OBJ_P} ${OBJ_B} ${DPDS}
	${MAKE} -C ${P_FTL} clean

fclean:	clean
	${RM} ${PRJ_N} ${BNS_N}
	${MAKE} -C ${P_FTL} fclean

re:	fclean all

.PHONY: all bonus clean fclean re debug
