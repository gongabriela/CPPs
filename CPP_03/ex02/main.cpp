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

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp" // Optional: Include if you want to compare the two siblings

int main() {
    std::cout << "\n===============================================" << std::endl;
    std::cout << "         TEST 1: FRAGTRAP'S BIRTH        " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        // Should call: ClapTrap Constructor -> FragTrap Constructor
        std::cout << "\n[Creating FragTrap 'Grenade']" << std::endl;
        FragTrap frag("Grenade");

        std::cout << "\n[Checking Initial Status]" << std::endl;
        // HP: 100, EP: 100, AD: 30
        // Let's spend energy and attack to prove the values
        
        frag.attack("Target Dummy"); 
        // NOTE: If you didn't override attack(), it will show "ClapTrap... causing 30 damage".
        // The important thing here is that DAMAGE is 30!

        frag.takeDamage(20); // HP drops to 80
        frag.beRepaired(10); // HP back to 90, EP drops to 99
        
        std::cout << "\n[Testing Special Ability]" << std::endl;
        frag.highFivesGuys(); // Should print the positive message
        
        std::cout << "\n[Destroying 'Grenade']" << std::endl;
        // Should call: FragTrap Destructor -> ClapTrap Destructor
    }

    std::cout << "\n===============================================" << std::endl;
    std::cout << "      TEST 2: COPY AND ASSIGNMENT (CANONICAL)     " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        std::cout << "\n[Creating Original]" << std::endl;
        FragTrap original("Original");
        
        std::cout << "\n[Creating Copy (Copy Constructor)]" << std::endl;
        FragTrap copia(original);
        
        std::cout << "\n[Assigning (Assignment Operator)]" << std::endl;
        FragTrap atribuido("Temp");
        atribuido = original;
        
        std::cout << "\n[Modifying Copy (Deep Copy Test)]" << std::endl;
        copia.highFivesGuys(); // Does the copy work?
        
        std::cout << "\n[Destroying everything]" << std::endl;
    }

    std::cout << "\n===============================================" << std::endl;
    std::cout << "     TEST 3: POLYMORPHISM AND VIRTUAL DESTRUCTOR  " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        std::cout << "\n[Allocating FragTrap via ClapTrap pointer]" << std::endl;
        ClapTrap* ptr = new FragTrap("HeapFrag");

        std::cout << "\n[Using polymorphism]" << std::endl;
        ptr->attack("Air"); // Will use ClapTrap's attack (if not virtual) or FragTrap's
        
        // Trying to call highFivesGuys() here would error, 
        // since the pointer is ClapTrap and it doesn't know this function.
        
        std::cout << "\n[Deleting Pointer]" << std::endl;
        delete ptr; 
        // CRUCIAL: Should show ~FragTrap then ~ClapTrap.
        // If only ~ClapTrap appears, your virtual destructor in parent failed.
    }

    return 0;
}