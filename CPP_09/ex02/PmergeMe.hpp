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

/**
 * @class PmergeMe
 * @brief Sorts a sequence of positive integers with the Ford-Johnson algorithm
 *        (merge-insertion sort), using both `std::vector` and `std::deque`.
 *
 * Reads the numbers from the program arguments, sorts them with a separate
 * implementation for each container, and prints the sequence before and after
 * sorting, together with the time spent by each container (reading the input
 * plus sorting).
 */
class PmergeMe
{
    private:
        /** @brief Sequence stored and sorted in a `std::vector`. */
        std::vector<int> _vector;
        /** @brief The same sequence, stored and sorted in a `std::deque`. */
        std::deque<int>  _deque;

        /** @brief Returns the n-th Jacobsthal number. */
        size_t      getJacobsthal(size_t n);
        /** @brief Returns the current time in microseconds. */
        long long   getTimeMicroseconds() const;

        /** @brief Sorts a `std::vector` with Ford-Johnson. */
        void        sortVector(std::vector<int>& container);
        /** @brief Sorts a `std::deque` with Ford-Johnson. */
        void        sortDeque(std::deque<int>& container);

        /** @brief Recursive Ford-Johnson on the indices of a `std::vector`. */
        void        sortVectorIdx(const std::vector<int>& values, std::vector<size_t>& idx);
        /** @brief Recursive Ford-Johnson on the indices of a `std::deque`. */
        void        sortDequeIdx(const std::deque<int>& values, std::deque<size_t>& idx);

        /** @brief Converts a token to an integer between 0 and `INT_MAX`. */
        bool        parseNumber(const std::string& token, int& out) const;
        /** @brief Validates the whole input before anything is printed. */
        void        validateInput(int argc, char** argv) const;
        /** @brief Reads the numbers from the arguments into `_vector`. */
        void        fillVector(int argc, char** argv);
        /** @brief Reads the numbers from the arguments into `_deque`. */
        void        fillDeque(int argc, char** argv);

    public:
        /** @brief Default constructor (empty containers). */
        PmergeMe();
        /** @brief Copy constructor. */
        PmergeMe(const PmergeMe& other);
        /** @brief Copy assignment operator. */
        PmergeMe& operator=(const PmergeMe& other);
        /** @brief Destructor. */
        ~PmergeMe();

        /** @brief Validates, sorts and prints the sequence and the timings. */
        void process(int argc, char** argv);

        /**
         * @class ErrorException
         * @brief Input error; the message is always `"Error"`.
         */
        class ErrorException : public std::exception
        {
            public:
                /** @brief Returns the error message. */
                virtual const char* what() const throw();
        };
};

#endif
