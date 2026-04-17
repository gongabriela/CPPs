/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:50:02 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/26 16:50:02 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <string>

class Dog : public Animal {
    public:
        Dog();
        Dog(const std::string& type);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        ~Dog();

        virtual void makeSound() const;

};

#endif