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
    std::cout << "2.5 * 0 = " << (e * f) << std::endl;
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
// std::cout << "\n========= ZERO & PRECISION TESTS =========" << std::endl;

//     Fixed z1(0);
//     Fixed z2(0.0f);
//     Fixed pos(42.5f);
//     Fixed neg(-42.5f);

//     std::cout << "--- 1. Construtores & Igualdade ---" << std::endl;
//     std::cout << "z1 (int 0)   : " << z1 << " (raw: " << z1.getRawBits() << ")" << std::endl;
//     std::cout << "z2 (float 0) : " << z2 << " (raw: " << z2.getRawBits() << ")" << std::endl;
//     std::cout << "z1 == z2     : " << (z1 == z2) << " (esperado: 1)" << std::endl;

//     std::cout << "\n--- 2. Multiplicação (O Aniquilador) ---" << std::endl;
//     // Qualquer coisa * 0 deve dar 0
//     Fixed res1 = pos * z1;
//     Fixed res2 = neg * z1;
//     Fixed res3 = z1 * z2; // 0 * 0

//     std::cout << "42.5 * 0     : " << res1 << " (esperado: 0)" << std::endl;
//     std::cout << "-42.5 * 0    : " << res2 << " (esperado: 0)" << std::endl;
//     std::cout << "0 * 0        : " << res3 << " (esperado: 0)" << std::endl;

//     std::cout << "\n--- 3. Divisão (0 no Numerador) ---" << std::endl;
//     // 0 divido por qualquer coisa deve ser 0
//     Fixed res4 = z1 / pos;
    
//     std::cout << "0 / 42.5     : " << res4 << " (esperado: 0)" << std::endl;
    
//     // CUIDADO: Não testes pos / z1 (Divisão por zero) se não tiveres proteção!
    
//     std::cout << "\n--- 4. Soma e Subtração Neutra ---" << std::endl;
//     std::cout << "42.5 + 0     : " << (pos + z1) << " (esperado: 42.5)" << std::endl;
//     std::cout << "42.5 - 0     : " << (pos - z1) << " (esperado: 42.5)" << std::endl;
//     std::cout << "0 - 42.5     : " << (z1 - pos) << " (esperado: -42.5)" << std::endl;
//     std::cout << "0 - 0        : " << (z1 - z2) << " (esperado: 0)" << std::endl;

//     std::cout << "\n--- 5. O Limite da Precisão (Epsilon) ---" << std::endl;
//     // O menor bit representável é 1/256 = 0.00390625
//     // O que acontece se passarmos um número menor que isso?
    
//     Fixed tiny(0.001f); // 0.001 é menor que 0.0039
    
//     std::cout << "Fixed(0.001f): " << tiny << std::endl;
//     std::cout << "Raw Bits     : " << tiny.getRawBits() << std::endl;
    
//     if (tiny.getRawBits() == 0)
//         std::cout << "-> DIAGNÓSTICO: O número foi arredondado para 0 (Perda de precisão esperada)." << std::endl;
//     else
//         std::cout << "-> DIAGNÓSTICO: O número sobreviveu (arredondou para cima)." << std::endl;

//     std::cout << "==========================================" << std::endl;
}