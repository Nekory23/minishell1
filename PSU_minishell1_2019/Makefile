##
## EPITECH PROJECT, 2020
## minishell1
## File description:
## makefile
##

NAME	=	mysh

SRC	=	src/main.c		\
		src/minishell.c		\
		src/check_command.c	\
		src/get_env.c		\
		src/get_args.c		\
		src/realloc.c		\
		src/my_cd.c		\
		src/my_env.c		\
		src/my_setenv.c		\
		src/my_unsetenv.c	\
		src/my_exit.c		\
		src/compare_str.c	\
		src/segfault_handling.c	\
		src/clean_str.c		\
		util/my_strcat.c	\
		util/my_strlen.c	\
		util/my_putstr.c	\
		util/my_put_nbr.c	\
		util/my_putchar.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wextra -Wall

CPPFLAGS=	-I./include/

all	:	$(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC) $(CPPFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
