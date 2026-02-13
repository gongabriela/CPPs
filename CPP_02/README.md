# CPP 02

Welcome to CPP 02! In this module, we learn about **fixed-point numbers** and the **Orthodox Canonical Form**.

## Table of contents

## Orthodox Canonical Form

When we create a class in C++, we are essentially creating a new data type. Like other built-in types (`int`, `char`, etc.), the compiler needs to know how to behave when it comes to creation, copying, and destruction.

The **Orthodox Canonical Form** is a convention consisting of four specific member functions that ensure this new data type behaves like the built-in ones. If you don't write these member functions manually, the compiler will do it for you, but its version is often not "smart" enough to deal with complex classes, especially ones that involve memory allocation.

For example purposes, let's use the `Fixed` class required by the CPP 02 module.

### Default constructor - `Fixed::Fixed()`

The default constructor decides what happens when you declare `Fixed a;`. We need it to ensure that our object starts in a valid state. In the ex00 case, we need to set `_fixedPointValue` to 0.

### Copy constructor - `Fixed::Fixed(const Fixed& src)`

The copy constructor decides what happens when we create a new object as a clone of an existing one, like `Fixed b(a);`.

The compiler's default version just copies values bit-by-bit. If your class had a pointer, both objects would point to the same memory address (this phenomenon is called **Shallow Copy**). If one is deleted, the other points to garbage. We need to implement the copy constructor manually to ensure a **Deep Copy** or specific logic.

### Copy assignment operator - `Fixed& Fixed::operator=(const Fixed& rhs)`

The copy assignment operator decides what happens when you update an already existing object with the values of another, like `c = b`.
It must handle self-assignment (`a = a`) and safely return a reference to itself (`*this`) to allow chaining (`a = b = c`).

### Destructor - `Fixed::~Fixed()`

The destructor decides what happens when the object goes out of scope. We need it to effectively clean resources, especially when a class allocates memory — the destructor needs to use `delete` to clean it.

## Fixed Point Numbers

Fixed-point arithmetic is a numerical representation that treats the number as an integer but decides that a specific number of bits are reserved for the fractional part.

For example, imagine dealing with money. You want to store `$1.50`. Instead of storing `1.50` as a float, you store `150`, and you know that the last two digits are the fractional part.

**What is the practical purpose of fixed-point numbers if floating-point numbers already exist as a built-in data type?**

Although floats enable us to store huge and tiny numbers, they lack precision and performance. In some programs and applications, precision and/or performance are non-negotiable, and that's where fixed-point numbers come in handy!

For the purpose of this module, it is established that out of the 32 bits of an integer:
*   **24 bits** are for the integer part.
*   **8 bits** are for the fractional part.

### The arithmetic behind transforming an int or float into fixed point

On our daily lives, we use base 10 - de decimal system -  to represent numbers, where each house has 10 times more value than the house before (dezena - 10, centena - 100, milhar - 1000, etc.).

But the computer does not use base 10. The computer uses base 2 - the binary system, composed of 0s and 1s. And in this system, each house has 2x more value than the house before (house 8, house 4, house 2, house 1.). So, each time we push a bit to the left, it goes to a house that has 2x more value than the house before. And if we push it 8 times, it falls to the house 256.

It's important to understand that the << operator only works with integer numbers, because this operator works with the raw bits of the memory. Floats for example are stored in memory in a really complex way (IEEE 754), so << doesn't work on them. 

To transform floats into fixed-point numbers, we can use the following formula:

nf * (1 << _fractionalBits)

where if n = 0.5 and _fractionalBits = 8, we would have:

roundf(0.5f * (1 << 8))
roundf(0.5f * 256)
roundf(128.0f)
128

## Ad-hoc polymorphysm/Overloading in C++

The ad-hoc pholimorhpism in c++ allows us to have one functions with multiple declarations, having a distinc parameter and behavior in each one of them. 

Main characteristics:
- static resolution: the choide of which function execute is made by the compiler (early binding).
- independence: there is no need of a base class or parental relation between the types.
- convenience: improves legibility of the code by avoiding function names like addInt, addDecimals, etc.

### Function overload

A function overload allows us to define multiple functions with the samename, as long as the "signature" (the data types, parameter quantities, etc) is different - the compiler is the one who will decide which version to call in the compilation runtime.

### Operator overload

The operator overload allows us to have the standar operators (+, -, *) to have **different meaning based on their operands**.
**We can also define how these operands work for their own classes!**


## Exercises

### Ex 00

### Ex 01

The main purpose of this exercise is to transform the class from ex00 and make it practical and useful (in ex00, we could only turn the number 0 into a fixed point). We are going to implement the logic for converting `int` and `float` to `Fixed` and vice versa.

We need to write two new constructors:

1.  **`Fixed(const int n)`**
    *   To convert an `int` to fixed with 8 fractional bits, we need to shift the bits to the left by 8 positions (which is equivalent to multiplying it by 256).
    *   `_fixedPointValue = n << _fractionalBits;`

2.  **`Fixed(const float n)`**
    *   We multiply the float by `2^(fract bits)`, which is the same as `(1 << 8)`, and round the result to the closest integer with `roundf`.

After writing those constructors, we need to write 2 methods that will convert those fixed values back to their original forms:

*   **`float toFloat(void) const;`**
    *   Divides the fixed value by `2^(fract bits)`. Don't forget to cast it to `float` before dividing to maintain precision!

