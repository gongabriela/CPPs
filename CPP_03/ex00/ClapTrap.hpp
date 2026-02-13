/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:23:43 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/07 09:23:43 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
    private:
        std::string _name;
        unsigned int _hitPoints; //(10)
        unsigned int _energyPoints; //(10)
        unsigned int _attackDamage; //(0)

    public: 
        ClapTrap();
        ClapTrap(const std::string& name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target); // causes its target to lose attack damage hit points.
        void takeDamage(unsigned int amount);  //receives the damage
        void beRepaired(unsigned int amount); //regains the amount of hit points
};

#endif