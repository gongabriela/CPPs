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
    protected:
        std::string _name; //name
        unsigned int _hitPoints; //hit points (10)
        unsigned int _energyPoints; //energy points (10)
        unsigned int _attackDamage; //attack damage (0)

    public: 
        ClapTrap();//default constructor
        ClapTrap(const std::string& name);//default constructor
        ClapTrap(const ClapTrap& other);//copy constructor
        ClapTrap& operator=(const ClapTrap& other);//copy assingment operator overload
        virtual ~ClapTrap();//default destructor

        void attack(const std::string& target); // causes its target to lose attack damage hit points.
        void takeDamage(unsigned int amount);  //receives the damage
        void beRepaired(unsigned int amount); //regains the amount of hit points
};

#endif