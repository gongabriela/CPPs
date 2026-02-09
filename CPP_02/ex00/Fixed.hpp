/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 21:17:06 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/12/30 21:17:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class   Fixed {
    private:
        int _fixedPointValue; //rawbits
        static const int _fractionalBits = 8; //rep of the fract part of the fixed point number
    public:
        Fixed(); //default constructor
        Fixed(const Fixed &src); //copy constructor
        Fixed& operator=(const Fixed &rhs); // copy assigment operator
        ~Fixed(); // destructor

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

}; 

#endif

/**
 *  ORTHODOX CANONICAL FORM
 *  
 *  - Default Constructor
 *      -> It is called when you declare an object with no arguments
 *      -> initializes the object in a "empty", "padronized" state.
 *
 *  - Copy constructor
 *      -> When you create a new object from an existent object. 
 *      -> It needs to garantee a correct copy of all data
 *
 *  - Copy assignment operator overload (ClassName &operator=(const ClassName &rhs);)
 *      -> When you assign an existent object to another existent object
 *      -> It needs to "clean" the current object, copy the data from the other object, and return a reference of itself (*this) to allow chain assignments (a = b = c).
 *      -> rhs: right-hand side (A = B) - A é LHS e B é RHS!
 * 
 *  - Destructor
 *      -> Called when  the object goes outside of its scope or is deleted.
 *      -> it is used to delete resources (allocated memory, opened files, etc).
 * 
 */

 /**
  * More about copy assignment operator
  * -> O CAO é uma função apesar de sua sintaxe
  * -> Isso se chama sobrecarga de operadores (operator overloading)
  * -> Em c++, a palavra-chave 'operator' permiteque você defina símbolos padrão (=, +, *, <<) se comportam com a sua classe.
  * -> o compilador lê 'Exemplo &operator=(const Exemplo &rhs);' como uma função normal, onde o nome da função é literalmente 'operator='
  * -> portanto se durante o seu codigo voce tem dois objetos a e b e faz a = b, o compilador enxergara a.operator = b;
  * -> agora analisando melhor o prototipo 'Exemplo &operator=(const Exemplo &rhs);':
  *     -> Exemplo &: tipo de retorno
  *         -> importante para permitir encadeamento como a = b = c.
  *         -> Isso é traduzido para a = (b = c). O b = c executa primeiro, retorna o objeto b (já atualizado), que então é passado para o a = ....
  *     -> operator= : nome da função
  *     -> const Exemplo &rhs : parametros
  *         -> é const pois nao queremos alterar o objeto original, apenas lê-lo
  *         -> é ref & para evitar copiar o objeto inteiro como parâmetro (performance)
  *         -> rhs (explicação em cima)
  * 
  * E como o compilador consegue ver que a = b envolve o copy operator se fazemos tantas assinalacoes ao longo do codigo?
  *     -> O compilador sabe nativamente o que sao os tipos primitivos (int, char, float, etc). Mas quando voce cria uma classe, voce esta inventando um tipo de dados novo,
  *         que o compilador nao conhece nativamente. Se voce faz isso:
  *         Fixed a;
  *         Fixed b;
  *         a = b;
  *         O compilador precisa saber como copiar a para b. Sera que ele deve copiar variavel por variavel, sera que tem algum ponteiro que precisa ser alocado, sera que ele
  *         precisa avisar no log que copiou?
  *         E aqui que entra o operator=. Para classes, o sinal de igual sempre e traduzido como uma chamada para essa funcao.
  *     -> E tem mais! Se voce nao escreve manualmente o copy operator, assim como o constructor, ele cria um para voce! Se chama shallow copy :) 
  */

  /**
   * Duvida: se o compilador ja cria todos esses metodos da canonical form, porque entao precisamos cria-las manualmente?
   *   
   * 1. Comportamento Automático do Compilador
   * -> Se você não declarar os métodos da OCF, o compilador gera versões implícitas automaticamente.
   * ->Essas versões fazem uma Shallow Copy (Cópia Rasa): copiam os valores bit-a-bit.
   * 
   * 2. O Problema da Shallow Copy
   * -> Funciona bem para tipos primitivos (int, float), mas é desastrosa para ponteiros.
   * -> Ao copiar um ponteiro bit-a-bit, o novo objeto aponta para o mesmo endereço de memória do original.
   * -> Consequência (Double Free): Quando os objetos são destruídos, ambos tentam liberar (delete) a mesma memória duas vezes, causando o crash do programa.
   * 
   * 3. A Solução: Deep Copy (Cópia Profunda)
   * -> Ao escrever a OCF manualmente, você assume o controle para alocar nova memória e copiar o conteúdo, não apenas o endereço.
   * -> Isso garante que cada objeto seja independente.
   */

   /**
    *  Porque usar o '_' nos atributos _fixedPointValue e _fractionalBits:
    *   ->
    */