/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:19:50 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/20 13:19:08 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()

/**
 * @brief Usage of srand to seed the random number generator using the current
 * time. 
 * This ensures that we get different results every time we run the program.
 */
int main() {
    std::srand(std::time(NULL));

    for (int i = 1; i <= 5; ++i) {
        std::cout << "\n[ --- TEST " << i << " --- ]" << std::endl;
        
        Base* randomObject = generate();
        identify(randomObject);
        identify(*randomObject);
        delete randomObject;
    }
    std::cout << "\n---------------------------------------" << std::endl;
    return 0;
}