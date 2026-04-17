/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:53:33 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/29 14:53:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    private:
        // OCF 
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        // Detectors
        static bool isPseudoLiteral(const std::string& literal);
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isValidFloatingPoint(const std::string& literal, bool mustBeFloat);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);

        // Printers
        static void printPseudo(const std::string& literal);
        static void printChar(double val);
        static void printInt(double val);
        static void printFloat(double val);
        static void printDouble(double val);

    public:
        static void convert(const std::string& literal);
};

#endif