/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:53:03 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/07 13:53:11 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/**
 * @brief Entry point of the `PmergeMe` program.
 *
 * Usage: `./PmergeMe <n1> <n2> ...`. Sorts the sequence of positive integers
 * with the Ford-Johnson algorithm, in both `std::vector` and `std::deque`, and
 * prints the time taken by each.
 *
 * @param argc Number of arguments (at least 2).
 * @param argv Arguments; from `argv[1]` on, the numbers to sort.
 * @return 0 on success, 1 on error.
 */
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.process(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
