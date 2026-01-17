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

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    //*this = src; (nao entendi como esta sintaxe funciona)
    //ou copiar manualmente 
}

Fixed::Fixed &operator=(const Fixed &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    //verifica se nao e auto-atribuicao
    //copia getrawbits do rhs pro fixedpointvalue
    //retorna *this
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    //return this->
}

void    Fixed::setRawBits(int const raw) {

}