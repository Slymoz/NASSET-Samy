##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	./lib/my_putchar.c\
		./lib/my_putstr.c\
		./lib/my_strlen.c\
		./lib/my_getnbr.c\
		./lib/my_strcpy.c\
		./src/main.c\
		./src/functions.c\
		./src/move.c\
		./src/conditions.c

OBJ	=	$(SRC:.c=.o)

NAME = my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -Wall -Wextra -lncurses

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
