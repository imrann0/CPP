# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albozkur <albozkur@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/29 16:01:12 by albozkur          #+#    #+#              #
#    Updated: 2024/06/29 16:08:27 by albozkur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
FLAG = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean
	fclean all
