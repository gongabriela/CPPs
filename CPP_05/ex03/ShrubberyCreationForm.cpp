/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 13:37:40 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/21 13:37:40 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("Default") {
    std::cout << " Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {
    std::cout << " Parameterized ShrubberyCreationForm constructor called" << std::endl;
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {
    std::cout << " ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << " ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    std::cout << " ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    this->checkExecution(executor);
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << _target + "_shrubbery" << std::endl;
        return;
    }
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_ " << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile.close();
    
}