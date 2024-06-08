NAME = fractol
SRC = events.c init.c main.c math_utils.c render.c string_utils.c
OBJ = $(SRC:.c=.o)
COMPLE = cc
FLAGS = -Wall -Wextra -Werror
LIBXFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

all: $(NAME)

$(NAME) : $(OBJ)
	$(COMPLE) $(FLAGS) $(OBJ) $(LIBXFLAGS) -o $(NAME)

%.o: %.c
	$(COMPLE) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
	
re: fclean all
