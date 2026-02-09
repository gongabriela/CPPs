# CPP 03

**Bem-vinda ao Módulo 03: Herança (Inheritance).**

Se o **Módulo 02** foi sobre *precisão matemática e bits*, o **Módulo 03** é sobre **Arquitetura de Código e Reutilização**.

Aqui você vai parar de "copiar e colar" código e começar a criar hierarquias de classes inteligentes. O tema é divertido: você vai criar uma família de robôs (os Traps do jogo *Borderlands*).

---

### O Grande Salto Mental

No C++ até agora, cada classe era uma ilha isolada.

* **Antes:** Se você quisesse criar um `SuperRobo` que faz tudo que o `Robo` faz, mas melhor, você tinha que copiar todo o código do `Robo` para o `SuperRobo`.
* **Agora:** Você vai dizer: "O `SuperRobo` **É UM** `Robo`". Ele herda tudo automaticamente.

---

### O Mapa do Módulo 03

O módulo é dividido em 4 exercícios que contam uma história evolutiva:

#### 1. Ex00: ClapTrap (O Ancestral)

Você cria a classe base.

* **Conceito:** Encapsulamento estrito (`private`) e lógica básica de recursos (HP, Energia).
* **Desafio:** Fazer a Forma Canônica Ortodoxa funcionar perfeitamente e lidar com o *underflow* de `unsigned int` (o bug de vida negativa).

#### 2. Ex01: ScavTrap (O Filho Guardião)

O primeiro herdeiro.

* **Conceito:** A palavra-chave **`protected`**.
* `private`: "Só eu mexo."
* `protected`: "Eu e meus filhos mexemos."
* `public`: "Todo mundo mexe."


* **Desafio:** Entender a **Ordem de Construção/Destruição**. (O pai nasce antes do filho, o filho morre antes do pai).
* **Conceito Vital:** O **Destrutor Virtual**. Sem isso, o pai não sabe limpar a memória do filho.

#### 3. Ex02: FragTrap (O Irmão Festeiro)

O segundo herdeiro.

* **Conceito:** Consolidação. É muito parecido com o ScavTrap, mas com valores diferentes e uma função nova (`highFivesGuys`).
* **Objetivo:** Provar que você consegue ter múltiplas classes filhas herdando da mesma base sem que elas interfiram umas nas outras.


## EX00

### 1. Encapsulamento e Visibilidade (`private` vs `public`)

O Ex00 introduziu a ideia de proteger os dados do robô.

* **Atributos Privados:** Inicialmente, `_name`, `_hitPoints`, `_energyPoints` e `_attackDamage` foram declarados como **`private`**.
* *Conceito:* "O mundo exterior (a main) não pode tocar nos meus orgãos vitais diretamente. Se quiserem mudar meu HP, usem a função `takeDamage`."
* *Evolução:* Mais tarde (no Ex01), descobrimos que `private` era restrito demais para herança, e mudamos para `protected`. Mas no Ex00, o encapsulamento estrito era a regra.



---

### 2. Forma Canônica Ortodoxa (Orthodox Canonical Form)

Foi aqui que você aprendeu a regra de ouro das classes na 42. Para uma classe ser considerada "estável" e segura, ela precisa implementar os "Big 4":

1. **Default Constructor:** `ClapTrap()` -> Para criar arrays ou variáveis sem parâmetros.
2. **Copy Constructor:** `ClapTrap(const ClapTrap &copy)` -> Para criar um objeto novo clonando um existente.
3. **Copy Assignment Operator:** `operator=` -> Para atualizar um objeto já existente com os dados de outro.
4. **Destructor:** `~ClapTrap()` -> Para limpar a bagunça quando o objeto morre.

---

### 3. Lógica de Jogo: Gerenciamento de Recursos

Implementamos a regra de "custo de ação" e "estado de morte".

* **A Regra de Ouro:** Antes de `attack` ou `beRepaired`, o robô deve checar:
```cpp
if (_energyPoints > 0 && _hitPoints > 0)

```


* **O Custo:** Toda ação custa 1 ponto de energia (`_energyPoints--`).
* **A Morte:** Se HP = 0, o robô não faz mais nada. Ele vira um peso de papel.

---

### 4. A Armadilha do `unsigned int` (Underflow)

Este foi o desafio lógico mais técnico do exercício.

* **O Problema:** Os atributos são `unsigned int` (apenas positivos).
* Se você tem 5 HP e toma 10 de dano: `5 - 10` em matemática inteira sem sinal **não dá -5**. Dá `4.294.967.291` (um número gigante).


