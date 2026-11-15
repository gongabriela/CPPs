/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:30:35 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/02 07:34:20 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <string>
# include <map>
# include <iomanip>
# include <sstream>
# include <cstdlib>
# include <exception>

/**
 * @class BitcoinExchange
 * @brief Computes the value of an amount of bitcoin on a given date.
 *
 * Loads the historical price database (`data.csv`, format
 * `date,exchange_rate`) into a `std::map` sorted by date, then processes an
 * input file whose lines have the format `date | value`. For each valid line it
 * prints `date => value = value * rate`, using the rate of that date or, if the
 * date is not in the database, the rate of the closest earlier date.
 */
class BitcoinExchange {
    private:
        /** @brief Path of the input file to process. */
        std::string _path;
        /** @brief Price database: date (`YYYY-MM-DD`) -> exchange rate. */
        std::map<std::string, double> database;

        /** @brief Checks whether a string is a real `YYYY-MM-DD` date. */
        bool isValidDate(const std::string& date);
        /** @brief Converts a string to a number, rejecting trailing garbage. */
        bool parseValue(const std::string& valueStr, double& value);
        /** @brief Loads the CSV price file into `database`. */
        void readDatabaseFile(const std::string& databasePath);
        /** @brief Prints the converted value of `value` on `date`. */
        void getExchangeRate(const std::string& date, double value);

    public:
        /** @brief Default constructor (no input file). */
        BitcoinExchange();
        /** @brief Creates the converter for the input file `path`. */
        BitcoinExchange(const std::string& path);
        /** @brief Copy constructor. */
        BitcoinExchange(const BitcoinExchange& other);
        /** @brief Copy assignment operator. */
        BitcoinExchange& operator=(const BitcoinExchange& other);
        /** @brief Destructor. */
        ~BitcoinExchange();

        /** @brief Loads the database and processes the input file. */
        void readInputFile();
        /** @brief Validates a `date | value` line and extracts its date and value. */
        bool isValidLine(const std::string& line, std::string& date, double& value);

        /**
         * @class ErrorException
         * @brief Fatal error that stops the program, with a custom message.
         */
        class ErrorException : public std::exception {
            private:
                /** @brief Message returned by what(). */
                std::string _msg;
            public:
                /** @brief Creates the exception with the message `msg`. */
                ErrorException(const std::string& msg) throw() : _msg(msg) {}
                /** @brief Destructor. */
                virtual ~ErrorException() throw() {}
                /** @brief Returns the error message. */
                virtual const char* what() const throw() {
                    return _msg.c_str();
                }
        };
};

#endif
