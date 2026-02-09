/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:18:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/09 16:18:25 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    _name = "Default_FragTrap";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other); // Call the base class assignment operator
    }
    std::cout << "FragTrap copy assignment operator called for " << _name << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " asks for a high five!" << std::endl;
}


