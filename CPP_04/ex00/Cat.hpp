/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:29:00 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/11 09:29:00 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

class Cat : public Animal {
public:
    Cat();
    Cat(const std::string& type);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

   virtual void makeSound() const;
};

#endif