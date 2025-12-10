FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Brain

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) main.cpp -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re