NAME = push_swap
CC = cc
CFLAG = -Wall -Werror -Wextra
SRC = push_swap.c \
	  valid.c \
	  list.c \
	  list_utils.c \
	  compare.c \
	  swap.c \
	  push.c \
	  rotate.c \
	  rotate_rev.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h \
		 ./libft/libft.h
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
RM = rm -rf

%.o:%.c
	$(CC) $(CFLAG) -c -o $@ $< -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
