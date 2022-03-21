NAME=fractol
CC=gcc
RM=rm -f

SRC = mandelbrot.c zoom.c

OBJ = $(SRC:.c=.o)

MLXLINK	:=	-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
MLXINC	:=	-I /usr/local/include

LIB_LINK	+=	-lm $(MLXLINK)
LIB_INC		+=	$(MLXINC)

%.o: %.c
	$(CC) -Wall -Wextra -Werror $(MLXINC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXLINK) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
