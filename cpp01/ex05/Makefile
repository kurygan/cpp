FLAGS = -Wall -Wextra -Werror -std=c++98
CC = c++
NAME = Harl
SRCS = main.cpp Harl.cpp

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "Final Executable \033[1;31m$(NAME)\033[0m Compiled"

.cpp.o:
	$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
	@$(RM) $(OBJS)
	@echo "Removing Objects" 

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed"

re: fclean all

.PHONY: fclean, all, re