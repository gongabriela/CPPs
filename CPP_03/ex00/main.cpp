/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:23:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/07 09:23:30 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap a("Ash");
    
    a.attack("Pikachu");
    a.takeDamage(5); // HP turns 5
    a.beRepaired(2); // HP turns 7, Energy drops
    a.takeDamage(10); // Should die and should zero HP (without breaking the unsigned)
    a.attack("Someone"); // Should not be able to attack because HP is 0
    
    return 0;
}