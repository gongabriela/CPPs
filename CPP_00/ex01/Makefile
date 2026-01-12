# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/22 10:02:15 by ggoncalv          #+#    #+#              #
#    Updated: 2026/01/11 11:47:17 by ggoncalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp

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