#!/bin/bash

# Cores para o output ficar bonito no terminal
GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[36m"
YELLOW="\033[33m"
RESET="\033[0m"

EXEC="./PmergeMe"

# Verificar se o executável existe (lembre-se de fazer 'make' primeiro)
if [ ! -f "$EXEC" ]; then
    echo -e "${RED}Erro: O executável $EXEC não foi encontrado. Execute 'make' primeiro.${RESET}"
    exit 1
fi

echo -e "${BLUE}===================================================${RESET}"
echo -e "${BLUE}        BATERIA DE TESTES - PMERGEME (ex02)        ${RESET}"
echo -e "${BLUE}===================================================${RESET}\n"

# 1. TESTES DE ERRO (Devem imprimir "Error")
echo -e "${YELLOW}--- 1. TESTES DE ERRO E EXCEÇÕES ---${RESET}"

echo "Teste 1.1: Sem argumentos"
$EXEC 2>/dev/null || echo -e "${GREEN}Passou! (Retornou erro)${RESET}"

echo "Teste 1.2: Números negativos (-5)"
$EXEC 1 2 -5 4 2>/dev/null || echo -e "${GREEN}Passou! (Retornou erro)${RESET}"

echo "Teste 1.3: Letras no meio (3 a 5)"
$EXEC 3 a 5 2>/dev/null || echo -e "${GREEN}Passou! (Retornou erro)${RESET}"

echo "Teste 1.4: Overflow (> INT_MAX: 2147483648)"
$EXEC 1 2 2147483648 3 2>/dev/null || echo -e "${GREEN}Passou! (Retornou erro)${RESET}\n"


# 2. CASOS LIMITE E DUPLICADOS
echo -e "${YELLOW}--- 2. CASOS LIMITE E DUPLICADOS ---${RESET}"

echo "Teste 2.1: Apenas 1 número"
$EXEC 42 | grep "After"

echo -e "\nTeste 2.2: Já ordenado (1 2 3 4 5)"
$EXEC 1 2 3 4 5 | grep "After"

echo -e "\nTeste 2.3: Ordem inversa (5 4 3 2 1)"
$EXEC 5 4 3 2 1 | grep "After"

echo -e "\nTeste 2.4: Muitos duplicados (7 2 7 9 2 7 7)"
$EXEC 7 2 7 9 2 7 7 | grep "After"
echo ""


# 3. TESTES DE STRESS (Requisitos do Subject)
echo -e "${YELLOW}--- 3. TESTES DE STRESS E PERFORMANCE ---${RESET}"

# Teste com 5 elementos (Subject example)
echo "Teste 3.1: Exemplo do Subject (5 elementos)"
$EXEC 3 5 9 7 4
echo ""

# Teste com 3000 elementos
echo "Teste 3.2: O teste dos 3000 números (Exigido pelo Subject)"
# shuf gera 3000 números aleatórios entre 1 e 100000, o tr tira as quebras de linha
NUMS_3K=$(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
$EXEC $NUMS_3K | grep "Time to process"
echo ""

# Teste bônus brutal com 10.000 elementos
echo "Teste 3.3: O Teste de Ferro (10.000 números)"
NUMS_10K=$(shuf -i 1-100000 -n 10000 | tr '\n' ' ')
$EXEC $NUMS_10K | grep "Time to process"
echo ""

echo -e "${GREEN}===================================================${RESET}"
echo -e "${GREEN}             BATERIA DE TESTES CONCLUÍDA           ${RESET}"
echo -e "${GREEN}===================================================${RESET}"