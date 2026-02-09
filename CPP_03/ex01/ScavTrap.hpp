/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 10:49:53 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/09 10:49:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
    public: 
        ScavTrap(); //default constructor
        ScavTrap(const std::string &name); //default constructor com o nome
        ScavTrap(const ScavTrap &other); //copy constructor
        ScavTrap &operator=(const ScavTrap &other); //copy assignment operator overload
        ~ScavTrap(); //destructor

        void attack(const std::string &target); //attack()
        void guardGate(); //enters Gate keeper mode. In this mode, the ScavTrap will be able to guard a gate against intruders.
};

#endif