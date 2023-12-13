NAME = push_swap
CC = cc
CFLAG = -Wall -Werror -Wextra
SRC = push_swap.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h
RM = rm -rf

%.o:%.c
	$(CC) $(CFLAG) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) -I$(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
