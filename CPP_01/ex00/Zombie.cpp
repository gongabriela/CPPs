/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:41:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 10:41:15 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Constructor was called!" << std::endl;
}
void    Zombie::announce(void) const {
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const {
    return this->name;
}

Zombie::~Zombie() {
    std::cout << this->name << " was destroyed!" << std::endl;
}

void    Zombie::setName(std::string name) {
    this->name = name;
}
/*
    Quando você usa delete, o destrutor é chamado automaticamente antes de 
    liberar a memória. O zombie na stack (randomChump) terá seu destrutor 
    chamado automaticamente ao final da função.
*/