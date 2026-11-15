/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 06:29:50 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/03 06:58:30 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Entry point of the `RPN` program.
 *
 * Usage: `./RPN "<expression>"`. Evaluates the Reverse Polish Notation
 * expression and prints the result on stdout, or `Error` on stderr if the
 * expression is invalid.
 *
 * @param argc Number of arguments (must be 2).
 * @param argv Arguments; `argv[1]` is the expression.
 * @return 0 on success, 1 on error.
 */
int main (int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn(argv[1]);
        int result = rpn.calculate();
        std::cout << result << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
