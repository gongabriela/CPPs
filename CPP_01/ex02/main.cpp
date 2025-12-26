/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:51:21 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/26 16:51:21 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string> 
#include <iostream> 

int main(void) {

    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string&  stringREF = str;
    
    std::cout << "memory address of the string variable: " << &str << std::endl;
    std::cout << "memory adress held by stringPTR:       " << stringPTR << std::endl;
    std::cout << "memory adress held by stringREF:       " << &stringREF << std::endl;

    std::cout << "value of the string variable:          " << str << std::endl;
    std::cout << "value pointed to by stringPTR:         " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF:         " << stringREF << std::endl;
    
}

/*
    To save de address in c++, we put & in the declaration, not  in the assignilation (??? kkkk you know what i mean)
*/