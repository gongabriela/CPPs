# CPP 03

## EX00

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