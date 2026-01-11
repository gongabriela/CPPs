/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:38:32 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/01/11 13:16:02 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructor
PhoneBook::PhoneBook() {
    std::cout << "Welcome to the phonebook!" <<std::endl;
    this->index = 0;
    this->totalContacts = 0;
}

// adds the contact after all fields are filled in
void    PhoneBook::AddContacts() {
    std::cout << "Please fill out all contact information" << std::endl;
    std::string firstName = getInfo("first name");
    std::string lastName = getInfo("last name");
    std::string nickname = getInfo("nickname");
    std::string phoneNumber = getInfo("phone number");
    std::string darkestSecret = getInfo("darkest secret");
    this->contacts[this->index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret); //instanciated contact obj
    this->index = (this->index + 1) % 8; //circular buffer
    if (this->totalContacts < 8)
        this->totalContacts++;
}

// fetches each contact's information
std::string PhoneBook::getInfo(const std::string& info) {
    std::string input;
    
    do {
        std::cout << info << ": " << std::endl;
        getline(std::cin, input);
    } while (!verifyInput(info, input)); // verify that the user actually provided input // maybe place a full validation function here?

    return input;   
}

// verify user input
bool    PhoneBook::verifyInput(const std::string &info, const std::string &input) {
    if (input.empty()) {
        std::cout << "Field cannot be empty!" << std::endl;
        return false;
    }
    if (info == "phone number") {
        if (input.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "the field phone number only accepts numbers as inputs!" << std::endl;
            return false;
        }
    }
    return true;
}

// print the PhoneBook
void    PhoneBook::printPhonebook() const {
    if (this->totalContacts == 0) {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }
    std::cout << "|" << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << "|" << std::endl;
    
    for (int i = 0; i < this->totalContacts; i++) {
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(this->contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(this->contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(this->contacts[i].getNickname()) << "|"
                  << std::endl;
    }

    int chosenIndex = -1;
    while (true) {
        std::string input;
        std::cout << "Type an index to view further details or ENTER to leave this page: " << std::endl;
        getline(std::cin, input);
        if (input.empty())
            break ;
        if (input.size() == 1 && isdigit(input[0]))
            chosenIndex = input[0] - '0';
        if (chosenIndex >= 0 && chosenIndex < this->totalContacts) {
                this->printContact(chosenIndex);
                break ;
            }
        std::cout << "invalid index!" << std::endl;
    }
}

// print a SINGLE contact
void    PhoneBook::printContact(int index) const {
    
    std::cout << std::endl << "=============== CONTACT INFO ===============" << std::endl;
    std::cout << "First name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

std::string PhoneBook::formatField(const std::string& str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}