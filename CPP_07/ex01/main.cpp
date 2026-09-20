/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:07:17 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/20 16:18:13 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"


class sampleClass {
    private:
        int _n;
    public:
        sampleClass(void) : _n(42) { return; }
        int get(void) const { return this->_n; }
};

std::ostream & operator<<(std::ostream & o, sampleClass const & rhs) {
    o << rhs.get();
    return o;
}

void multiplyByTwo(int& n) { n *= 2; }
void printInt(const int& n) { std::cout << n << " "; }
void printString(const std::string& str) { std::cout << str << " "; }

template <typename T>
void printTemplate(const T& element) {
    std::cout << element << std::endl;
}

int main() {
    std::cout << "--- TEST 1: Array  ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    std::cout << "> Original: " << std::endl;
    ::iter(intArray, intLen, printTemplate<int>);
    std::cout << "\n> Multiplied: \n";
    ::iter(intArray, intLen, multiplyByTwo);
    ::iter(intArray, intLen, printTemplate<int>);
    
    std::cout << "\n\n--- TEST 2: Const String Array (Read-only) ---" << std::endl;
    const std::string strArray[] = {"Hello", "World", "from", "42", "school"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
    std::cout << "> Strings: \n";
    ::iter(strArray, strLen, printTemplate<std::string>);

    std::cout << "\n--- TEST 3: objects sampleClass ---" << std::endl;
    sampleClass sampleArray[5];
    ::iter(sampleArray, 5, printTemplate<sampleClass>);
    std::cout << std::endl;
    return 0;
}
