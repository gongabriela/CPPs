/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:48:59 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/20 16:00:09 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
    
    std::cout << "--- [1] BASIC TESTS ---" << std::endl;
    
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "Porto";
    std::cout << "String array size: " << strArray.size() << std::endl;
    std::cout << "String array content: " << strArray[0] << " " << strArray[1] << " " << strArray[2] << std::endl;

    std::cout << "\n--- [2] DEEP COPY & MIRROR TEST ---" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    std::cout << "Deep copy and memory mirror test completed." << std::endl;
    std::cout << "Validating mirror integrity after scope destruction:" << std::endl;
    bool isMirrorValid = true;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "[ERROR] Data corruption: didn't save the same value!!" << std::endl;
            isMirrorValid = false;
            return 1;
        }
    }
    if (isMirrorValid) {
        std::cout << "[SUCCESS] Deep copy and memory mirror validated." << std::endl;
    }

    std::cout << "\n--- [3] EXCEPTIONS TEST ---" << std::endl;
    
    try {
        numbers[-2] = 0;
        std::cout << "[ERROR] Exception not thrown for index -2!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "[SUCCESS] Caught invalid index (-2): " << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
        std::cout << "[ERROR] Exception not thrown for MAX_VAL index!" << std::endl;
    }
    catch(const std::exception& e) {
        std::cout << "[SUCCESS] Caught invalid index (MAX_VAL): " << e.what() << '\n';
    }
    
    delete [] mirror;
    
    std::cout << "\nAll tests passed successfully." << std::endl;
    return 0;
}
