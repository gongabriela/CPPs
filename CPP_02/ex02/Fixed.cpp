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
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(f * (1 << _fractionalBits));
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
        _fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const raw) {
    //std::cout << "setRawBits member function called" << std::endl;
    _fixedPointValue = raw;
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)_fixedPointValue / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->getRawBits() != other.getRawBits();
}

Fixed   Fixed::operator+(const Fixed &other) const {
    Fixed ret;
    ret.setRawBits(this->getRawBits() + other.getRawBits());
    return ret;
}

Fixed   Fixed::operator-(const Fixed &other) const {
    Fixed ret;
    ret.setRawBits(this->getRawBits() - other.getRawBits());
    return ret;
}

Fixed   Fixed::operator*(const Fixed &other) const {
    Fixed ret;
    long temp = (long)this->getRawBits() * (long)other.getRawBits();
    ret.setRawBits((int)(temp >> _fractionalBits));
    return ret;
}

Fixed   Fixed::operator/(const Fixed &other) const {
    Fixed ret;
    long temp = long(this->getRawBits()) << _fractionalBits;
    temp /= other.getRawBits();
    ret.setRawBits(temp);
    return ret;
}

Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}   

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}