/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:47:51 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/20 15:54:01 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

class Awesome {
    private:
        int _n;
    public:
        Awesome(void) : _n(0) {}
        Awesome(int n) : _n(n) {}
        
        // Overload of comparison operators essential for min and max to work
        bool operator==(Awesome const & rhs) const { return (this->_n == rhs._n); }
        bool operator!=(Awesome const & rhs) const { return (this->_n != rhs._n); }
        bool operator>(Awesome const & rhs) const { return (this->_n > rhs._n); }
        bool operator<(Awesome const & rhs) const { return (this->_n < rhs._n); }
        bool operator>=(Awesome const & rhs) const { return (this->_n >= rhs._n); }
        bool operator<=(Awesome const & rhs) const { return (this->_n <= rhs._n); }
        
        int getN() const { return _n; }
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) {
    o << a.getN();
    return o;
}

int main(void) {
    std::cout << "--- Mandatory Subject Tests ---" << std::endl;
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

    std::cout << "\n--- Custom Class Test (Awesome) ---" << std::endl;
    Awesome awe1(42);
    Awesome awe2(21);

    ::swap(awe1, awe2);
    std::cout << "awe1 (should be 21) = " << awe1 << std::endl;
    std::cout << "awe2 (should be 42) = " << awe2 << std::endl;

    std::cout << "Max between awe1 and awe2: " << ::max(awe1, awe2) << std::endl;
    std::cout << "Min between awe1 and awe2: " << ::min(awe1, awe2) << std::endl;

    return 0;
}