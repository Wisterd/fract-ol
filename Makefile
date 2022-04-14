NAME=fractol
CC=gcc
FLAGS = -Wall -Wextra -O3
RM=rm -f
DEPS = fractol.h
OBJ = atof.o algos.o zoom.o utils.o utils2.o hook.o main.o \
color.o parsing.o

LIB_LINK = ../mlx/libmlx_Linux.a -lXext -lX11 -lm

%.o: %.c $(DEPS)
	$(CC) -Imlx -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FLAGS)
#$(CC) $(OBJ) $(LIB_LINK) -o $(NAME) $(FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
