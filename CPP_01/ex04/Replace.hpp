/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:22:38 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/29 13:44:19 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

bool        getFileContent(const std::string& filename, std::string& fileContent);
int         replace(const std::string& filename, const std::string& s1, const std::string& s2);
int         createOutfile(const std::string& filename, const std::string& buffer);

#endif
