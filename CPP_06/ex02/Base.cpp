/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:19:01 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/04/08 09:09:10 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <exception>

/**
 * @brief Standard virtual destructor.
 * * Absolutely necessary to make the Base class polymorphic.
 * Without a virtual method, the compiler does not generate the virtual function table (vtable),
 * RTTI (Run-Time Type Information) fails, and dynamic_cast cannot be used.
 */
Base::~Base() {}

/**
 * @brief Randomly instantiates one of the derived classes (A, B, or C).
 * * Uses std::rand() to generate a pseudo-random number between 0 and 2.
 * Dynamically allocates the corresponding class on the Heap based on the result.
 * * @return Base* A pointer to the new instance, hiding its true identity under the Base type.
 */
Base* generate(void) {
    // Generate a random number between 0 and 2
    int randomValue = std::rand() % 3;

    if (randomValue == 0) {
        std::cout << "Factory generated an instance of class: A" << std::endl;
        return new A();
    } else if (randomValue == 1) {
        std::cout << "Factory generated an instance of class: B" << std::endl;
        return new B();
    } else {
        std::cout << "Factory generated an instance of class: C" << std::endl;
        return new C();
    }
}

/**
 * @brief Identifies the real type of the object using a pointer.
 * * Attempts to cast the Base pointer to the derived types A*, B*, or C*.
 * If the conversion fails, dynamic_cast catches the error silently and returns NULL,
 * allowing the program to test the next type in the if-else chain.
 * * @param p Pointer to the polymorphic object to be evaluated. Can be NULL.
 */
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Pointer identified as: NULL pointer" << std::endl;
        return;
    }

    if (dynamic_cast<A*>(p)) {
        std::cout << "Pointer identified as: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Pointer identified as: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Pointer identified as: C" << std::endl;
    } else {
        std::cout << "Pointer identified as: Unknown Type" << std::endl;
    }
}

/**
 * @brief Identifies the real type of the object using a reference.
 * * In C++, references cannot be NULL. Therefore, if dynamic_cast fails when trying
 * to convert to a derived reference, it throws an exception (std::bad_cast).
 * Uses try-catch blocks catching the generic std::exception class to discover
 * the identity without relying on the forbidden <typeinfo> header.
 * * @param p Reference to the polymorphic object to be evaluated.
 */             
void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Cast to void to prevent "unused variable" compilation error
        std::cout << "Reference identified as: A" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Reference identified as: B" << std::endl;
        return;
    } catch (std::exception& e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Reference identified as: C" << std::endl;
        return;
    } catch (std::exception& e) {}

    std::cout << "Reference identified as: Unknown Type" << std::endl;
}