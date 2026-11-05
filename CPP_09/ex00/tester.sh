#!/bin/bash

# Cores para o output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}=== A COMPILAR O PROJETO ===${NC}"
make re

echo -e "\n${BLUE}=== A CRIAR FICHEIROS DE TESTE ===${NC}"

# 1. Teste de Sucesso (Valores e Limites permitidos)
cat << EOF > test_valid.txt
date | value
2011-01-03 | 3
2011-01-03 | 1.2
2012-01-11 | 0
2012-01-11 | 1000
2012-02-29 | 5
EOF

# 2. Teste de Datas Inválidas (Ano bissexto, mês 42, formatação)
cat << EOF > test_bad_dates.txt
date | value
2001-42-42 | 5
2013-02-29 | 5
2012-1-11 | 5
2012-01-11 | 5
2012/01/11 | 5
EOF

# 3. Teste de Valores Inválidos (Negativos, maiores que 1000, não-numéricos)
cat << EOF > test_bad_values.txt
date | value
2012-01-11 | -1
2012-01-11 | 1001
2012-01-11 | 2147483648
2012-01-11 | 
2012-01-11 | abc
EOF

# 4. Teste de Cabeçalho e Ficheiro Vazio
cat << EOF > test_bad_header.txt
data | valor
2012-01-11 | 5
EOF
touch test_empty.txt

echo -e "${GREEN}[OK] Ficheiros criados.${NC}\n"

echo -e "${BLUE}=== 1. TESTES DE SUCESSO E LIMITES ===${NC}"
echo "Espera-se: Cálculos corretos, incluindo o limite de 0, 1000 e o dia 29 de fevereiro (2012 é bissexto)."
./btc test_valid.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 2. TESTES DE DATAS INVÁLIDAS ===${NC}"
echo "Espera-se: Erros de 'bad input' para mês 42, 29 de fev de 2013 (não é bissexto), formatação sem zeros e separadores errados."
./btc test_bad_dates.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 3. TESTES DE VALORES INVÁLIDOS ===${NC}"
echo "Espera-se: Erros de 'not a positive number', 'too large a number' e 'bad input'."
./btc test_bad_values.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 4. TESTES DE ESTRUTURA DO FICHEIRO ===${NC}"
echo "Espera-se: Erro de cabeçalho inválido."
./btc test_bad_header.txt
echo "Espera-se: Erro de ficheiro vazio."
./btc test_empty.txt
echo "Espera-se: Erro de ficheiro inexistente."
./btc nao_existo.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 5. TESTE DE MEMÓRIA (VALGRIND) ===${NC}"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./btc test_valid.txt 2>&1 | grep -E "ERROR SUMMARY|definitely lost|FILE DESCRIPTORS"

echo -e "\n${BLUE}=== A LIMPAR FICHEIROS DE TESTE ===${NC}"
rm -f test_valid.txt test_bad_dates.txt test_bad_values.txt test_bad_header.txt test_empty.txt
echo -e "${GREEN}[OK] Limpeza concluída.${NC}"