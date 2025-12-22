/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:38:32 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 15:06:29 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//constructor
PhoneBook::PhoneBook(int valorInicial) {
    std::cout << "Welcome to the phonebook!" <<std::endl;
    this->index = this->totalContacts = valorInicial;
}

//adiciona o contacto apos ter tudo preenchido
void    PhoneBook::AddContacts() {
    std::cout << "Please fill out all contact information" << std::endl;
    std::string firstName = getInfo("first name");
    std::string lastName = getInfo("last name");
    std::string nickname = getInfo("nickname");
    std::string phoneNumber = getInfo("phone number");
    std::string darkestSecret = getInfo("darkest secret");
    this->contacts[this->index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    this->index = (this->index + 1) % 8;
    if (this->totalContacts < 8)
        this->totalContacts++;
}

//pega cada informacao do contacto
std::string PhoneBook::getInfo(std::string info) {
    std::string input;
    
    do {
        std::cout << info << ": ";
        getline(std::cin, input);
    } while (input.empty()); //verificar que a pessoa de fato deu um input

    return input;   
}

//printar o Phonebook
void    PhoneBook::printPhonebook() {
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
                  << std::setw(10) << formatField(this->contacts[i].firstName) << "|"
                  << std::setw(10) << formatField(this->contacts[i].lastName) << "|"
                  << std::setw(10) << formatField(this->contacts[i].nickname) << "|"
                  << std::endl;
    }

    int chosenIndex;
    while (true) {
        std::string input;
        std::cout << "Type an index to view further details or ENTER to leave this page: ";
        getline(std::cin, input);
        if (input.empty())
            break ;
        std::stringstream ss(input);
        if ((ss >> chosenIndex && ss.eof()) && 
            (chosenIndex >= 0 && chosenIndex < this->totalContacts)) {
                this->printContact(chosenIndex);
                break ;
            }
        std::cout << "invalid index!" << std::endl;
    }
}

//printar UM contacto
void    PhoneBook::printContact(int index) {
    
    std::cout << std::endl << "======== CONTACT INFO ========" << std::endl;
    std::cout << "First name: " << this->contacts[index].firstName << std::endl;
    std::cout << "Last name: " << this->contacts[index].lastName << std::endl;
    std::cout << "Nickname: " << this->contacts[index].nickname << std::endl;
    std::cout << "Phone number: " << this->contacts[index].phoneNumber << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].darkestSecret << std::endl;
    std::cout << "Contact added successfully at index " << this->index << "!" << std::endl;
}

std::string PhoneBook::formatField(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}