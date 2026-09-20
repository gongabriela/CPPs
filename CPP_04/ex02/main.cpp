/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:01:32 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/11 10:01:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    //This will give compilation errrors
    Animal* a = new Animal(); 
    
    //This will not give compilation errors
    Animal* b = new Dog();
    
    //delete a;
    delete b;
    return 0;
}