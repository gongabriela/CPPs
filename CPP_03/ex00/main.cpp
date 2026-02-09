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
    a.takeDamage(5); // HP vai pra 5
    a.beRepaired(2); // HP vai pra 7, Energia cai
    a.takeDamage(10); // Deve morrer e zerar HP (sem bugar o unsigned)
    a.attack("Someone"); // Não deve conseguir atacar pois HP é 0
    
    return 0;
}