*   **`int toInt(void) const;`**
    *   Shifts the bits to the right by 8 positions, discarding the fractional part.

You might have noticed that the symbol `<<` shows up often. This is called the **insertion operator**. This is a crucial point. We need to "overload" this operator so that we can pass a `Fixed` object to `std::cout`.

But before diving deeper, let's understand what each of these terms means:

*   **Operator:** It is basically a function with a weird name — a symbol — instead of a normal name. For example, let's think about addition. A function to do the add operation would be `add(1, 2)`. But we have an operator: `+`. We have other operators, like `-`, `=`, `==`, and so on.

*   **Overloading:** The term overloading means to give more work or functions to something than what it had originally. We will give an operator more functions, and the function performed will depend on the context in which it is placed.

*   **Operator Overloading:** We are now going to combine the last two concepts. Taking the `+` example again, C++ already knows how to add integers, and that's why `int a, int b; a + b` works. But the compiler does not know how to add variables of the class `Fixed` we created. Operator overload is when we write a special function to teach the compiler how to perform the addition operation with values of the type `Fixed`.

#### The Insertion Operator `<<`

We will see the insertion operator being used for two purposes in this exercise: to pass the Fixed value to the output stream, and to shift bits when transforming floats and ints to fixed-point values and vice versa. 

**First, let's talk about the output stream purpose.** 

Originally, in C, `<<` served only for binary math, to shift bits to the left. However, in the C++ library `iostream`, it was decided to overload this operator to signify "inserting a stream of data".

For example: when we use `std::cout << "msg"`, `std::cout` represents the output stream (terminal), and `<<` represents the action of sending something to that stream. When we use `<<` with an `int` or a `float`, the compiler knows what to do. But with a new datatype like `Fixed`, we need to teach it what to do. So, we need to write an operator overload for the insertion operator.

```cpp
std::ostream & operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return o;
}
```

This function is special because we need to declare it **outside** of the `Fixed` class. Why? Because class functions start with `Fixed::`. This doesn't, and that's because the operator `<<` works with two sides:

*   **Left side:** Receives the data (`std::cout`).
*   **Right side:** Data to be sent (the `Fixed` object).

If we placed this function inside the `Fixed` class, C++ would assume that `Fixed` is the left side.

*   **`std::ostream & o`**: Represents the left side as the output stream, just like `std::cout`. We need the reference `&` because streams cannot be copied! We are modifying the original stream by inserting things into it, so we need to pass its address, not a copy.
*   **`Fixed const & i`**: Represents the right side, which is the `Fixed` object we want to output. It needs to be `const` because printing an object should not alter it (safety guarantee). The `&` is for performance. If we don't use it, C++ will make a copy of the object just to output it. If we pass as `&`, it doesn't do that, and there is no risk of the variable being altered since it is also `const`!
*   **Return value type**: This is where a lot of people find it confusing. We need to return the stream itself. Why? To allow **chaining**, like we do with `std::cout`:

    ```cpp
    std::cout << fixedA << " " << fixedB << std::endl;
    ```

    C++ reads this from left to right. It executes `std::cout << fixedA` and returns the updated version of `std::cout`. The code becomes `(std::cout updated) << " "` and so on.
    If our function had a `void` return value, the line above would return an error right after the first `<<`, because the second `<<` would try to insert into a void space.

**Now, the purpose of shifting bits:**

Like i've mentioned earlier, the compiler understands the purpose of an operator based on context. When we use << around two integer numbers (number << number), it understands that we want to perform binary math (shift bits), and that is native to the c++ language. 

We need the bit shifting arithmethic in order to create a fixed point value, because we need to keep the integer part into those 24 bits, and the fractional part into the 8 bits.

And the << tells the compiler that you want to do that. For exammple: if n = 10, and fractBits = 8, when we do n << fractBits, we are saying to the compiler "shift the bits of number 10 to the left by 8 positions".

### Ex 02

--- 

## Compilation and Usage

---

**Project completed as part of the 42 School Common Core curriculum.**

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

# Guiao avaliacao 

## cpp02 ex00

- Nosso objetivo e criar uma classe que represente um numero em ponto fixo.
- para representar um ponto fixo, nossa classe precisa ter:
    - um atributo que guarde o valor em ponto fixo
    - um atributo que guarde o valor de bits fracionarios 
    - um metodo getrawbits que retorna o valor em bits (como um tipo int)
    - um metodo setrawbits guarda o valor em bits (como um tipo int)

    - a forma canonica ortodoxa
        - construtor padrao
        - construtor de copia
        - operadore de atribuicao
        - destrutor
Se o avaliador perguntar: "Mudaste o getRawBits neste exercício?"
Tu respondes: "Não. Essas funções lidam apenas com o armazenamento cru dos bits. A lógica de conversão (Fixed Point arithmetic) está isolada nos construtores e nos métodos toInt/toFloat."
nenhum deles guarda o valor real. um guarda o valor em bits na variavel, fixedPointValue, e o outro retorna o valor guardado por fixedpointvalue, que estara como um inteiro, sem o ponto que separa a parte inteira da fracionaria.

## cpp02 ex01

"No Ex00, criámos apenas a 'caixa' (a estrutura da classe) que guardava bits, mas não sabíamos o que eles significavam.
Neste Ex01, damos vida à classe. Agora conseguimos converter números reais (int e float) para o formato de Ponto Fixo e vice-versa. Basicamente, criámos um tradutor entre o mundo humano e o mundo do Ponto Fixo."