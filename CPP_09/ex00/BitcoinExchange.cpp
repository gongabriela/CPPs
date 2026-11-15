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

/**
 * @brief Default constructor.
 *
 * Creates an object with no input file. It exists to comply with the
 * Orthodox Canonical Form; the program always uses the path constructor.
 */
BitcoinExchange::BitcoinExchange() { }

/**
 * @brief Creates the converter for an input file.
 *
 * The file is only opened in readInputFile().
 *
 * @param path Path of the file with the `date | value` lines.
 */
BitcoinExchange::BitcoinExchange(const std::string& path) : _path(path) { }

/**
 * @brief Copy constructor.
 *
 * @param other Object to copy (path and database).
 */
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _path(other._path), database(other.database) { }

/**
 * @brief Copy assignment operator.
 *
 * @param other Object to copy (path and database).
 * @return A reference to this object.
 */
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _path = other._path;
        database = other.database;
    }
    return *this;
}

/**
 * @brief Destructor.
 */
BitcoinExchange::~BitcoinExchange() {}

/**
 * @brief Checks whether a string is a real date in the `YYYY-MM-DD` format.
 *
 * Checks the format (10 characters, dashes at positions 4 and 7, digits
 * everywhere else), that the month is between 1 and 12 and that the day exists
 * in that month, taking leap years into account (divisible by 4 and not by 100,
 * or divisible by 400).
 *
 * @param date String to validate.
 * @return `true` if the date is valid, `false` otherwise.
 */
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

/**
 * @brief Converts a string to a decimal number.
 *
 * The conversion is only accepted if the whole string is consumed: `"1.5"` is
 * valid, but `"1.5abc"` or `"1.5 "` are not.
 *
 * @param valueStr String to convert.
 * @param value    Receives the converted number.
 * @return `true` if the conversion is valid, `false` otherwise.
 */
bool BitcoinExchange::parseValue(const std::string& valueStr, double& value) {
    std::istringstream iss(valueStr);
    if (!(iss >> value) || !iss.eof()) return false;
    return true;
}

/**
 * @brief Validates a line of the input file and extracts its date and value.
 *
 * The line must have the format `date | value`, with a valid date and a
 * numeric value between 0 and 1000. If the line is invalid, the matching error
 * message is printed (`bad input`, `not a valid number`, `not a positive number`
 * or `too large a number`).
 *
 * @param line           Line to validate.
 * @param extractedDate  Receives the date part.
 * @param extractedValue Receives the converted value.
 * @return `true` if the line is valid, `false` otherwise.
 */
bool BitcoinExchange::isValidLine(const std::string& line, std::string& extractedDate, double& extractedValue) {
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

/**
 * @brief Loads the price database into the `std::map`.
 *
 * The first line must be exactly `date,exchange_rate`. Every following line
 * must have the format `YYYY-MM-DD,rate`, with a valid date and a non-negative
 * rate. Invalid lines are skipped, with a warning on stderr.
 *
 * @param databasePath Path of the CSV file.
 * @throws ErrorException If the file cannot be opened or the header is wrong.
 */
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
        double exchange_rate;

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

/**
 * @brief Prints the value of an amount of bitcoin on a date.
 *
 * Uses `lower_bound` to find the requested date. If that date does not exist,
 * it steps back to the closest earlier date, as the subject requires (never the
 * later one). If the date is earlier than every date in the database, an error
 * is printed. The result is shown with 10 significant digits so that it never
 * appears in scientific notation.
 *
 * @param date  Valid date in the `YYYY-MM-DD` format.
 * @param value Amount of bitcoin (between 0 and 1000).
 */
void BitcoinExchange::getExchangeRate(const std::string& date, double value) {
    std::map<std::string, double>::iterator it = this->database.lower_bound(date);

    if (it == this->database.begin() && it->first != date) {
        std::cout << "Error: date is too early => " << date << std::endl;
        return;
    }

    if (it == this->database.end() || it->first != date) {
        --it;
    }

    double exchangeRate = it->second;
    double result = value * exchangeRate;

    std::cout << std::setprecision(10) << date << " => " << value << " = " << result << std::endl;
}

/**
 * @brief Loads the database and processes the input file line by line.
 *
 * Reads `data.csv` from the current directory, then the input file, whose
 * first line must be `date | value`. For every following line it prints
 * either the converted value or the error message for that line; an invalid
 * line does not stop the processing.
 *
 * @throws ErrorException If the database cannot be opened, is invalid or is
 *         empty, or if the input file cannot be opened, is empty or has a
 *         wrong header.
 */
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
        double value;

        if(!isValidLine(line, date, value))
            continue;

        getExchangeRate(date, value);
    }
    input_file.close();
}
