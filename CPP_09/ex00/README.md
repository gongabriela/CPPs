# Ex00: Bitcoin Exchange

Bem-vindo ao ex00! Se este exercício fosse resumido numa frase, seria: **Como cruzar dados de forma eficiente.** 

Neste projeto, o nosso programa age como um analista financeiro. Ele recebe um banco de dados histórico com o preço do Bitcoin ao longo dos anos (`data.csv`) e, em seguida, lê um ficheiro de texto do utilizador contendo datas e quantidades de Bitcoin. O objetivo é calcular quanto valia aquela quantidade de Bitcoin naquela data específica.

O grande desafio? **Nem todas as datas que o utilizador pede existem no banco de dados.** Se pedirem o valor do dia `2012-01-03` e não houver registo, o programa tem de procurar a data válida mais próxima no passado.

---

## 1. A Escolha do Contêiner: Porquê o `std::map`?

Na STL (Standard Template Library), poderíamos usar um `std::vector` ou `std::list`, iterar desde o início e comparar as datas uma a uma. Mas isso é lento (complexidade $O(N)$). 

A escolha perfeita é o **`std::map<std::string, float>`**.
O `std::map` é estruturado internamente como uma *Red-Black Tree* (Árvore Binária de Busca Balanceada). Ele guarda os dados em pares chave-valor (`std::pair`).

O segredo aqui é o formato da data: `YYYY-MM-DD`. Como o ano vem primeiro, a ordem alfabética das strings corresponde **exatamente** à ordem cronológica. Ao inserirmos as datas no `std::map`, a árvore organiza-as automaticamente da mais antiga para a mais recente.

## 2. A Magia da Busca: `std::lower_bound`

Para encontrar o preço do Bitcoin numa data, usamos a função nativa do map: `map.lower_bound(data_pedida)`.
Esta função devolve um iterador que aponta para:
1. A data exata, se ela existir.
2. A data **imediatamente superior**, se a exata não existir.

Como o subject exige que peguemos na data mais próxima no **passado**, a nossa lógica é simples:
```cpp
std::map<std::string, float>::iterator it = database.lower_bound(date);

if (it->first != date) { // Se não encontrou a data exata
    if (it == database.begin()) {
        // Erro: A data pedida é mais antiga que o primeiro registo da nossa base de dados!
    } else {
        --it; // Recuamos um passo na árvore binária para obter a data anterior
    }
}
```
Com isto, a busca de uma data num ficheiro gigante cai para $O(\log N)$, sendo virtualmente instantânea.

## 3. Guia de Implementação e Parsing

A maior parte do código deste projeto destina-se a validar se o ficheiro de entrada não contém lixo. A implementação deve seguir estes passos:

1. **Carregar o `data.csv`:** Abrir o ficheiro com `std::ifstream`, ignorar o cabeçalho (`date,exchange_rate`), separar a linha pela vírgula e guardar no `std::map`.
2. **Ler o ficheiro de Input:** Ler o ficheiro do utilizador linha a linha.
3. **Validar o Formato (`YYYY-MM-DD | Valor`):**
* Confirmar se existem os hífens e o delimitador `|`.
* Validar se o ano, mês e dia são números válidos (ex: mês <= 12, dia <= 31). (Opcional, mas recomendado: verificar anos bissextos).


4. **Validar o Valor:** Converter a string para `float` ou `double`. Confirmar se não é negativo e se não excede `1000` (exigência do subject).
5. **Calcular:** Encontrar o valor no mapa (usando o `lower_bound` explicado acima), multiplicar pelo valor do input e imprimir no terminal.