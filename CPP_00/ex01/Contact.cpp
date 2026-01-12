/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:39:37 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/23 14:22:52 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(const std::string& first, const std::string& last, const std::string& nick,
    const std::string& phone, const std::string& darkest)
    : firstName(first),
      lastName(last),
      nickname(nick),
      phoneNumber(phone),
      darkestSecret(darkest) {
    // Empty body because all fields are already initialized in the list
}

/*
    INITIALIZATION LIST:
    You initialize the members directly with the desired values.
    If done in the constructor body, the compiler first creates the member with
    a default value (e.g., empty string) and then assigns the new value.
*/
std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getPhoneNumber() const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}

/* USE OF const IN GETTERS
    By marking getters as const, you ensure:
    1. If someone changes the method to modify a member, it will fail to compile.
    2. You can call the getter on a const object, guaranteeing no modification
        (if the object is const and the getter is not, it fails to compile).
    Using const for read-only methods also improves documentation: it makes
    explicit that these methods do not modify the object/state.
*/