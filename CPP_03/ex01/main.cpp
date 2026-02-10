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
#include "ScavTrap.hpp"

int main() {
    std::cout << "### TEST 1: CONSTRUCTOR AND INHERITANCE CHAIN ###" << std::endl;
    {
        // Stack Creation: Should call ClapTrap Constructor -> ScavTrap Constructor
        ScavTrap robot("Serena");
        
        std::cout << "\n--- Testing Attributes and Methods ---" << std::endl;
        // Should print: "ScavTrap Serena attacks..." (Damage 20)
        robot.attack("Enemy"); 
        
        // Should use the parent function (ClapTrap), but with HP 100
        robot.takeDamage(10); 
        robot.beRepaired(10); 

        // ScavTrap exclusive function
        robot.guardGate();
        
        std::cout << "\n--- End of Scope (Destruction) ---" << std::endl;
        // Here should call: ScavTrap Destructor -> ClapTrap Destructor
    }

    std::cout << "\n\n### TEST 2: CANONICAL FORM (COPY AND ASSIGNMENT) ###" << std::endl;
    {
        ScavTrap original("Original");
        
        std::cout << "\n[Copying...]" << std::endl;
        ScavTrap copia(original); // Copy Constructor
        
        std::cout << "\n[Assigning...]" << std::endl;
        ScavTrap atribuido("Temp");
        atribuido = original; // Copy Assignment Operator
        
        std::cout << "\n--- Destroying copies ---" << std::endl;
    }

    std::cout << "\n\n### TEST 3: POLYMORPHISM (VIRTUAL DESTRUCTOR TEST) ###" << std::endl;
    std::cout << "If the ClapTrap destructor is not virtual, ScavTrap will leak memory here!" << std::endl;
    {
        // ClapTrap pointer pointing to ScavTrap
        ClapTrap* ptr = new ScavTrap("HeapRobot");
        
        // The attack here will call ClapTrap's if not virtual, 
        // or ScavTrap's if attack is virtual (the subject doesn't require attack to be virtual, but it's good to know)
        ptr->attack("Target"); 

        std::cout << "\n[Deleting via base pointer...]" << std::endl;
        delete ptr; // IMPORTANT: Should call ~ScavTrap then ~ClapTrap
    }

    return 0;
}