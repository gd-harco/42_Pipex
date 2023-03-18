# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	pipex

NAME_BONUS		=	pipex_bonus

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_OBJS_BONUS	=	bin_bonus/

DIR_SRCS		=	srcs/

DIR_SRCS_BONUS	=	srcs_bonus/

DIR_HEADERS		=	include/

# ---- Libs variables ---- #

LIBFT            =   libft/libft.a

# ---- Files ---- #

HEADERS_LIST	=	pipex.h

SRCS_LIST		=	main.c			\
					parsing.c		\
					parsing_2.c		\
					error.c			\
					exec.c

SRCS_LIST_BONUS	=	main_bonus.c		\
					parsing_bonus.c		\
					parsing_2_bonus.c	\
					error_bonus.c		\
					exec_bonus.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

OBJS_BONUS		=	${SRCS_LIST_BONUS:%.c=${DIR_OBJS_BONUS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Werror -Wextra -g3 -fsanitize=address
FRAMEWORKS		=	-Llibft -lft

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:
					make -C libft/
					make ${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS} ${LIBFT}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}

# ---- Lib rules ---- #

${LIBFT}		:
						make -C libft

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}
					make -C libft fclean

re				:	fclean all


.PHONY:	all clean fclean re
