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
    // Corpo vazio pq tudo ja foi inicializado na lista
}

/*
    INITIALIZATION LIST:
    Voce inicia os atributos ja com o valor que voce quer. 
    quando voce faz da forma normal, o compilador primeiro cria o atributo com uma string vazia,
    e depois assinala o valor
    
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

/* USO DE CONST NOS GETTERS
   Ao utilizar o const, voce garante alguns pontos:
   1. caso alguem mude o metodo e ele passe a tentar alterar o atributo, da erro de compilacao. 
   2. pode acessar um atributo de um objeto instanciado como const, porque assim garante que nada mudara
      (se o objeto for const e o getter nao, tambem da erro de compilacao)
   Utilizar const nos metodos que apenas leem dados tambem e importante em termos de documentacao.
   E uma forma de deixar explicito que estes metodos nao modificam o objeto/metodo.
*/