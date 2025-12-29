/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 00:02:25 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/27 00:02:25 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error: missing parameters" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty() || s1.empty()) {
        std::cerr << "Error: empty parameters" << std::endl;
        return 1;
    }

    return (replace(filename, s1, s2));
}

