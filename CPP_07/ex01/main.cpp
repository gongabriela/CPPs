/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:07:17 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/04/08 15:42:29 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

void multiplyByTwo(int& n) {
    n *= 2;
}

void printInt(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

template <typename T>
void printTemplate(const T& element) {
    std::cout << element << " (via template) ";
}

int main() {
    std::cout << "--- TEST 1: Pointer Array  ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original: ";
    ::iter(intArray, intLen, printInt);
    std::cout << "\nMultiplied: ";
    ::iter(intArray, intLen, multiplyByTwo);
    ::iter(intArray, intLen, printInt);
    
    std::cout << "\n\n--- TEST 2: Const String Array (Read-only) ---" << std::endl;
    const std::string strArray[] = {"Ola", "Mundo", "da", "Escola", "42"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Strings: ";
    ::iter(strArray, strLen, printString); // compiler chooses the const version of iter() for this array
    // ::iter(strArray, strLen, multiplyByTwo); // will give compilation errors
    

    std::cout << "\n\n--- TEST 3: Using Template Function ---" << std::endl;
    
    ::iter(intArray, intLen, printTemplate<int>);
    
    std::cout << std::endl;

    return 0;
}
