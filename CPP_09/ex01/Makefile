# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 07:29:03 by ggoncalv          #+#    #+#              #
#    Updated: 2026/11/03 06:41:33 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

debug:
	$(CPP) $(CPPFLAGS) -g $(SRC) -o $(NAME)
	gdb --tui $(NAME)

valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(NAME)
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@