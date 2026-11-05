/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 20:27:05 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/02 07:37:01 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return -1;
    }
    
    try {
        BitcoinExchange btc(argv[1]);
        btc.readInputFile();
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    
    return 0;
}