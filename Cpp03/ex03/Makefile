NAME =	DiamondTrap
SRC =	main.cpp \
		ScavTrap.cpp \
		ClapTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp

OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98 -Wshadow

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