* **A Solução:** No método `takeDamage`, tivemos que fazer uma verificação manual:
```cpp
if (amount >= _hitPoints)
    _hitPoints = 0; // Zera a vida em vez de subtrair
else
    _hitPoints -= amount;

```


Isso garantiu que seu robô morresse corretamente em vez de virar um deus imortal com 4 bilhões de vida.

---

### 5. Interação "Faz de Conta" (Abstraction)

O Subject pediu: *"Os parâmetros não devem se referir a outra instância"*.

* **O Conceito:** O método `attack(string const &target)` recebe apenas um **nome**, não um objeto.
* **A Realidade:** O `ClapTrap` "grita" que atacou o alvo, mas ele não tem o poder de reduzir o HP do inimigo automaticamente.
* **O Mestre do Jogo (Main):** É responsabilidade de quem escreve a `main` conectar a história:
1. Chamar `a.attack("B")`.
2. Chamar manualmente `b.takeDamage(dano)`.

---

### 6. Lista de Inicialização (Member Initializer List)

No construtor, usamos a sintaxe correta para inicializar variáveis antes mesmo do corpo da função começar:

```cpp
ClapTrap::ClapTrap(string name) : _name(name), _hitPoints(10), ... {
    cout << "Constructor called" << endl;
}

```

* Isso é mais eficiente do que atribuir valores dentro das chaves `{}`, e é obrigatório para certos tipos de dados (como `const` ou referências), então é bom criar o hábito desde o Ex00.

---

### Resumo Visual da Base (ClapTrap)

```text
[ ClapTrap ]
- _name (string)
- _hitPoints (10)
- _energyPoints (10)
- _attackDamage (0)
-------------------
+ attack() -> Gasta Energia, Printa msg
+ takeDamage() -> Reduz HP, Checa underflow
+ beRepaired() -> Gasta Energia, Aumenta HP

```

## EX01

### 1. Herança e Modificadores de Acesso (`protected`)

A principal mudança do **Ex00** para o **Ex01** foi a introdução da herança. O `ScavTrap` herda do `ClapTrap`.

* **O Problema do `private`:** No Ex00, os atributos (`_name`, `_hitPoints`, etc.) eram `private`. Isso significa que **apenas** a classe `ClapTrap` podia vê-los. Nem mesmo as classes filhas (`ScavTrap`) tinham acesso.
* **A Solução `protected`:** Mudamos os atributos para `protected` no `ClapTrap.hpp`.
* **`private`**: Acessível apenas pela própria classe.
* **`protected`**: Acessível pela própria classe **e suas filhas**.
* **`public`**: Acessível por qualquer um (incluindo a `main`).



Isso permitiu que o `ScavTrap` modificasse diretamente os valores de vida e dano herdados.

---

### 2. Ciclo de Vida: Construção e Destruição ("Chaining")

O C++ segue uma ordem rigorosa para garantir que a memória seja gerenciada corretamente. Imagine a construção de uma casa:

* **Construção (Do Pai para o Filho):**
Quando você cria um `ScavTrap`, o C++ primeiro constrói a base (`ClapTrap`) para garantir que a "fundação" exista, e só depois executa o construtor do `ScavTrap` (o acabamento).
* *Código:* `ScavTrap::ScavTrap(string name) : ClapTrap(name)`
* *Resultado:* `ClapTrap constructor` -> `ScavTrap constructor`.


* **Destruição (Do Filho para o Pai):**
Quando o objeto é destruído, o processo é inverso. Primeiro removemos as características específicas (`~ScavTrap`) e depois demolimos a base (`~ClapTrap`).
* *Resultado:* `ScavTrap destructor` -> `ClapTrap destructor`.

---

### 3. O Problema do "Shadowing" (Sombra de Variáveis)

Este foi um erro sutil que causou mensagens sem nome no seu log (`ScavTrap constructor called for `).

* **O Erro:** Você redeclarou `std::string _name;` dentro do `ScavTrap.hpp`.
* **O Efeito:** O `ScavTrap` criou uma **nova variável** chamada `_name` que "escondia" (shadowed) a variável `_name` herdada do pai.
* **Consequência:** O pai inicializava a variável dele ("Serena"), mas o filho tentava ler a variável nova (que estava vazia).
* **A Correção:** Nunca redeclare atributos que já existem na classe pai. O `ScavTrap` deve usar a variável que já foi criada pelo `ClapTrap`.

---

### 4. Forma Canônica em Classes Derivadas

Aprendemos a diferença crucial entre **Inicializar** (Construtor) e **Atribuir** (Operador).

