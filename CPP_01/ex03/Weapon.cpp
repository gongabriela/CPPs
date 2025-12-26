/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:58:03 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 17:58:03 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//constructor
Weapon::Weapon(const std::string& type) {
    std::cout << "Constructor was called!" << std::endl;
    this->setType(type);
}

//destructor
Weapon::~Weapon() {
    std::cout << "Destructor was called for " << this->getType() << std::endl;
}

//getter
const std::string& Weapon::getType() const {
    return this->type;
}

//setter
void    Weapon::setType(const std::string& type) {
    this->type = type;
}
 /*
    Porque passar a referencia mesmo sendo const?
    pela EFICIENCIA:
    Return by value (std::string getType()):
    -> Creates and returns a copy of the string
    -> Expensive, especially for larger strings (memory allocation, copying characters)
    
    Return by const reference (const std::string& getType() const):
    -> Returns a reference to the actual internal string (no copy!)
    -> Much more efficient (no allocation, no copying)
    -> The const prevents the caller from modifying it through that reference
 */