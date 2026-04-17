/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 08:04:47 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/04/08 08:04:48 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Gabriela";

    std::cout << "--- ORIGINAL DATA ---" << std::endl;
    std::cout << "Memory address   : " << &myData << std::endl;
    std::cout << "Content (ID)     : " << myData.id << std::endl;
    std::cout << "Content (Name)   : " << myData.name << "\n" << std::endl;

    /** Serialize (Pointer -> Integer) */
    uintptr_t raw = Serializer::serialize(&myData);
    
    std::cout << "--- AFTER SERIALIZATION ---" << std::endl;
    std::cout << "Raw value        : " << raw << "\n" << std::endl;

    /** Deserialize (Integer -> Pointer) */
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "--- AFTER DESERIALIZATION ---" << std::endl;
    std::cout << "Recreated address: " << deserializedData << std::endl;
    std::cout << "Content (ID)     : " << deserializedData->id << std::endl;
    std::cout << "Content (Name)   : " << deserializedData->name << "\n" << std::endl;

    std::cout << "--- RESULT ---" << std::endl;
    if (deserializedData == &myData) {
        std::cout << "SUCCESS: The memory addresses match!" << std::endl;
    } else {
        std::cout << "FAILURE: The original address was lost!" << std::endl;
    }

    return 0;
}