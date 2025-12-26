/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:24:03 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 15:24:03 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*This function creates a zombie, names it, and returns it so you can use it 
outside of the function scope*/
Zombie* newZombie(std::string name) {
    Zombie* ret = new Zombie;
    ret->setName(name);
    return ret;
}

/* MALLOC VS NEW
    Tanto o malloc quanto o new alocam memoria na heap, mas o new para alem disso
    tb chama o construtor da classe.

*/