NAME=fractol
CC=gcc
FLAGS = -Wall -Wextra -Werror
RM=rm -f

SRC = atof.c mandelbrot.c zoom.c utils.c utils2.c hook.c main.c \
color.c parsing.c julia.c

OBJ = $(SRC:.c=.o) 
LIB_LINK = ../mlx/libmlx_Linux.a -lXext -lX11 -lm

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
