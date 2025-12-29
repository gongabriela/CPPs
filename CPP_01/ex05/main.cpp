/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:43:53 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/29 14:43:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {

    Harl Harl; 

    std::cout << "--- TESTING VALID LEVELS ---" << std::endl;

    std::cout << "[ DEBUG ]" << std::endl;
    Harl.complain("DEBUG");

    std::cout << "[ INFO ]" << std::endl;
    Harl.complain("INFO");

    std::cout << "[ WARNING ]" << std::endl;
    Harl.complain("WARNING");

    std::cout << "[ ERROR ]" << std::endl;
    Harl.complain("ERROR");

    std::cout << "--- TESTING INVALID LEVELS ---" << std::endl;

    std::cout << "Trying to complain about Picanha: " << std::endl;
    Harl.complain("Picanha");

    std::cout << "Trying to complaing with an empty string: " << std::endl;
    Harl.complain("");

    std::cout << "--- END OF THE TESTS ---" << std::endl;

    return 0;
}