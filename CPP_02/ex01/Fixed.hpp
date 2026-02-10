/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:17:06 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/30 21:17:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class   Fixed {
    private:
        int _fixedPointValue; //rawbits
        static const int _fractionalBits = 8; //rep of the fract part of the fixed point number
    public:
        Fixed(); //default constructor
        Fixed(const int n);//constructor of an integer
        Fixed(const float f);//constructor of a float
        Fixed(const Fixed &src); //copy constructor
        Fixed& operator=(const Fixed &rhs); // copy assignment operator
        ~Fixed(); // destructor

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
        float   toFloat(void) const; //fixed to float
        int     toInt(void) const; //fixed to int

}; 

std::ostream& operator<<(std::ostream &out, const Fixed &fixed); //operator overload 

#endif