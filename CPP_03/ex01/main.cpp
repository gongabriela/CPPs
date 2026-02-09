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
#include "ScavTrap.hpp"

int main() {
    std::cout << "### TESTE 1: CONSTRUTOR E CADEIA DE HERANÇA ###" << std::endl;
    {
        // Criação na Stack: Deve chamar ClapTrap Construtor -> ScavTrap Construtor
        ScavTrap robot("Serena");
        
        std::cout << "\n--- Testando Atributos e Métodos ---" << std::endl;
        // Deve imprimir: "ScavTrap Serena attacks..." (Dano 20)
        robot.attack("Inimigo"); 
        
        // Deve usar a função do pai (ClapTrap), mas com HP 100
        robot.takeDamage(10); 
        robot.beRepaired(10); 

        // Função exclusiva do ScavTrap
        robot.guardGate();
        
        std::cout << "\n--- Fim do Escopo (Destruição) ---" << std::endl;
        // Aqui deve chamar: ScavTrap Destructor -> ClapTrap Destructor
    }

    std::cout << "\n\n### TESTE 2: FORMA CANÔNICA (CÓPIA E ATRIBUIÇÃO) ###" << std::endl;
    {
        ScavTrap original("Original");
        
        std::cout << "\n[Copiando...]" << std::endl;
        ScavTrap copia(original); // Copy Constructor
        
        std::cout << "\n[Atribuindo...]" << std::endl;
        ScavTrap atribuido("Temp");
        atribuido = original; // Copy Assignment Operator
        
        std::cout << "\n--- Destruindo as cópias ---" << std::endl;
    }

    std::cout << "\n\n### TESTE 3: POLIMORFISMO (O TESTE DO DESTRUTOR VIRTUAL) ###" << std::endl;
    std::cout << "Se o destrutor do ClapTrap nao for virtual, o ScavTrap vaza memoria aqui!" << std::endl;
    {
        // Ponteiro de ClapTrap apontando para ScavTrap
        ClapTrap* ptr = new ScavTrap("HeapRobot");
        
        // O ataque aqui vai chamar o do ClapTrap se não for virtual, 
        // ou ScavTrap se attack for virtual (o subject não exige attack virtual, mas é bom saber)
        ptr->attack("Target"); 

        std::cout << "\n[Deletando via ponteiro base...]" << std::endl;
        delete ptr; // IMPORTANTE: Deve chamar ~ScavTrap e depois ~ClapTrap
    }

    return 0;
}