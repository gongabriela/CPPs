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

int main(int argc, char **argv) {

    Harl Harl; 

    if (argc != 2) {
        std::cout << "invalid parameters" << std::endl;
        return 1;
    }
    Harl.complain(argv[1]);

    return 0;
}