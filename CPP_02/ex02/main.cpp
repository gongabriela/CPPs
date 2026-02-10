/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:11:57 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/01/15 21:11:57 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    std::cout << "========= SUBJECT TESTS =========" << std::endl;
    
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;         // 0
    std::cout << ++a << std::endl;       // 0.00390625
    std::cout << a << std::endl;         // 0.00390625
    std::cout << a++ << std::endl;       // 0.00390625
    std::cout << a << std::endl;         // 0.0078125

    std::cout << b << std::endl;         // 10.1016

    std::cout << Fixed::max( a, b ) << std::endl; // 10.1016

    std::cout << "========= END OF SUBJECT TESTS =========" << std::endl << std::endl;

    std::cout << "========= EXTRA ROBUST TESTS =========" << std::endl;

    std::cout << "--- Comparation tests ---" << std::endl;
    Fixed const c( 10 );
    Fixed const d( 20 );
    std::cout << "c (10) < d (20)  : " << (c < d) << " (expected: 1)" << std::endl;
    std::cout << "c (10) > d (20)  : " << (c > d) << " (expected: 0)" << std::endl;
    std::cout << "c (10) == c (10) : " << (c == c) << " (expected: 1)" << std::endl;

    std::cout << "\n--- Advanced Arithmetic Tests ---" << std::endl;
    Fixed e( 2.5f );
    Fixed f( 2 );
    std::cout << "2.5 + 2 = " << (e + f) << std::endl;
    std::cout << "2.5 - 2 = " << (e - f) << std::endl;
    std::cout << "2.5 * 2 = " << (e * f) << std::endl;
    std::cout << "2.5 / 2 = " << (e / f) << std::endl;

    std::cout << "\n--- Decrement Tests ---" << std::endl;
    Fixed g( 1 );
    std::cout << "g inicial: " << g << std::endl;
    std::cout << "--g      : " << --g << std::endl;
    std::cout << "g--      : " << g-- << std::endl;
    std::cout << "g final  : " << g << std::endl;

    std::cout << "\n--- Static Min/Max Tests ---" << std::endl;
    // Testing with constant references
    std::cout << "min(c, d) : " << Fixed::min( c, d ) << std::endl;
    // Testing with non-constant references
    Fixed i( 500 );
    Fixed j( 1000 );
    std::cout << "max(i, j) : " << Fixed::max( i, j ) << std::endl;

    std::cout << "\n--- Chaining Test (Reference) ---" << std::endl;
    Fixed k( 0 );
    std::cout << "k before ++++++k: " << k << std::endl;
    ++++++k;
    std::cout << "k after ++++++k: " << k << " (should be 3 * epsilon)" << std::endl;

    std::cout << "========= END OF EXTRA TESTS =========" << std::endl;

    return 0;
}