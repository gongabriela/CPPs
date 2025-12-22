/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:41 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 15:01:28 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phonebook(0); //instanciei o objeto com o constructor
    std::string input;

    while (input != "EXIT") {
        do {
            std::cout << "Choose a command (ADD, SEARCH, EXIT): ";
            std::getline(std::cin, input);
        } while (input != "ADD" && input != "EXIT" && input != "SEARCH");
        if (input == "ADD")
                phonebook.AddContacts();
        else if (input == "SEARCH")
            phonebook.printPhonebook();
    }
}
