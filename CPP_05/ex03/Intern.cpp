/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:24:23 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/28 11:24:23 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other) {
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(Intern const &other) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    
    AForm *(Intern::*formCreators[])(std::string) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (size_t i = 0; i < (sizeof(formNames) / sizeof(formNames[0])); i++) {
        if (formName == formNames[i] && formCreators[i] != NULL) {
            std::cout << "Intern creates " << formName << " form" << std::endl; //APAGAR talvez usar exceptions 
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " form: unknown form name" << std::endl;
    return NULL;
}