/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:13:42 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 17:13:42 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
    private:
        std::string type;
    public:
        Weapon(const std::string& type);
        ~Weapon();
        const std::string& getType() const;
        void    setType(const std::string& value);
};

#endif