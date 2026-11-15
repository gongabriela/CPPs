#!/bin/bash

GREEN="\033[32m"
RED="\033[31m"
BLUE="\033[36m"
YELLOW="\033[33m"
RESET="\033[0m"

EXEC="./PmergeMe"

if [ ! -f "$EXEC" ]; then
    echo -e "${RED}Error: executable $EXEC not found. Run 'make' first.${RESET}"
    exit 1
fi

echo -e "${BLUE}===================================================${RESET}"
echo -e "${BLUE}            PMERGEME TEST SUITE (ex02)             ${RESET}"
echo -e "${BLUE}===================================================${RESET}\n"

echo -e "${YELLOW}--- 1. ERROR HANDLING ---${RESET}"

echo "Test 1.1: No arguments"
$EXEC 2>/dev/null || echo -e "${GREEN}Passed! (returned an error)${RESET}"

echo "Test 1.2: Negative number (-5)"
$EXEC 1 2 -5 4 2>/dev/null || echo -e "${GREEN}Passed! (returned an error)${RESET}"

echo "Test 1.3: Letter in the sequence (3 a 5)"
$EXEC 3 a 5 2>/dev/null || echo -e "${GREEN}Passed! (returned an error)${RESET}"

echo "Test 1.4: Overflow (> INT_MAX: 2147483648)"
$EXEC 1 2 2147483648 3 2>/dev/null || echo -e "${GREEN}Passed! (returned an error)${RESET}\n"


echo -e "${YELLOW}--- 2. EDGE CASES AND DUPLICATES ---${RESET}"

echo "Test 2.1: A single number"
$EXEC 42 | grep "After"

echo -e "\nTest 2.2: Already sorted (1 2 3 4 5)"
$EXEC 1 2 3 4 5 | grep "After"

echo -e "\nTest 2.3: Reverse order (5 4 3 2 1)"
$EXEC 5 4 3 2 1 | grep "After"

echo -e "\nTest 2.4: Many duplicates (7 2 7 9 2 7 7)"
$EXEC 7 2 7 9 2 7 7 | grep "After"
echo ""


echo -e "${YELLOW}--- 3. STRESS AND PERFORMANCE ---${RESET}"

echo "Test 3.1: Subject example (5 elements)"
$EXEC 3 5 9 7 4
echo ""

echo "Test 3.2: 3000 numbers (required by the subject)"
NUMS_3K=$(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
$EXEC $NUMS_3K | grep "Time to process"
echo ""

echo "Test 3.3: 10000 numbers"
NUMS_10K=$(shuf -i 1-100000 -n 10000 | tr '\n' ' ')
$EXEC $NUMS_10K | grep "Time to process"
echo ""

echo -e "${GREEN}===================================================${RESET}"
echo -e "${GREEN}                TEST SUITE COMPLETE                ${RESET}"
echo -e "${GREEN}===================================================${RESET}"
