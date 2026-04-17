/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:54:18 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/29 14:54:18 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <cmath>

// -----------------------------------------------------------------------------
// OCF
// -----------------------------------------------------------------------------
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }   
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// -----------------------------------------------------------------------------
// Detectors
// -----------------------------------------------------------------------------
bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
            literal == "-inf" || literal == "+inf" || literal == "nan");
}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string& literal) {
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    if (i == literal.length()) 
        return false;
        
    for (; i < literal.length(); ++i) {
        if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

bool ScalarConverter::isValidFloatingPoint(const std::string& literal, bool mustBeFloat) {
    size_t literalLength = literal.length();
    if (literalLength == 0) return false;

    if (mustBeFloat) {
        if (literalLength < 2 || literal[literalLength - 1] != 'f') 
            return false;
        literalLength--;
    } else {
        if (literal[literalLength - 1] == 'f') 
            return false;
    }

    bool hasDot = false;
    bool hasDigit = false;
    size_t i = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

    for (; i < literalLength; i++) {
        if (literal[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } 
        else if (std::isdigit(literal[i])) {
            hasDigit = true;
        } 
        else {
            return false;
        }
    }
    return hasDigit && hasDot;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    return isValidFloatingPoint(literal, true);
}

bool ScalarConverter::isDouble(const std::string& literal) {
    return isValidFloatingPoint(literal, false);
}

// -----------------------------------------------------------------------------
// Printers for outputs
// -----------------------------------------------------------------------------

void ScalarConverter::printPseudo(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "-inf" || literal == "+inf") {
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    } else {
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
}

void ScalarConverter::printChar(double val) {
    std::cout << "char: ";
    if (val < 0.0 || val > 127.0) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<int>(val))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
    }
}

void ScalarConverter::printInt(double val) {
    std::cout << "int: ";
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(val) << std::endl;
    }
}

void ScalarConverter::printFloat(double val) {
    float f = static_cast<float>(val);
    std::cout << "float: " << f;
    
    if (f == std::floor(f) && f < 1e6f && f > -1e6f) {
        std::cout << ".0";
    }
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double val) {
    std::cout << "double: " << val;
    
    if (val == std::floor(val) && val < 1e6 && val > -1e6) {
        std::cout << ".0";
    }
    std::cout << std::endl;
}

// -----------------------------------------------------------------------------
// Orchestrator
// -----------------------------------------------------------------------------
void ScalarConverter::convert(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        printPseudo(literal);
        return;
    }

    double value = 0.0;

    if (isChar(literal)) {
        value = static_cast<double>(literal[0]);
    } else if (isInt(literal) || isFloat(literal) || isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    } else {
        std::cout << "Invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}