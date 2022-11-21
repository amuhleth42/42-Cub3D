SRCS_DIR	= ./
SRCS_FILES	=  0_parser_main.c\
 			   M_parser_map.c\
			   C_parser_color.c\
			   S_parser_sprite.c\
 			   A_stock_arguments.c\
 			   M_stock_map.c\
 			   A_height_calculator.c\
 			   A_tools_fct.c\
 			   A_error_manager.c\
 			   C_checker_color.c\
 			   S_checker_sprite.c\

#			   exit.c\


SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

UNAME		:= $(shell uname)

LIBFT		= ../../libft
MAKELIB		= ${MAKE} -C ${LIBFT}

ifeq ($(UNAME), Darwin)
	LIBX		= ./../mlx
else
	LIBX		= ./mlx_linux
endif
MAKELIBX	= ${MAKE} -C ${LIBX}


O_DIR		= ./objs/
D_DIR		= ./debugs/
HEADS		= -I./includes/ -I${LIBX} -I${LIBFT}

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
DEBUGS		:= ${patsubst %, ${D_DIR}%, ${OBJS_FILES}}

OBJS		+= ${LIBFT}/libft.a
DEBUGS		+= ${LIBFT}/libft.a
#
OBJS		+= ${LIBX}/libmlx.a
DEBUGS		+= ${LIBX}/libmlx.a


#VALGRIND	= valgrind  --main-stacksize=167104768 --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=memcheckignore --gen-suppressions=yes
#VALGRIND	= valgrind  --suppressions=memcheckignore --gen-suppressions=yes

ifeq ($(UNAME), Darwin)
	LIBS		= -framework OpenGL -framework AppKit
else
	LIBS		= -lm -lbsd -lX11 -lXext
endif

NAME		= Z_maps
#ifeq (${OS},Windows_NT)
#	NAME	:= ${NAME:=.exe}
#endif

CC			= gcc
H			= 0_parser_maps.h
AR			= ar rcs
MKDIR		= mkdir
CP			= cp -f
RM			= rm -f
 
CCFLAGS		= -Wall -Wextra -Werror # -O3# -march=native


all:		${NAME}

#Compile normal executable
${NAME}:	${O_DIR} ${OBJS}
			${CC} ${CCFLAGS} -o ${NAME} ${OBJS} ${LIBS}

#Create objects directory
${O_DIR}:
			${MKDIR} ${O_DIR}

#Compile normals objects
${O_DIR}%.o:${SRCS_DIR}%.c | ${H}
			${CC} ${CCFLAGS} ${HEADS} -o $@ -c $<

##Compile libft
${LIBFT}/libft.a:
			${MAKELIB} all

#Compile minilibx
${LIBX}/libmlx.a:
			${MAKELIBX} all



#Compile and use valgrind
valgrind:	${D_DIR} ${DEBUGS}
			${RM} ${NAME}
			${CC} ${CCFLAGS} -o ${NAME} ${DEBUGS} ${LIBS} -ggdb
			${VALGRIND} ./${NAME}


#Compile a debug executable with -g and fsanitize
debug:		${D_DIR} ${DEBUGS}
			${MAKELIB} all
			${MAKELIBX} all
			${CC} ${CCFLAGS} -fsanitize=address -o ${NAME} ${DEBUGS} ${LIBS}

#Create debug directory
${D_DIR}:
			${MKDIR} ${D_DIR}

#Compile debug objects
${D_DIR}%.o:${SRCS_DIR}%.c
			${CC} ${CCFLAGS} -g ${HEADS} -o $@ -c $<


clean:
			${RM} ${OBJS} ${OBJSB} ${DEBUGS}
			@${RM} -r ${O_DIR}
			@${RM} -r ${D_DIR}
			@${MAKELIB} clean
			@${MAKELIBX} clean

fclean:		clean
			${RM} ${NAME}
			@${RM} -r ${NAME}.dSYM
			@${MAKELIB} fclean

re:			fclean all

.PHONY:		all clean fclean re debug

