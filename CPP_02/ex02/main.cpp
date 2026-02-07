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
    // ==========================================================
    // INICIO DA MAIN DO SUBJECT
    // ==========================================================
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


    // ==========================================================
    // INICIO DOS MEUS TESTES (ROBUSTOS)
    // ==========================================================
    std::cout << "========= EXTRA ROBUST TESTS =========" << std::endl;

    std::cout << "--- Testes de Comparação ---" << std::endl;
    Fixed const c( 10 );
    Fixed const d( 20 );
    std::cout << "c (10) < d (20)  : " << (c < d) << " (esperado: 1)" << std::endl;
    std::cout << "c (10) > d (20)  : " << (c > d) << " (esperado: 0)" << std::endl;
    std::cout << "c (10) == c (10) : " << (c == c) << " (esperado: 1)" << std::endl;

    std::cout << "\n--- Testes de Aritmética Avançada ---" << std::endl;
    Fixed e( 2.5f );
    Fixed f( 2 );
    std::cout << "2.5 + 2 = " << (e + f) << std::endl;
    std::cout << "2.5 - 2 = " << (e - f) << std::endl;
    std::cout << "2.5 * 2 = " << (e * f) << std::endl;
    std::cout << "2.5 / 2 = " << (e / f) << std::endl;

    std::cout << "\n--- Testes de Decremento ---" << std::endl;
    Fixed g( 1 );
    std::cout << "g inicial: " << g << std::endl;
    std::cout << "--g      : " << --g << std::endl;
    std::cout << "g--      : " << g-- << std::endl;
    std::cout << "g final  : " << g << std::endl;

    std::cout << "\n--- Testes de Min/Max Estáticos ---" << std::endl;
    // Testando com referências constantes
    std::cout << "min(c, d) : " << Fixed::min( c, d ) << std::endl;
    // Testando com referências não-constantes
    Fixed i( 500 );
    Fixed j( 1000 );
    std::cout << "max(i, j) : " << Fixed::max( i, j ) << std::endl;

    std::cout << "\n--- Teste de Encadeamento (Referência) ---" << std::endl;
    Fixed k( 0 );
    std::cout << "k antes de ++++++k: " << k << std::endl;
    ++++++k;
    std::cout << "k depois de ++++++k: " << k << " (deve ser 3 * epsilon)" << std::endl;

    std::cout << "========= END OF EXTRA TESTS =========" << std::endl;

    return 0;
}