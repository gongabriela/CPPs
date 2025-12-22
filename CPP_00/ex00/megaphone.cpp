/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:39:14 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 10:00:38 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//recebe string(s)
//passa TUDO pra toupper
//se nao tiver args printa msg especifica
#include <iostream>

int main(int argc, char **argv){
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE NOISE *" <<std::endl;
        return 0;
    }
    for (int i = 0; i < argc; i++) {
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)std::toupper(argv[i][j]);
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}