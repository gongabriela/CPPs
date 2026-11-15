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
# include <list>
# include <stdexcept>
# include <cctype>
# include <climits>

/**
 * @class RPN
 * @brief Evaluates expressions written in Reverse Polish Notation.
 *
 * Accepts single-digit numbers (0 to 9) and the operators `+ - * /`, separated
 * by spaces, for example `"8 9 * 9 - 9 - 9 - 4 - 1 +"`. Evaluation uses a
 * stack: numbers are pushed, and each operator pops two operands and pushes
 * the result.
 *
 * The stack uses `std::list` as its underlying container instead of the
 * default `std::deque`, because `std::deque` is used in ex02 and containers
 * cannot be reused across exercises.
 */
class RPN
{
    private:
        /** @brief Expression to evaluate. */
        std::string _expression;
        /** @brief Operand stack (always holds values that fit in an `int`). */
        std::stack<int, std::list<int> > _stack;

    public:
        /** @brief Default constructor (empty expression). */
        RPN();
        /** @brief Creates the evaluator for the expression `expression`. */
        RPN(const std::string &expression);
        /** @brief Copy constructor. */
        RPN(const RPN &other);
        /** @brief Copy assignment operator. */
        RPN &operator=(const RPN &other);
        /** @brief Destructor. */
        ~RPN();

        /** @brief Evaluates the expression and returns the result. */
        int calculate();

        /**
         * @class ErrorException
         * @brief Error in the expression or the calculation, with a custom message.
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
