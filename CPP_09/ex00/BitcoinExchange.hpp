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
# include <sstream>
# include <cstdlib>
# include <exception> 

class BitcoinExchange {
    private:
        std::string _path;
        std::map<std::string, float> database;

        bool isValidDate(const std::string& date);
        bool parseValue(const std::string& valueStr, float& value);
        void readDatabaseFile(const std::string& databasePath);
        void getExchangeRate(const std::string& date, float value);

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& path);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void readInputFile();
        bool isValidLine(const std::string& line, std::string& date, float& value);

        class ErrorException : public std::exception {
            private:
                std::string _msg;
            public:
                ErrorException(const std::string& msg) throw() : _msg(msg) {}
                virtual ~ErrorException() throw() {}
                virtual const char* what() const throw() {
                    return _msg.c_str();
                }
        };
};

#endif