/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:41 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 11:45:11 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phonebook;
    std::string input;

    std::cout << "Welcome to the phonebook!" <<std::endl;
    while (input != "EXIT") {
        do {
            std::cout << "Choose a command (ADD, SEARCH, EXIT): ";
            std::getline(std::cin, input);
        } while (input != "ADD" || input != "EXIT" || input != "SEARCH");
        if (input == "ADD")
                phonebook.AddContacts();
    }
}