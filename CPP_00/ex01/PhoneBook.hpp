/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/01/11 12:50:16 by ggoncalv         ###   ########.fr       */
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
        PhoneBook(); // constructor
        void        AddContacts(); // collects info and then adds a contact to the phone book
        void        printPhonebook() const; // prints a preview table of all saved contacts
    private:
        Contact contacts[8];
        int     index;
        int     totalContacts;
        // helper functions
        std::string getInfo(const std::string& info); // collects a single field (used in AddContacts)
        bool        verifyInput(const std::string &info, const std::string &input); // validates user input
        void        printContact(int index) const; // prints a specific contact (used in printPhonebook)
        std::string formatField(const std::string& str) const; // formats info before printing (used in printPhonebook)
};

/* USE OF const&
   When we declare a parameter as std::string str, we pass by value, copying the original string.
   When we use std::string& str, we pass the original string by reference, and changes in the method
   modify the original string.
   What about const std::string& str?
   - We pass by reference, avoiding the cost of copying.
   - We also cannot modify it, because it is const!
*/
#endif