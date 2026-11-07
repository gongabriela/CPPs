# Ex01: Reverse Polish Notation (RPN)

Este exercício introduz a **Notação Polaca Inversa**, uma notação matemática onde o operador vem *sempre depois* dos operandos. 
Por exemplo, a equação clássica `(3 + 4) * 5` escreve-se em RPN como `3 4 + 5 *`. 

A grande vantagem da RPN é que ela **elimina completamente a necessidade de parênteses**. As antigas calculadoras da HP usavam esta lógica porque é a forma mais eficiente e natural para um computador processar matemática.

---

## 1. A Escolha do Contêiner: Porquê o `std::stack`?

Se desenharmos a forma como a RPN é resolvida no papel, percebemos que o último número a ser escrito é o primeiro a ser usado quando um operador aparece. Isto é a definição de **LIFO** (*Last-In, First-Out*).

O contêiner arquitetado exatamente para fluxos LIFO é o **`std::stack<int>`**.
* Ele restringe as nossas ações: só podemos colocar coisas no topo (`push`), ver o topo (`top`), ou retirar do topo (`pop`).
* Esta restrição é maravilhosa porque nos impede de aceder a números no meio da equação acidentalmente, blindando a lógica do nosso programa.

## 2. A Lógica de Implementação

O algoritmo da nossa calculadora RPN deve ler a string de entrada da esquerda para a direita, caracter a caracter (ignorando os espaços), e seguir duas regras estritas:

**Regra 1: É um número?**
Se o token for um dígito (de 0 a 9), convertemos para `int` e empurramos para a pilha (`stack.push()`).

**Regra 2: É um operador?**
Se for um `+`, `-`, `*`, ou `/`:
1. Retiramos o número que está no topo e guardamos na variável **`v2`** (direita).
2. Retiramos o novo número que ficou no topo e guardamos na variável **`v1`** (esquerda).
3. Executamos a matemática: `v1 operador v2`.
4. Empurramos o resultado de volta para o topo da pilha.

**Atenção à Ordem!** Na subtração e na divisão, a ordem importa muito. Se a pilha tem um `3` e inserimos um `4`, o topo agora é o `4`. Se vier o operador `-`, o cálculo correto é `3 - 4` (o de baixo menos o do topo), e não o inverso.

## 3. Gestão de Erros (O que faz o programa explodir?)

Uma calculadora robusta tem de proteger a CPU contra equações mal formatadas. O nosso código tem de verificar três cenários perigosos:
1. **Falta de operandos:** Aparece um operador na string, mas a pilha tem menos de 2 números. (Ex: `3 +`). Tentar fazer `pop()` numa pilha vazia causa *Segfault*.
2. **Divisão por Zero:** Se o operador for `/` e a variável `v2` for `0`, o programa aborta. Temos de lançar uma exceção de "Error".
3. **Falta de operadores:** No final da string, se a equação estiver correta, a pilha tem de conter **exatamente 1 elemento** (o resultado final). Se tiver mais do que um elemento, significa que o utilizador digitou números a mais sem operadores suficientes (Ex: `3 4 5 +`). É um erro.