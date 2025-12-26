/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:38:21 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 10:38:21 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {

    int nbr = 10;
    std::string name = "gabi";
    std::cout << "Creating a zombie horde: " << std::endl;
    Zombie *horde = zombieHorde(nbr, name);
    for (int i = 0; i < nbr; i++)
        horde[i].announce();

    std::cout << "Deleting the horde. . ." << std::endl;
    delete[] horde;
}