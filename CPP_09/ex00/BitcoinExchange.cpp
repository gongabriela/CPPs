/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:15:49 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/02 07:35:35 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { 
    std::cout << "Error: no input file path provided." << std::endl; 
}

BitcoinExchange::BitcoinExchange(const std::string& path) : _path(path) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _path = other._path;
        database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 1 || month < 1 || month > 12 || day < 1) return false;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        daysInMonth[2] = 29;
    }

    if (day > daysInMonth[month]) {
        return false;
    }

    return true;
}

bool BitcoinExchange::parseValue(const std::string& valueStr, float& value) {
    std::istringstream iss(valueStr);
    if (!(iss >> value) || !iss.eof()) return false;
    return true;
}

bool BitcoinExchange::isValidLine(const std::string& line, std::string& extractedDate, float& extractedValue) {
    size_t separatorPos = line.find(" | ");
    if (separatorPos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return false;
    }

    extractedDate = line.substr(0, separatorPos);
    std::string valuePart = line.substr(separatorPos + 3);

    if (!isValidDate(extractedDate)) {
        std::cout << "Error: bad input => " << extractedDate << std::endl;
        return false;
    }

    if (!parseValue(valuePart, extractedValue)) {
        std::cout << "Error: not a valid number." << std::endl;
        return false;
    }

    if (extractedValue < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (extractedValue > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void BitcoinExchange::readDatabaseFile(const std::string& databasePath) {
    std::ifstream database_file(databasePath.c_str());
    if (!database_file.is_open()) {
        throw BitcoinExchange::ErrorException("Error: could not open database file.");
    }

    std::string line;
    if (!std::getline(database_file, line) || line != "date,exchange_rate") {
        throw BitcoinExchange::ErrorException("Error: data.csv has invalid format.");
    }

    while (std::getline(database_file, line)) {
        float exchange_rate;
        
        if (line.length() < 12 || line[10] != ',' || !isValidDate(line.substr(0, 10)) 
        || !parseValue(line.substr(11), exchange_rate) || exchange_rate < 0) {
            std::cerr << "Error: invalid database format => " << line << std::endl;
            continue; 
        }

        std::string dateKey = line.substr(0, 10);
        this->database[dateKey] = exchange_rate;
    }
    database_file.close();
}

void BitcoinExchange::getExchangeRate(const std::string& date, float value) {
    std::map<std::string, float>::iterator it = this->database.lower_bound(date);

    if (it == this->database.begin() && it->first != date) {
        std::cout << "Error: date is too early => " << date << std::endl;
        return;
    }

    if (it == this->database.end() || it->first != date) {
        --it;
    }

    float exchangeRate = it->second;
    float result = value * exchangeRate;

    std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::readInputFile() {
    readDatabaseFile("data.csv");
    if (database.empty()) {
        throw BitcoinExchange::ErrorException("Error: database is empty."); 
    }

    std::ifstream input_file(this->_path.c_str());
    if (!input_file.is_open()) {
        throw BitcoinExchange::ErrorException("Error: could not open file.");
    }
    
    std::string line;
    if (std::getline(input_file, line)) {
        if (line != "date | value") {
            throw BitcoinExchange::ErrorException("Error: bad input => " + line);
        }
    } else {
        throw BitcoinExchange::ErrorException("Error: empty file.");
    }

    while(std::getline(input_file, line)) {
        std::string date;
        float value;

        if(!isValidLine(line, date, value))
            continue;
            
        getExchangeRate(date, value);
    }
    input_file.close();
}