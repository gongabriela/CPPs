/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 08:00:47 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/24 08:03:47 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "         TESTING MUTANTSTACK            " << std::endl;
    std::cout << "========================================" << std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator i = mstack.begin();
    MutantStack<int>::iterator j = mstack.end();
    
    ++i;
    --i;
    
    std::cout << "\nIterating through MutantStack:" << std::endl;
    while (i != j) {
        std::cout << *i << std::endl;
        ++i;
    }
    
    std::stack<int> s(mstack);

    std::cout << "\n========================================" << std::endl;
    std::cout << "          TESTING STD::LIST             " << std::endl;
    std::cout << "========================================" << std::endl;
    
    std::list<int> mlist;
    
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Top element: " << mlist.back() << std::endl;
    
    mlist.pop_back();
    
    std::cout << "Size after pop: " << mlist.size() << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator li = mlist.begin();
    std::list<int>::iterator lj = mlist.end();
    
    ++li;
    --li;
    
    std::cout << "\nIterating through std::list:" << std::endl;
    while (li != lj) {
        std::cout << *li << std::endl;
        ++li;
    }

    return 0;
}