/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:07:46 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 18:07:46 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon;
    public: 
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        void attack() const;
};

#endif

/*
    • While HumanA takes the Weapon in its constructor, HumanB does not.
    • HumanB may not always have a weapon, whereas HumanA will always be
      armed.
    EXPLANATION
    HumanA:
    -> Always has a weapon (never null/uninitialized)
    -> Takes Weapon in constructor: HumanA(std::string name, Weapon& weapon)
    -> Should store weapon as a reference (Weapon& weapon)
    -> Use initialization list to initialize the reference
    HumanB:
    -> May or may not have a weapon (optional)
    -> Constructor doesn't take a weapon: HumanB(std::string name)
    -> Needs a setWeapon() method to assign weapon later
    -> Should store weapon as a pointer (Weapon* weapon)
    -> Initialize pointer to NULL in constructor

*/