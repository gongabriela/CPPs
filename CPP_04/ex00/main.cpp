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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "\n========== MANDATORY PDF TESTS ==========" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n--- Checking Types ---" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    
    std::cout << "\n--- Checking Sounds (Polymorphism / Late Binding) ---" << std::endl;
    i->makeSound(); // Will output the cat sound!
    j->makeSound(); // Will output the dog sound!
    meta->makeSound(); // Will output the generic animal sound!

    std::cout << "\n--- Memory Cleanup (Virtual Destructors) ---" << std::endl;
    delete i;
    delete j;
    delete meta;

    std::cout << "\n\n========== WRONG ANIMAL TESTS ==========" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();

    std::cout << "\n--- Checking Types ---" << std::endl;
    std::cout << wrongI->getType() << " " << std::endl;

    std::cout << "\n--- Checking Sounds (No Polymorphism / Early Binding) ---" << std::endl;
    wrongI->makeSound(); // INTENTIONAL ERROR: Will output WrongAnimal sound!
    wrongMeta->makeSound();

    std::cout << "\n--- Memory Cleanup ---" << std::endl;
    delete wrongI;
    delete wrongMeta;

    return 0;
}