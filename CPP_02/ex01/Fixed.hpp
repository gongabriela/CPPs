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
        int _fixedPointValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &src);
        Fixed& operator=(const Fixed &rhs);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        
        float   toFloat(void) const;
        int     toInt(void) const;

}; 

std::ostream& operator<<(std::ostream &out, const Fixed &fixed); 

#endif