/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 19:24:27 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 19:24:27 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {
    std::cout << "Constructor was called for " << this->name << std::endl;
}

HumanB::~HumanB() {
    std::cout << "Destructor was called for " << this->name << std::endl;
}

void    HumanB::attack() const {
    if (this->weapon == NULL)
        std::cout << this->name << " had no weapon and could not defend themself :(" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}