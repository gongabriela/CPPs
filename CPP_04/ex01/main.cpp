/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:01:32 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/11 10:01:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "\n========== PART 1: ARRAY TEST (PDF) ==========" << std::endl;
    const int arraySize = 6;
    const Animal* animals[arraySize];

    std::cout << "\n--- Filling the Array (Half Dog, Half Cat) ---" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        if (i < arraySize / 2) {
            std::cout << "Creating Dog " << i << ":" << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "Creating Cat " << i << ":" << std::endl;
            animals[i] = new Cat();
        }
    }

    std::cout << "\n--- Deleting the Array ---" << std::endl;
    // Testing for memory leaks. 
    // Virtual destructors should call ~Dog/~Cat first, then ~Animal.
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }


    std::cout << "\n\n========== PART 2: DEEP COPY TEST ==========" << std::endl;
    
    std::cout << "\n--- Testing Copy Constructor ---" << std::endl;
    Dog dogOriginal;
    dogOriginal.setBrainIdea(0, "I want a giant bone!");
    dogOriginal.setBrainIdea(1, "I'm going to bark at the mailman.");
    
    Dog dogCopy(dogOriginal); // Using the copy constructor
    
    std::cout << "\nOriginal's Idea 0: " << dogOriginal.getBrainIdea(0) << std::endl;
    std::cout << "Copy's Idea 0:     " << dogCopy.getBrainIdea(0) << std::endl;
    
    std::cout << "\nChanging the Copy's idea..." << std::endl;
    dogCopy.setBrainIdea(0, "I changed my mind, I want to sleep.");
    
    std::cout << "Original's Idea 0: " << dogOriginal.getBrainIdea(0) << " (Must remain the same!)" << std::endl;
    std::cout << "Copy's Idea 0:     " << dogCopy.getBrainIdea(0) << " (Must change!)" << std::endl;


    std::cout << "\n--- Testing Assignment Operator ---" << std::endl;
    Cat catA;
    Cat catB;
    
    catA.setBrainIdea(0, "I'm going to knock the cup off the table.");
    std::cout << "\nCopying CatA to CatB using the '=' operator..." << std::endl;
    catB = catA; 
    
    std::cout << "CatA's Idea 0: " << catA.getBrainIdea(0) << std::endl;
    std::cout << "CatB's Idea 0: " << catB.getBrainIdea(0) << std::endl;
    
    std::cout << "\nChanging CatB's idea..." << std::endl;
    catB.setBrainIdea(0, "I'm going to scratch the sofa.");
    
    std::cout << "CatA's Idea 0: " << catA.getBrainIdea(0) << std::endl;
    std::cout << "CatB's Idea 0: " << catB.getBrainIdea(0) << std::endl;

    std::cout << "\n--- Final destruction (Leaving main scope) ---" << std::endl;
    return 0;
}