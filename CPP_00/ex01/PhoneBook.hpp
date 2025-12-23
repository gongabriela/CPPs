/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:08:15 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/23 14:00:41 by ggoncalv         ###   ########.fr       */
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
        PhoneBook(); //construtor
        void        AddContacts(); //recolhe as informacoes e depois adiciona um contacto ao phonebook
        void        printPhonebook() const; //printa o preview de todos os contactos salvos
    private:
        Contact contacts[8];
        int     index;
        int     totalContacts;
        //funcoes auxiliares
        std::string getInfo(const std::string& info); //recolhe uma informacao (usa-se em AddContacts)
        void        printContact(int index) const; //printa um contacto especifico (usa-se em printPhoneBook)
        std::string formatField(const std::string& str) const; //formata a informacao antes de printar (usa-se em printPhoneBook)
};

/* USO DE CONST&
   Quando criamos um paramatro coo std::string str, passamos por valor, copiando a string original.
   QUando fazemos std::string& str, nos passamos a string original por referencia, e tudo que modificarmos dentro do metodo sera modificado na string original
   e se fizermos const std::string& str?
   - passamos a string por referencia, nao perdemos "tempo" copiando outra
   - mas tambem nao tempos hipotese de modifica-la, pois ela e const! 
*/
#endif