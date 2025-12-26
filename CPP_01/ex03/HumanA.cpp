/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:59:45 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 18:59:45 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon)
    :   name(name),
        weapon(weapon) {

}

HumanA::~HumanA() {
    std::cout << "Destructor was called for " << this->name << std::endl;
}

void    HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}