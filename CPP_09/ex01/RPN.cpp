/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 06:32:14 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/03 06:58:04 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/**
 * @brief Default constructor: creates an evaluator with an empty expression.
 */
RPN::RPN() : _expression("") {}

/**
 * @brief Creates the evaluator for an expression.
 *
 * The expression is only validated and evaluated in calculate().
 *
 * @param expression Expression in Reverse Polish Notation.
 */
RPN::RPN(const std::string &expression) : _expression(expression) {}

/**
 * @brief Copy constructor.
 *
 * @param other Object to copy (expression and stack).
 */
RPN::RPN(const RPN &other) : _expression(other._expression), _stack(other._stack) {}

/**
 * @brief Copy assignment operator.
 *
 * @param other Object to copy (expression and stack).
 * @return A reference to this object.
 */
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _expression = other._expression;
        _stack = other._stack;
    }
    return *this;
}

/**
 * @brief Destructor.
 */
RPN::~RPN() {}

/**
 * @brief Evaluates the expression and returns the result.
 *
 * Walks through the expression one character at a time, skipping spaces:
 * - every token is a single character, so the next character must be a space
 *   or the end of the expression (this rejects numbers >= 10, such as `"12"`,
 *   and tokens stuck together, such as `"1+"` or `"-1"`);
 * - a digit is pushed onto the stack;
 * - an operator pops `b` (the top) and `a`, then pushes `a op b`.
 *
 * Arithmetic is done in `long long`, where none of the four operations between
 * two `int` values can overflow. The result is only pushed back if it fits in
 * an `int`; this also catches `INT_MIN / -1`, which would otherwise crash the
 * program. At the end, the stack must hold exactly one value.
 *
 * @return The result of the expression.
 * @throws ErrorException With the message `"Error"` if the expression is empty,
 *         contains an invalid character or a token longer than one character,
 *         an operator is missing operands, there is a division by zero, the
 *         result of an operation does not fit in an `int`, or more than one
 *         value is left on the stack.
 */
int RPN::calculate()
{
    if (_expression.empty())
        throw RPN::ErrorException("Error");

    this->_stack = std::stack<int, std::list<int> >();

    for (size_t i = 0; i < _expression.length(); ++i)
    {
        char c = _expression[i];

        if (std::isspace(c))
            continue;

        if (std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (i + 1 < _expression.length() && !std::isspace(_expression[i + 1]))
                throw RPN::ErrorException("Error");
        }

        if (std::isdigit(c))
        {
            _stack.push(c - '0');
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            if (_stack.size() < 2)
                throw RPN::ErrorException("Error");

            long long b = _stack.top();
            _stack.pop();
            long long a = _stack.top();
            _stack.pop();

            long long result = 0;
            switch (c)
            {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw RPN::ErrorException("Error");
                    result = a / b;
                    break;
            }

            if (result > INT_MAX || result < INT_MIN)
                throw RPN::ErrorException("Error");

            _stack.push(static_cast<int>(result));
        }
        else
        {
            throw RPN::ErrorException("Error");
        }
    }

    if (_stack.size() != 1)
        throw RPN::ErrorException("Error");

    return _stack.top();
}
