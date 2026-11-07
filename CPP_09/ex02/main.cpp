/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 13:53:03 by ggoncalv          #+#    #+#             */
/*   Updated: 2026/11/07 13:53:11 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe sorter;
        sorter.process(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

/**
Pseudo code of the algorithm for vector

função recursiva(containerOriginal)
    containerOriginal.length == 1
        return;
    separar elemento impar se a lista for de tamanho impar
    colocar a lista em pares
    verificar qual e o maior de cada par e por numa lista
    chamar nela propria (recursao) com uma lista so dos maiores
    criar lista dos menores, na mesma ordem que os pares maiores estao na lista deles
    inserir menores[0] no maiores[0]

    jcbstl_prev = 1;
    jcbstl = 3;
    while (jcbstl_prev < Menores.length)
        if (jcbstl > Menores.length)
            jcbstl = Menores.length;
        for (i = jcbstl; i >= jcbstl_prev + 1; i--)
            menorElemento = Menores[i - 1];
            parMenorElemento = findParDoMenor(menorElemento, Maiores);
            indexMaximo = findIndexParDoMenor(parMenorELemento, Maiores);
            newPositionMenorElementoNosMaiores = binarySearch(MAiores, begin, indexMaximo, menorELemento);
            inserirMenorELementonosMAiores(newPositionMenorElementoNosMaiores, Maiores, menorElemento)
        jcbstl_prev = jcbstl;
        jcbstl = calculate_jacobsthal();
    if (elementoImpar)
        newPositionElementoImpar = binarySearch(Maiores, begin, Maiores.length, elementoImpar);
        inserirMenorElementonosMaiores(newPositionElementoImpar, Maiores, elementoImpar)
    containerOriginal = Maiores;
 */

 /*
 findParDoMenor(menorElemento, Maiores);
 findIndexParDoMenor(parMenorELemento, Maiores);
 binarySearch(MAiores, begin, indexMaximo, menorELemento);
 newPositionMenorElementoNosMaiores = binarySearch(MAiores, begin, indexMaximo, menorELemento);
 inserirMenorELementonosMAiores(newPositionMenorElementoNosMaiores, Maiores, menorElemento)
 calculate_jacobsthal();
 */

 /**
*/
