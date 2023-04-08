##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	./src/main.c\
		./src/functions.c\
		./src/other.c\
		./src/get_plane.c\
		./src/get_tower.c\
		./src/destroy.c\
		./src/cases.c\
		./lib/my_getnbr.c\
		./lib/my_putstr.c\
		./lib/my_putchar.c

OBJ	=	$(SRC:.c=.o)

NAME = my_radar

CFLAGS = -W -Wall -Wextra

SFML_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(SFML_FLAGS) -lm

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
