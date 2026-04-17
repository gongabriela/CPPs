/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 10:11:29 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/20 10:11:29 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
    std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Parameterized Form constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Copy Form constructor called" << std::endl;
}

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form Name: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Grade to Sign: " << form.getGradeToSign() << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}

void AForm::checkExecution(Bureaucrat const &executor) const {
    if (!this->_isSigned) {
        throw AForm::NotSignedException();
    }
    if (executor.getGrade() > this->_gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
}