/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:23:30 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/02/07 09:23:30 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp" // Opcional: Inclua se quiser comparar os dois irmãos

int main() {
    std::cout << "\n===============================================" << std::endl;
    std::cout << "         TESTE 1: NASCIMENTO DO FRAGTRAP        " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        // Deve chamar: ClapTrap Constructor -> FragTrap Constructor
        std::cout << "\n[Criando FragTrap 'Grenade']" << std::endl;
        FragTrap frag("Grenade");

        std::cout << "\n[Verificando Status Iniciais]" << std::endl;
        // HP: 100, EP: 100, AD: 30
        // Vamos gastar energia e atacar para provar os valores
        
        frag.attack("Target Dummy"); 
        // OBS: Se você não sobrescreveu attack(), vai aparecer "ClapTrap... causing 30 damage".
        // O importante aqui é o DANO ser 30!

        frag.takeDamage(20); // HP cai para 80
        frag.beRepaired(10); // HP volta para 90, EP cai para 99
        
        std::cout << "\n[Testando Habilidade Especial]" << std::endl;
        frag.highFivesGuys(); // Deve imprimir a mensagem positiva
        
        std::cout << "\n[Destruindo 'Grenade']" << std::endl;
        // Deve chamar: FragTrap Destructor -> ClapTrap Destructor
    }

    std::cout << "\n===============================================" << std::endl;
    std::cout << "      TESTE 2: COPY E ASSIGNMENT (CANÔNICA)     " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        std::cout << "\n[Criando Original]" << std::endl;
        FragTrap original("Original");
        
        std::cout << "\n[Criando Cópia (Copy Constructor)]" << std::endl;
        FragTrap copia(original);
        
        std::cout << "\n[Atribuindo (Assignment Operator)]" << std::endl;
        FragTrap atribuido("Temp");
        atribuido = original;
        
        std::cout << "\n[Modificando a Cópia (Teste de Deep Copy)]" << std::endl;
        copia.highFivesGuys(); // A cópia funciona?
        
        std::cout << "\n[Destruindo tudo]" << std::endl;
    }

    std::cout << "\n===============================================" << std::endl;
    std::cout << "     TESTE 3: POLIMORFISMO E VIRTUAL DESTRUCTOR  " << std::endl;
    std::cout << "===============================================" << std::endl;
    {
        std::cout << "\n[Alocando FragTrap via ponteiro de ClapTrap]" << std::endl;
        ClapTrap* ptr = new FragTrap("HeapFrag");

        std::cout << "\n[Usando polimorfismo]" << std::endl;
        ptr->attack("Air"); // Vai usar o attack do ClapTrap (se não for virtual) ou FragTrap
        
        // Tentar chamar highFivesGuys() aqui daria erro, 
        // pois o ponteiro é ClapTrap e ele não conhece essa função.
        
        std::cout << "\n[Deletando Ponteiro]" << std::endl;
        delete ptr; 
        // CRUCIAL: Deve aparecer ~FragTrap e depois ~ClapTrap.
        // Se aparecer só ~ClapTrap, seu destrutor virtual no pai falhou.
    }

    return 0;
}