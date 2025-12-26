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

int main(void) {

    std::cout << "Creating a zombie in the heap: " << std::endl;
    Zombie *heapZombie = newZombie("Gabi");
    heapZombie->announce();
    delete heapZombie;
    
    std::cout << "Creating a zombie in the stack: " << std::endl;
    randomChump("StackZombie");
}