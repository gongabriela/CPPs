# C++ Module 09 - Standard Template Library (STL)

Este módulo marca o final da jornada do *Common Core* de C++ na 42. Após meses a reinventar a roda (gerindo memória manualmente, criando iteradores e construindo estruturas de dados do zero), o CPP09 liberta-nos para utilizar a poderosa **Standard Template Library (STL)**.

O objetivo principal não é apenas saber *como* usar a STL, mas sim **qual contêiner escolher para cada problema**, justificando a decisão com base na complexidade algorítmica ($O(1)$, $O(n)$, $O(\log n)$) e na arquitetura de memória subjacente (memória contínua vs. fragmentada).

## Regras do Módulo
**Contêineres Específicos:** Cada exercício exige a escolha e justificação de contêineres diferentes da STL. Uma vez usado um contêiner num exercício, ele não deve ser a escolha principal noutro, forçando a exploração de toda a biblioteca.

## Resumo dos Exercícios
* **[ex00 - Bitcoin Exchange](./ex00/README.md):** Criação de um programa que calcula o valor de uma carteira de Bitcoin numa data específica, cruzando dados com um banco de dados histórico (formato CSV).
* **[ex01 - Reverse Polish Notation](./ex01/README.md):** Implementação de uma calculadora matemática baseada na Notação Polaca Inversa (RPN), focada no processamento LIFO.
* **[ex02 - PmergeMe](./ex02/README.md):** Implementação do algoritmo de ordenação Ford-Johnson (Merge-Insertion Sort) em dois contêineres diferentes para efetuar um *benchmark* de performance entre estruturas de memória contínua e fragmentada.


# Referencias

ex00

https://stackoverflow.com/questions/69071462/how-to-handle-excel-files-using-c
https://www.geeksforgeeks.org/cpp/csv-file-management-using-c/
https://stackoverflow.com/questions/15080231/c-variable-stdifstream-ifs-has-initializer-but-incomplete-type
https://cplusplus.com/doc/tutorial/files/
https://www.w3schools.com/cpp/cpp_files.asp
https://stackoverflow.com/questions/22026697/passing-a-file-to-constructor-to-read

ex01

https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://en.cppreference.com/cpp/container/stack
https://www.geeksforgeeks.org/dsa/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-java/

ex02

https://en.wikipedia.org/wiki/Merge-insertion_sort
https://en.wikipedia.org/wiki/Binary_search
https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91
https://www.youtube.com/watch?v=w1QXGe295sI

