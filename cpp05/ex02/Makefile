FLAGS = -Wall -Wextra -Werror -std=c++98
CC = g++
INCLUDE = -Iinclude/
NAME = Bureaucrat

SRC_DIR = src/
OBJ_DIR = .bin/

CLASS = Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
SRCS = main.cpp $(addprefix $(SRC_DIR), $(CLASS))

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:%.cpp=%.o)))

vpath %.cpp $(SRC_DIR) .

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Final Executable \033[1;32m$(NAME)\033[0m Compiled"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) *_shrubbery
	@echo "Removing Objects" 

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed"

re: fclean all

.PHONY: fclean, all, re