/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 07:23:40 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/09/22 08:18:57 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container :(");
    }
    return it;
}

#endif 