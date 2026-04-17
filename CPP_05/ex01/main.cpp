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
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- TEST 1: Form Constructor Exceptions ---" << std::endl;
    try {
        std::cout << "Trying to create a form with sign grade 0..." << std::endl;
        Form f1("Invalid Form 1", 0, 50);
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "Trying to create a form with exec grade 151..." << std::endl;
        Form f2("Invalid Form 2", 50, 151);
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Form operator<< ---" << std::endl;
    Form taxForm("28B", 50, 20);
    std::cout << taxForm << std::endl; 

    std::cout << "\n--- TEST 3: Bureaucrat with sufficient grade signs the form ---" << std::endl;
    Bureaucrat alice("Alice", 10); 
    std::cout << alice << std::endl;
    
    alice.signForm(taxForm); 
    std::cout << taxForm << std::endl; 

    std::cout << "\n--- TEST 4: Bureaucrat with INSUFFICIENT grade tries to sign ---" << std::endl;
    Bureaucrat bob("Bob", 100); 
    Form secretForm("Top Secret", 10, 5); 
    
    std::cout << bob << std::endl;
    std::cout << secretForm << std::endl;

    bob.signForm(secretForm); 

    std::cout << "\n--- END OF TESTS ---" << std::endl;

    return 0;
}