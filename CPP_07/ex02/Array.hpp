/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 14:14:26 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/20 15:41:54 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array {
    private:
        T* _elements;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        ~Array();

        Array<T>& operator=(const Array<T>& other);
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

# include "Array.tpp" 
#endif