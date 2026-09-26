/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 07:28:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/22 08:21:22 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include "easyfind.hpp"

int main() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "       TESTING WITH STD::VECTOR         " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(50);

    try {
        std::cout << "Searching for 30 in vector..." << std::endl;
        std::vector<int>::iterator it = easyfind(myVector, 30);
        std::cout << "[SUCCESS] Value found: " << *it << std::endl;

        std::cout << "Searching for 99 in vector..." << std::endl;
        it = easyfind(myVector, 99);
        std::cout << "[SUCCESS] Value found: " << *it << std::endl; // Should not execute
    } 
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "        TESTING WITH STD::LIST          " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::list<int> myList;
    myList.push_back(42);
    myList.push_back(21);
    myList.push_back(84);
    myList.push_back(100);

    try {
        std::cout << "Searching for 21 in list..." << std::endl;
        std::list<int>::iterator it = easyfind(myList, 21);
        std::cout << "[SUCCESS] Value found: " << *it << std::endl;

        std::cout << "Searching for -5 in list..." << std::endl;
        it = easyfind(myList, -5);
        std::cout << "[SUCCESS] Value found: " << *it << std::endl; // Should not execute
    } 
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "          TESTING EMPTY CONTAINER       " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    std::vector<int> emptyVector;

    try {
        std::cout << "Searching for 1 in an empty vector..." << std::endl;
        std::vector<int>::iterator it = easyfind(emptyVector, 1);
        std::cout << "[SUCCESS] Value found: " << *it << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Exception caught: " << e.what() << std::endl;
    }

    return 0;
}