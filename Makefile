CC = cc -Wall -Wextra -Werror

FLAGS = -lmlx -framework OpenGL -framework AppKit 

####################

HLP = Helpers/Helpers.c \
		Helpers/H_Parsing.c \
		Helpers/Mandelbrot.c \
		Helpers/Julia.c \
		Helpers/h_event.c \
		Helpers/atoi.c

H_OBJ = $(HLP:.c=.o)

####################

SRC = ./Core.c 

OBJ = $(SRC:.c=.o)

####################

NAME = fractol

all : $(NAME)

$(NAME) : $(OBJ) $(H_OBJ)

	$(CC) $(FLAGS) $(OBJ) $(H_OBJ) -o $(NAME)

$(OBJ) : ./fractol.h $(SRC)

	$(CC) -c $(SRC) -o $(OBJ)

%.o : %.c ./fractol.h
	$(CC) -c $< -o $@

clean :

	rm -f $(OBJ) $(H_OBJ) 

fclean : clean

	rm -f $(NAME)

re : fclean all
