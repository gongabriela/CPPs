#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m'

cd "$(dirname "$0")/.." || exit 1

COPIED_DB=0
if [ ! -f data.csv ]; then
    cp db/data.csv data.csv && COPIED_DB=1
fi

echo -e "${BLUE}=== BUILDING THE PROJECT ===${NC}"
make re

echo -e "\n${BLUE}=== CREATING TEST FILES ===${NC}"

cat << EOF > test_valid.txt
date | value
2011-01-03 | 3
2011-01-03 | 1.2
2012-01-11 | 0
2012-01-11 | 1000
2012-02-29 | 5
EOF

cat << EOF > test_bad_dates.txt
date | value
2001-42-42 | 5
2013-02-29 | 5
2012-1-11 | 5
2012-01-11 | 5
2012/01/11 | 5
EOF

cat << EOF > test_bad_values.txt
date | value
2012-01-11 | -1
2012-01-11 | 1001
2012-01-11 | 2147483648
2012-01-11 |
2012-01-11 | abc
EOF

cat << EOF > test_bad_header.txt
Date | Value
2012-01-11 | 5
EOF
touch test_empty.txt

echo -e "${GREEN}[OK] Files created.${NC}\n"

echo -e "${BLUE}=== 1. VALID VALUES AND LIMITS ===${NC}"
echo "Expected: correct results, including the limits 0 and 1000 and February 29 (2012 is a leap year)."
./btc test_valid.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 2. INVALID DATES ===${NC}"
echo "Expected: 'bad input' for month 42, Feb 29 2013 (not a leap year), missing leading zeros and wrong separators; one valid control line."
./btc test_bad_dates.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 3. INVALID VALUES ===${NC}"
echo "Expected: 'not a positive number', 'too large a number' and 'not a valid number'."
./btc test_bad_values.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 4. FILE STRUCTURE ===${NC}"
echo "Expected: invalid header error."
./btc test_bad_header.txt
echo "Expected: empty file error."
./btc test_empty.txt
echo "Expected: missing file error."
./btc does_not_exist.txt
echo "----------------------------------------"

echo -e "${BLUE}=== 5. MEMORY CHECK (VALGRIND) ===${NC}"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./btc test_valid.txt 2>&1 | grep -E "ERROR SUMMARY|definitely lost|FILE DESCRIPTORS"

echo -e "\n${BLUE}=== CLEANING UP TEST FILES ===${NC}"
rm -f test_valid.txt test_bad_dates.txt test_bad_values.txt test_bad_header.txt test_empty.txt
if [ "$COPIED_DB" -eq 1 ]; then
    rm -f data.csv
fi
echo -e "${GREEN}[OK] Cleanup done.${NC}"
