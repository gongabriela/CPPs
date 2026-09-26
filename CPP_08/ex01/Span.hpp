/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 07:51:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/24 07:12:37 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>

class Span {
    private:
        unsigned int _n;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbersFromRange(Iterator begin, Iterator end) {
            if (std::distance(begin, end) + _numbers.size() > _n) {
                throw std::runtime_error("Cannot add range, capacity will be exceeded.");
            }
            _numbers.insert(_numbers.end(), begin, end);
        }
}; 

#endif