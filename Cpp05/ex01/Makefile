NAME =	Bureaucrat
SRC =	Bureaucrat.cpp \
		Form.cpp \
		main.cpp


OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
