NAME		=	rush-02

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -I ${INCLUDES} -g #-fsanitize=address

INCLUDES	=	./includes/

SRCS		=	srcs/main.c			\
				srcs/exit_utils.c	\
				srcs/list_utils.c	\
				srcs/ft_isspace.c	\
				srcs/ft_isnum.c		\
				srcs/ft_atoi.c		\
				srcs/ft_putstr.c	\
				srcs/ft_strlen.c	\
				srcs/ft_strtrim.c	\
				srcs/ft_strcmp.c	\
				srcs/ft_strjoin.c	\
				srcs/ft_split.c		\
				srcs/ft_free_tab.c	\
				srcs/ft_tablen.c	\
				srcs/ft_free_lst.c	\
				srcs/ft_strdup.c	\

OBJS		=	${SRCS:.c=.o}


all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			rm -rf ${OBJS}

fclean:		clean
			rm -rf ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
