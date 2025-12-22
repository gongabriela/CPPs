/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 14:51:43 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream> 
# include <string> 
# include <iomanip>
# include <sstream>

class PhoneBook {
    public:
        PhoneBook(int valorInicial);
        void        AddContacts();
        std::string getInfo(std::string info);
        void        printContact(int index);
        void        printPhonebook();
        std::string formatField(std::string str);
    private:
        Contact contacts[8];
        int     index;
        int     totalContacts;
};

#endif