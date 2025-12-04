FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Megaphone

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) megaphone.cpp -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re