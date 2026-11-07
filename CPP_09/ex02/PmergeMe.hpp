/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:49:43 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/07 13:59:45 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <exception>
# include <utility>
# include <algorithm>
# include <sys/time.h>
# include <cstdlib>
# include <sstream>
# include <climits>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int>  _deque;

        size_t      getJacobsthal(size_t n);
        long long   getTimeMicroseconds() const;

        void        sortVector(std::vector<int>& container);
        void        sortDeque(std::deque<int>& container);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void process(int argc, char** argv);

        class ErrorException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif