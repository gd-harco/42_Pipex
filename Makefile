# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	pipex

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Libs variables ---- #

LIBFT            =   libft/libft.a



# ---- Files ---- #

HEADERS_LIST	= pipex.h

SRCS_LIST		=	main.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g3

FRAMEWORKS		=	-Llibft -lft

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)



# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS} ${LIBFT}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}
					@echo "\033[0;32m [${NAME}] : ✔️ Successfully built so_long executable\033[1;36m ${NAME}\033[0;32m for \033[1;36m${UNAME} !\033[0;00m"

# ---- Lib rules ---- #

${LIBFT}		:
						make -C libft
						@echo "\033[0;32m [${NAME}/libft] : ✔️ Successfully built libft\033[1;36m ${@} !\033[0;32m"



# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}
					${MKDIR} ${DIR_OBJS}/parsing
					${MKDIR} ${DIR_OBJS}/actions
					${MKDIR} ${DIR_OBJS}/sorting
					@echo "\033[0;32m [${NAME}/bin] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;00m"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [${NAME}/bin] : ✔️ Successfully cleaned bin directories\033[1;36m bin/ !\033[0;00m"

fclean			:	clean
					${RM} ${NAME}
					@echo "\033[0;31m [${NAME}] : ✔️ Successfully deleted executable\033[1;36m ${NAME} !\033[0;00m"

re				:	fclean all


.PHONY:	all clean fclean re
