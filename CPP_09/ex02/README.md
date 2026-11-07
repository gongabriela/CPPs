# Ex02: PmergeMe (Ford-Johnson Algorithm)

O objetivo do `ex02` é ordenar pelo menos 3000 inteiros positivos utilizando o **Algoritmo de Ford-Johnson** (Merge-Insertion Sort). 

O twist? Temos de implementar o algoritmo em dois contêineres diferentes (`std::vector` e `std::deque`) para comparar o tempo de execução microscópico entre as duas arquiteturas de memória.

Este manual desmembra a matemática e a lógica deste algoritmo, que foi criado com um único objetivo: **ordenar elementos usando o menor número absoluto de comparações possíveis.**

---

## 1. A Teoria: Porquê usar a Sequência de Jacobsthal?

A base do algoritmo é fundir listas usando a **Busca Binária**. A Busca Binária é brutalmente rápida, mas ela gasta menos comparações quando o tamanho da lista onde procura é da forma $2^n - 1$ (tamanhos como 1, 3, 7, 15, 31...). 

Se inserirmos os elementos do array um a um, de forma linear (1º, 2º, 3º...), a lista cresce de forma desajeitada e a busca binária cai em tamanhos ineficientes, custando 1 ou 2 comparações extras que arruínam o recorde matemático de Ford-Johnson.

Para forçar a lista a ter sempre o tamanho matemático perfeito para a Busca Binária, nós usamos os saltos da **Sequência de Jacobsthal: 1, 3, 5, 11, 21, 43, 85...** 
Nós damos o salto para o índice de Jacobsthal, e inserimos os elementos **de trás para a frente** até ao salto anterior. Isto atrasa o crescimento da lista no momento exato em que a Busca Binária precisa de espaço limpo.

---

## 2. Guia Passo a Passo da Implementação

### Fase 1: Divisão e Emparelhamento (`std::pair`)
Se a lista tem tamanho ímpar, separamos o último elemento temporariamente.
Pegamos na lista e formamos pares `(Vencedor, Perdedor)`. 
Para cada par, fazemos exatamente 1 comparação: o maior número é o `first` (Vencedor) e o menor é o `second` (Perdedor). Guardamos todos os pares num contêiner.

### Fase 2: A Descida Recursiva
Criamos uma nova lista imaginária, a lista **$S$**, apenas com os Vencedores.
Chamamos a nossa função recursivamente, passando apenas esta lista $S$. Ela continuará a dividir-se e a formar pares de vencedores até chegar ao fundo (tamanho 1) e voltar a subir perfeitamente ordenada.

### Fase 3: A Reconstrução dos Perdedores (O Rastreio)
A lista $S$ voltou ordenada! Mas as posições originais mudaram. 
Temos de recriar a lista de perdedores (vamos chamar-lhe **$X$**) colocando-os **na mesma ordem exata** em que os seus parceiros estão na nova lista $S$. 
*Truque crucial:* O subject exige o tratamento de números duplicados. Para garantir que um número repetido seja amarrado ao perdedor certo, utilizamos um array booleano `std::vector<bool> used` para marcar os pares que já foram resgatados, impedindo misturas.

### Fase 4: O Motor de Jacobsthal
O nosso primeiro passo é inserir o `X[0]` na primeira posição do array $S$. Como ele perdeu para o menor Vencedor de todos, a posição 0 é garantida sem precisar de comparações!
A partir de agora, disparamos a matemática:
Calculamos os números de Jacobsthal (`jacob_atual` e `jacob_anterior`). Iteramos de trás para a frente (do `jacob_atual` descendo até ao `jacob_anterior + 1`). 

### Fase 5: O Teto Otimizado da Busca Binária (`std::lower_bound`)
Ao pegar num perdedor da lista $X$ para o inserir no $S$, onde procuramos? 
Graças à matemática da Fase 1, nós sabemos quem derrotou este perdedor. A Busca Binária não precisa de procurar no array $S$ inteiro! Ela só procura desde o início `S.begin()` até à posição exata do seu Parceiro Vencedor. Isto corta o espaço de procura brutalmente, garantindo o limite de comparações do algoritmo original de 1959.

### Fase 6: O Ímpar
Se no início nós retirámos um elemento ímpar, ele é inserido no final de todo o processo usando uma busca binária simples na lista total (porque ele não tem um parceiro vencedor para servir de teto).

---

## 3. O Benchmark: Vector vs Deque (Por que o Vector ganha?)

O programa cronometra (usando `gettimeofday()`) a execução nos dois contêineres. Nos nossos testes de *stress* com 10.000 números aleatórios, o **`std::vector` é praticamente o dobro da velocidade do `std::deque`**. Porquê?

A resposta está na **Arquitetura da Memória**:
1. **`std::vector` (Memória Contínua):** Os blocos estão todos encostados fisicamente na RAM. A Busca Binária, ao saltar índices, torna-se incrivelmente rápida porque a CPU carrega blocos inteiros para a **Cache L1/L2**. Inserir no meio de um vetor custa um arrastamento de memória, mas o C++ fá-lo usando `memmove`, uma rotina em Assembly ultrarrápida.
2. **`std::deque` (Memória Fragmentada):** O deque aloca memória em dezenas de pequenos "pedaços" separados (chunks), ligados por uma matriz central. A Busca Binária tem de parar frequentemente para verificar se saltou a fronteira de um bloco para o próximo (cache misses). Além disso, inserir dados no meio de blocos fragmentados exige realocação de ponteiros complexa, atrasando o processo em volumes altos.
