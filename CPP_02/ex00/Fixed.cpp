/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:11:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/01/15 21:11:30 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}