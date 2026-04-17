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
    // ISSO AQUI TEM QUE DAR ERRO DE COMPILAÇÃO:
    //Animal* a = new Animal(); 
    
    // ISSO AQUI TEM QUE FUNCIONAR NORMALMENTE:
    Animal* b = new Dog();
    
    //delete a;
    delete b;
    return 0;
}