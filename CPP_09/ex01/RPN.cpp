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

RPN::RPN() : _expression("") {}

RPN::RPN(const std::string &expression) : _expression(expression) {}

RPN::RPN(const RPN &other) : _expression(other._expression), _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _expression = other._expression;
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::calculate()
{
    if (_expression.empty())
        throw RPN::ErrorException("Error");

    this->_stack = std::stack<int>();

    for (size_t i = 0; i < _expression.length(); ++i)
    {
        char c = _expression[i];

        if (std::isspace(c))
            continue;

        // A verificação vital para o teu loop: o próximo char TEM de ser espaço ou fim
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

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            switch (c)
            {
                case '+':
                    _stack.push(a + b);
                    break;
                case '-':
                    _stack.push(a - b);
                    break;
                case '*':
                    _stack.push(a * b);
                    break;
                case '/':
                    if (b == 0)
                        throw RPN::ErrorException("Error");
                    _stack.push(a / b);
                    break;
            }
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