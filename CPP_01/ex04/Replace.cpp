/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:23:31 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/29 13:23:31 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

bool getFileContent(const std::string& filename, std::string& fileContent) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Input file cannot be opened." << std::endl;
        return false;
    }
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    fileContent = buffer.str();
    return true;
}

int    replace(const std::string& filename, const std::string& s1, const std::string& s2) 
{
    std::string fileContent; 

    if (!getFileContent(filename, fileContent))
        return 1;
    size_t pos = 0; 
    while (true) {
        pos = fileContent.find(s1, pos);
        if (pos == std::string::npos)
            break ;
        fileContent.erase(pos, s1.length());
        fileContent.insert(pos, s2);
        pos += s2.length();
    }
    return (createOutfile(filename, fileContent));
}

int createOutfile(const std::string& filename, const std::string& buffer) {
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error opening outfile." << std::endl;
        return 1;
    }
    outputFile << buffer;
    return 0;
}