* **Copy Constructor (Nascer Copiando):**
O objeto está sendo criado agora. Devemos usar a **Lista de Inicialização** para chamar o construtor de cópia do pai.
```cpp
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) { ... }

```


*Isso garante que a parte "pai" seja copiada antes da parte "filho" nascer.*
* **Copy Assignment Operator (Atualizar Existente):**
O objeto já existe. Não podemos usar lista de inicialização (`:`). Devemos chamar o operador do pai explicitamente dentro da função.
```cpp
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other); // Chama a função do pai manualmente
    }
    return *this;
}

```



---

### 5. O Destrutor Virtual (`virtual`)

Este é o conceito de segurança de memória mais importante da herança.

* **O Cenário:** Um ponteiro do tipo pai apontando para um filho (`ClapTrap* ptr = new ScavTrap`).
* **Sem `virtual`:** Ao fazer `delete ptr`, o compilador olha para o tipo do ponteiro (`ClapTrap*`), chama apenas `~ClapTrap()` e ignora a existência do `ScavTrap`. Resultado: Vazamento de memória (a parte do filho fica órfã).
* **Com `virtual`:** O compilador verifica em **tempo de execução** qual é o tipo real do objeto. Ele descobre que é um `ScavTrap`, chama `~ScavTrap()` primeiro e depois `~ClapTrap()`.

---

### 6. Estudo de Caso: Por que o Ataque saiu como "ClapTrap"?

No seu Teste 3, tivemos este comportamento curioso:

```cpp
ClapTrap* ptr = new ScavTrap("HeapRobot");
ptr->attack("Target");
// Output: ClapTrap HeapRobot attacks Target, causing 20 points of damage!

```

Você perguntou: *"Por que ele usou o nome do pai (ClapTrap) mas o dano do filho (20)?"*

Isso acontece devido à diferença entre **Static Binding** (Ligação Estática) e **Atributos Herdados**.

#### Parte A: O Dano (20)

Os atributos (`_attackDamage`) são apenas dados na memória.

1. O `ClapTrap` criou a variável `_attackDamage`.
2. O construtor do `ScavTrap` foi lá e mudou o valor dela para **20**.
3. Quando a função imprimiu, ela leu a memória e encontrou o valor **20**.
*Conclusão:* Os dados são compartilhados e foram atualizados corretamente.

#### Parte B: O Nome da Função ("ClapTrap attacks...")

Aqui entra a diferença entre funções normais e virtuais.

1. **A Função `attack` NÃO é Virtual:**
O Subject não pediu para colocar `virtual void attack()`. Portanto, o compilador usa **Ligação Estática (Static Binding)**.
* O compilador olha para o ponteiro `ptr`.
* Ele vê que o ponteiro é do tipo `ClapTrap*`.
* Como a função não é virtual, ele decide **na hora da compilação**: *"Vou chamar a função `ClapTrap::attack`"*. Ele não se importa se o objeto real é um ScavTrap.


2. **Se a Função FOSSE Virtual:**
Se você tivesse declarado `virtual void attack()` no pai, o compilador usaria **Ligação Dinâmica (Dynamic Binding)**.
* Ele olharia para o ponteiro `ClapTrap*`.
* Ele veria a palavra `virtual`.
* Ele pensaria: *"Opa, vou esperar o programa rodar para ver quem esse ponteiro realmente é"*.
* Na execução, ele veria que é um `ScavTrap` e chamaria `ScavTrap::attack`, imprimindo a mensagem correta.



**Resumo da Ópera:**

* O **Destrutor** funcionou corretamente (ScavTrap -> ClapTrap) porque nós colocamos `virtual`.
* O **Ataque** funcionou com a lógica do pai (ClapTrap attacks) porque nós **não** colocamos `virtual`.
* O **Dano** estava correto (20) porque o valor da variável foi alterado na memória compartilhada.

## EX02

### 1. Herança Hierárquica (A Estrutura de "Irmãos")

No Ex01, tínhamos uma linha reta (`ClapTrap` -> `ScavTrap`). No Ex02, criamos uma ramificação.

* **O Conceito:** `ScavTrap` e `FragTrap` são classes derivadas da mesma base (`ClapTrap`).
* **Independência:** Embora ambos compartilhem o mesmo "DNA" (código do `ClapTrap`), eles são completamente independentes. Um `ScavTrap` não sabe que o `FragTrap` existe. Eles são "irmãos" que não conversam entre si.
* **Compartilhamento de Código:** A grande vantagem aqui é que não precisamos reescrever a lógica de `takeDamage`, `beRepaired` ou o gerenciamento de `_name`. Ambos os irmãos herdam isso de graça do pai.

