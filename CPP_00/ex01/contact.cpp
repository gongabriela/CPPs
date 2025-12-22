/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:39:37 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/22 15:41:01 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(std::string first, std::string last, std::string nick,
    std::string phone, std::string darkest) {
    this->firstName = first;
    this->lastName = last;
    this->nickname = nick;
    this->phoneNumber = phone;
    this->darkestSecret = darkest;
}