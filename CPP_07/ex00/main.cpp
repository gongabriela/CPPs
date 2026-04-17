/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 13:50:58 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/04/08 14:26:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

class Awesome {
  public:
    Awesome(void) : _n(0) {}
    Awesome(int n) : _n(n) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
    bool operator!=(Awesome const & rhs) const{ return (this->_n != rhs._n); }
    bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
    bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
    bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
    bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};

// Sobrecarga do operador << para podermos imprimir a classe Awesome no cout
std::ostream & operator<<(std::ostream & o, const Awesome &a) { 
    o << a.get_n(); 
    return o; 
}

int main( void ) {

    std::cout << "------------------ SUBJECT MAIN ------------------" << std::endl;
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "\n------------------ AWESOME CLASS TEST ------------------" << std::endl;
    Awesome awe1(2), awe2(4);

    ::swap(awe1, awe2);
    std::cout << "awe1 = " << awe1 << ", awe2 = " << awe2 << std::endl;
    std::cout << "min( awe1, awe2 ) = " << ::min(awe1, awe2) << std::endl;
    std::cout << "max( awe1, awe2 ) = " << ::max(awe1, awe2) << std::endl;

    return 0;
}