---

### 2. Inicialização e Construtores (Valores Diferentes)

A mecânica de construção é idêntica à do Ex01, mas os **valores** definem a especialização da classe.

* **A Ordem de Chamada:**
Quando você instancia um `FragTrap`, o C++ faz:
1. Chama `ClapTrap()` (Constrói a base genérica).
2. Chama `FragTrap()` (Especializa a base).


* **A Especialização (No código):**
Dentro do construtor do `FragTrap`, nós alteramos os valores herdados para torná-lo um robô mais ofensivo:
* **Hit Points:** 100 (Igual ao ScavTrap).
* **Energy Points:** 100 (Muito mais energia que os outros).
* **Attack Damage:** 30 (O mais forte até agora).


*Nota:* Isso prova que o modificador `protected` no pai funcionou, permitindo que o `FragTrap` sobrescrevesse esses valores diretamente.

---

### 3. Herança de Métodos: Por que "ClapTrap attacks"?

Este foi um ponto sutil e interessante do seu output.

* **No ScavTrap (Ex01):** Nós declaramos `void attack(...)` no `.hpp` e implementamos no `.cpp`. Isso é **Override** (Sobrescrita). Por isso aparecia "ScavTrap attacks...".
* **No FragTrap (Ex02):** Você (corretamente) optou por **não** sobrescrever a função `attack`. O Subject não obrigava.
* **O Resultado:** Quando você chamou `frag.attack()`, o compilador procurou a função na classe `FragTrap`. Não achou. Então, ele subiu para a classe pai (`ClapTrap`) e usou a implementação dela.
* **A Mensagem:** Por isso o log mostrou `"ClapTrap <name> attacks..."`.
* **O Dano:** Apesar da mensagem ser a do pai, o **valor do dano** foi **30**. Isso acontece porque a função `attack` do pai usa a variável `_attackDamage`, e o construtor do `FragTrap` já tinha atualizado essa variável para 30 na memória.


*Conclusão:* Você herdou o **comportamento** (código da função), mas usou os **dados** (variáveis) atualizados.

---

### 4. Capacidades Únicas (`highFivesGuys`)

Diferente da herança (onde você ganha coisas do pai), aqui você criou algo novo.

* **Extensão de Funcionalidade:** O `FragTrap` tem tudo o que o `ClapTrap` tem **MAIS** a função `highFivesGuys`.
* **Limitação de Ponteiros:** Se você tiver um ponteiro `ClapTrap* ptr = new FragTrap();`, você **não** consegue chamar `ptr->highFivesGuys()`.
* *Por que?* Porque o ponteiro "vê" apenas a estrutura do `ClapTrap`, e essa função não existe lá. Para chamar essa função, você precisa de um objeto ou ponteiro do tipo `FragTrap`.



---

### 5. Destrutor Virtual e Polimorfismo (A Segurança)

Validamos novamente que a alteração feita no Ex00/01 (`virtual ~ClapTrap`) protege toda a hierarquia.

* **O Teste:** `ClapTrap* ptr = new FragTrap(); delete ptr;`
* **O Fluxo:** O programa detectou em tempo de execução que o objeto era um `FragTrap`.
1. Chamou `~FragTrap()` (Limpou a parte específica).
2. Chamou `~ClapTrap()` (Limpou a base).


* **A Regra:** Se a classe base tem destrutor virtual, **todas** as classes filhas herdam esse comportamento automaticamente. Você não precisou fazer nada extra no Ex02 para isso funcionar, apenas seguir a Forma Canônica.

---

### 6. Cuidados na Implementação (Copy-Paste)

O Ex02 é um teste de atenção aos detalhes.

* **Include Guards:** Mudar de `SCAVTRAP_HPP` para `FRAGTRAP_HPP` é vital para evitar conflitos de definição se você incluir ambos os arquivos.
* **Shadowing:** Assim como no Ex01, o `FragTrap` **não** deve redeclarar `_name`, `_hitPoints`, etc. Ele deve confiar nas variáveis que herdou. O seu teste provou que você fez isso certo, pois os nomes apareceram corretamente.

---

### Resumo Visual da Hierarquia até agora

```text
      [ ClapTrap ]
      (Base Class)
      /          \
 [ ScavTrap ]  [ FragTrap ]
 (Derived 1)   (Derived 2)
  - GateKeeper  - HighFives
  - HP: 100     - HP: 100
  - EP: 50      - EP: 100
  - AD: 20      - AD: 30

```