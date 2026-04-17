/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:19:50 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/04/08 08:19:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator using the current time.
    // This ensures we get different results every time we run the program.
    std::srand(std::time(NULL));

    std::cout << "---------------------------------------" << std::endl;
    std::cout << "      TESTING RUN-TIME TYPE INFO       " << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    for (int i = 1; i <= 5; ++i) {
        std::cout << "\n[ --- TEST " << i << " --- ]" << std::endl;
        
        // 1. Generate a random object
        Base* randomObject = generate();

        // 2. Test identification via pointer
        identify(randomObject);

        // 3. Test identification via reference
        // We dereference the pointer (*randomObject) to pass it as a reference
        identify(*randomObject);

        // 4. Clean up memory to avoid leaks
        delete randomObject;
    }

    std::cout << "\n---------------------------------------" << std::endl;
    return 0;
}