/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 07:12:51 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/24 07:13:20 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    std::cout << "--- SUBJECT TEST ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- EXCEPTION TEST: ADDING OVER CAPACITY ---" << std::endl;
    try {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "[SUCCESS] Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- EXCEPTION TEST: NOT ENOUGH NUMBERS ---" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "[SUCCESS] Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- PERFORMANCE TEST: 15,000 NUMBERS (addNumbersFromRange) ---" << std::endl;
    try {
        Span bigSpan(15000);
        std::vector<int> randomNumbers;
        
        std::srand(std::time(NULL));
        for (int i = 0; i < 15000; i++) {
            randomNumbers.push_back(std::rand()); // Generate random numbers
        }
        
        // Add all numbers in a single call using iterators
        bigSpan.addNumbersFromRange(randomNumbers.begin(), randomNumbers.end());
        
        std::cout << "15,000 numbers added successfully!" << std::endl;
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- FLEXIBILITY TEST: DIFFERENT ITERATOR TYPE (std::list) ---" << std::endl;
    try {
        Span listSpan(5);
        std::list<int> myList;
        myList.push_back(100);
        myList.push_back(200);
        myList.push_back(300);

        listSpan.addNumbersFromRange(myList.begin(), myList.end());
        std::cout << "Numbers from std::list added successfully!" << std::endl;
        std::cout << "Shortest span: " << listSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << listSpan.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}