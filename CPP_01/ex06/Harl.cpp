/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:45:28 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/29 14:45:28 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
    std::cout << "Constructor called" << std::endl;
} 

Harl::~Harl(void) {
    std::cout << "Destructor called" << std::endl;
}

void    Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did,  I wouldn't be asking for more!" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptrFunctions[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int i = 0;
    while (i < 4 && levels[i] != level) {
        i++;
    }

    switch (i) {
        case 0:
            std::cout << "[ " << levels[0] << " ]" << std::endl;
            (this->*ptrFunctions[0])();
            std::cout << std::endl;
            // fall through
        case 1:
            std::cout << "[ " << levels[1] << " ]" << std::endl;
            (this->*ptrFunctions[1])();
            std::cout << std::endl;
            // fall through
        case 2:
            std::cout << "[ " << levels[2] << " ]" << std::endl;
            (this->*ptrFunctions[2])();
            std::cout << std::endl;
            // fall through
        case 3:
            std::cout << "[ " << levels[3] << " ]" << std::endl;
            (this->*ptrFunctions[3])();
            std::cout << std::endl;
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}