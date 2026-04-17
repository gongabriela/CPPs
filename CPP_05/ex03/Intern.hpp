/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 11:23:36 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/03/28 11:23:36 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern {
    private:
        AForm *createShrubberyCreationForm(std::string target);
        AForm *createRobotomyRequestForm(std::string target);
        AForm *createPresidentialPardonForm(std::string target);

    public:
        Intern();
        Intern(Intern const &other);
        ~Intern();
        Intern &operator=(Intern const &other);

        AForm *makeForm(std::string formName, std::string target);
};

#endif