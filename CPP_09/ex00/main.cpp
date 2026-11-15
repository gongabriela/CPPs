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

/**
 * @brief Entry point of the `btc` program.
 *
 * Usage: `./btc <file>`. Converts every `date | value` line of the file into
 * its value in bitcoin, using the `data.csv` database.
 *
 * @param argc Number of arguments (must be 2).
 * @param argv Arguments; `argv[1]` is the path of the input file.
 * @return 0 on success, -1 if the file is missing or a fatal error occurs.
 */
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
