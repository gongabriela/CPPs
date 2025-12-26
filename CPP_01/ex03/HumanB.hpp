/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:13:53 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 18:13:53 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(const std::string& name);
        ~HumanB();
        void    setWeapon(Weapon& weapon);
        void attack() const;
};

#endif