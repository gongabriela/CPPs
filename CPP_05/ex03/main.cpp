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

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    std::cout << "\n=========================================" << std::endl;
    std::cout << "        INTERN CREATION TESTS" << std::endl;
    std::cout << "=========================================\n" << std::endl;

    Intern someRandomIntern;
    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* unknown = NULL;

    std::cout << "[1] Testing Robotomy Request Form (Valid):" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    std::cout << "\n[2] Testing Shrubbery Creation Form (Valid):" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");

    std::cout << "\n[3] Testing Presidential Pardon Form (Valid):" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

    std::cout << "\n[4] Testing Unknown Form (Invalid / Edge Case):" << std::endl;
    // This should print an explicit error message and return NULL
    unknown = someRandomIntern.makeForm("make coffee request", "Intern");


    std::cout << "\n=========================================" << std::endl;
    std::cout << "     INTEGRATION TEST WITH BUREAUCRAT" << std::endl;
    std::cout << "=========================================\n" << std::endl;

    try {
        Bureaucrat boss("Hermes Conrad", 1); // Highest possible grade
        std::cout << boss << std::endl;

        if (rrf) {
            std::cout << "\n--- Boss interacting with Robotomy Form ---" << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
        }
    }
    catch (std::exception &e) {
        std::cerr << "Unexpected error during Bureaucrat integration: " << e.what() << std::endl;
    }


    std::cout << "\n=========================================" << std::endl;
    std::cout << "       CLEANUP (MEMORY MANAGEMENT)" << std::endl;
    std::cout << "=========================================\n" << std::endl;

    // Deleting the allocated forms to prevent memory leaks.
    // Note: 'unknown' is expected to be NULL, and deleting NULL is safe in C++.
    delete rrf;
    delete scf;
    delete ppf;
    delete unknown;

    std::cout << "Cleanup complete. End of tests." << std::endl;

    return 0;
}