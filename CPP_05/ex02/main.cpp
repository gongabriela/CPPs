/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:31:43 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/19 16:31:43 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL)); // Initialize the seed for Robotomy's rand()

    std::cout << "\n----- TEST 1: The Happy Path (Boss Bureaucrat) -----" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n[Signing the forms]" << std::endl;
        boss.signForm(shrub);
        boss.signForm(robot);
        boss.signForm(pardon);

        std::cout << "\n[Executing the forms]" << std::endl;
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- TEST 2: Permission Failure (Intern Bureaucrat) -----" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        ShrubberyCreationForm shrub("Backyard");

        intern.signForm(shrub); // Will fail and print the correct message
        intern.executeForm(shrub); // Tries to execute even without signature and grade
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- TEST 3: Unsigned Form Failure -----" << std::endl;
    try {
        Bureaucrat manager("Manager", 40);
        RobotomyRequestForm robot("R2D2");

        // manager.signForm(robot); // We forgot to sign on purpose!
        manager.executeForm(robot); // Should throw an error stating it is not signed
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- TEST 4: The Luck Factor (Robotomy 5 times) -----" << std::endl;
    try {
        Bureaucrat scientist("Scientist", 5);
        RobotomyRequestForm robot("C3PO");

        scientist.signForm(robot);
        for (int i = 0; i < 5; i++) {
            std::cout << "\nAttempt " << i + 1 << ":" << std::endl;
            scientist.executeForm(robot);
        }
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n----- END OF TESTS -----" << std::endl;
    return 0;
}