/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:24:33 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 15:24:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
This function creates a zombie, names it, and makes it announce itself.
*/
void randomChump(std::string name) {
    Zombie zombie;
    zombie.setName(name);
    zombie.announce();
}
