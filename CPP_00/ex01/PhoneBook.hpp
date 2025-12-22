/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 11:45:41 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> 
# include <string> 
    
class PhoneBook {
    public:
        PhoneBook();
        void    AddContacts();
    private:
        Contact contacts[8];
        int     index;
};

#endif