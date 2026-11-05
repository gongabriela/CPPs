/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 06:30:42 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/03 06:58:48 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdexcept>
# include <cctype>

class RPN
{
    private:
        std::string _expression;
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const std::string &expression);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        int calculate();

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