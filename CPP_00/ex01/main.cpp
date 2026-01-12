/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:41 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/01/11 12:50:17 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phonebook; // instantiated the object via the constructor
    std::string input;

    while (input != "EXIT") {
        do {
            std::cout << "Choose a command (ADD, SEARCH, EXIT): " << std::endl;
            std::getline(std::cin, input);
            if (input != "ADD" && input != "EXIT" && input != "SEARCH")
                std::cout << "Invalid command!" << std::endl;
        } while (input != "ADD" && input != "EXIT" && input != "SEARCH");
        if (input == "ADD")
                phonebook.AddContacts();
        else if (input == "SEARCH")
            phonebook.printPhonebook();
    }
    std::cout << "Thank you for using the PhoneBook! Bye for now :)" << std::endl;
}
