/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:17:06 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/30 21:17:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class   Fixed {
    private:
        int fixedPoint;
        static const int fractBits = 8;
    public:
        Fixed();
        FixedCopyConstructor(Fixed Copy);
        FixedAssignmentOperator(Fixed Value);
        ~Fixed();
        int getRawBits(void) const;
        void    setRawBits(int const raw);

}

#endif