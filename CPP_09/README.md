# CPP Module 09 — STL

The last module of the 42 C++ piscine. Each exercise must be solved with containers from the
**Standard Template Library**, and a container used in one exercise cannot be used again in the
rest of the module.

| Exercise | Program | Container(s) | What it does |
|---|---|---|---|
| [ex00](./ex00) | `btc` | `std::map` | Converts amounts of bitcoin into their value on a given date, using a CSV price history. |
| [ex01](./ex01) | `RPN` | `std::stack` on top of `std::list` | Evaluates expressions written in Reverse Polish Notation. |
| [ex02](./ex02) | `PmergeMe` | `std::vector` and `std::deque` | Sorts positive integers with the Ford-Johnson (merge-insertion) algorithm and compares both containers. |

All the code is written in C++98 and compiled with `c++ -Wall -Wextra -Werror -std=c++98`.

## Building

Each exercise has its own `Makefile`:

```sh
cd ex00 && make      # builds ./btc
cd ex01 && make      # builds ./RPN
cd ex02 && make      # builds ./PmergeMe
```

The usual rules are available: `make`, `make clean`, `make fclean` and `make re`.

## Usage

### ex00 — Bitcoin Exchange

`btc` reads the price history from `data.csv` in the directory it is run from. The files provided
with the subject are kept in `ex00/db/`; copy `data.csv` to the root of `ex00/` before running:

```
$ cp db/data.csv .
$ ./btc db/input_file.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
```

Each input line has the format `date | value`, with a valid `YYYY-MM-DD` date and a value between
0 and 1000. If the date is not in the database, the closest **earlier** date is used.

### ex01 — Reverse Polish Notation

```
$ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$ ./RPN "(1 + 1)"
Error
```

The input holds single-digit numbers and the operators `+ - * /`, separated by spaces. Errors are
printed on stderr.

### ex02 — PmergeMe

```
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 9 us
Time to process a range of 5 elements with std::deque  : 13 us
$ ./PmergeMe -1 2
Error
```

Each timing covers reading the input into the container and sorting it. The program handles at
least 3000 numbers, duplicates included.

## Project structure

```
CPP_09/
├── README.md
├── ex00/
│   ├── Makefile
│   ├── main.cpp
│   ├── BitcoinExchange.hpp
│   ├── BitcoinExchange.cpp
│   └── db/
│       ├── data.csv          # price history provided with the subject
│       ├── input_file.txt    # example input from the subject
│       └── tester.sh         # test script for btc
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── RPN.hpp
│   └── RPN.cpp
└── ex02/
    ├── Makefile
    ├── main.cpp
    ├── PmergeMe.hpp
    ├── PmergeMe.cpp
    └── tester.sh             # test script for PmergeMe
```

## Testing

```sh
bash ex00/db/tester.sh        # builds btc and runs valid/invalid inputs, plus valgrind
                              # (copies db/data.csv to ex00/ if it is not there, and removes it after)
cd ex02 && make && bash tester.sh
```

## Design notes

- **ex00** stores the price history in a `std::map<std::string, double>`. Dates in `YYYY-MM-DD`
  format sort alphabetically in chronological order, so `lower_bound` finds a date (or the one
  right after it) in $O(\log n)$.
- **ex01** uses `std::stack<int, std::list<int> >`. A plain `std::stack<int>` stores its data in a
  `std::deque`, which is reserved for ex02. Every operation is computed in `long long` and rejected
  if the result does not fit in an `int`.
- **ex02** has a separate Ford-Johnson implementation for each container. It sorts indices instead
  of values, so that every loser stays linked to its winner, and each binary search only covers the
  part of the chain before that winner. This keeps the number of comparisons within the
  theoretical limit of the algorithm.

A detailed explanation of each exercise is available in the repository wiki.

## References

| Exercise | Topic | Link |
|---|---|---|
| ex00 | Handling spreadsheet files in C++ (Stack Overflow) | https://stackoverflow.com/questions/69071462/how-to-handle-excel-files-using-c |
| ex00 | CSV file management in C++ (GeeksforGeeks) | https://www.geeksforgeeks.org/cpp/csv-file-management-using-c/ |
| ex00 | `std::ifstream` "incomplete type" error (Stack Overflow) | https://stackoverflow.com/questions/15080231/c-variable-stdifstream-ifs-has-initializer-but-incomplete-type |
| ex00 | Input/output with files (cplusplus.com) | https://cplusplus.com/doc/tutorial/files/ |
| ex00 | C++ files (W3Schools) | https://www.w3schools.com/cpp/cpp_files.asp |
| ex00 | Passing a file to a constructor to read it (Stack Overflow) | https://stackoverflow.com/questions/22026697/passing-a-file-to-constructor-to-read |
| ex01 | Reverse Polish notation (Wikipedia) | https://en.wikipedia.org/wiki/Reverse_Polish_notation |
| ex01 | `std::stack` (cppreference) | https://en.cppreference.com/cpp/container/stack |
| ex01 | Evaluating an expression in Reverse Polish Notation (GeeksforGeeks) | https://www.geeksforgeeks.org/dsa/evaluate-the-value-of-an-arithmetic-expression-in-reverse-polish-notation-in-java/ |
| ex02 | Merge-insertion sort (Wikipedia) | https://en.wikipedia.org/wiki/Merge-insertion_sort |
| ex02 | Binary search (Wikipedia) | https://en.wikipedia.org/wiki/Binary_search |
| ex02 | Step-by-step visualisation of the Ford-Johnson algorithm (dev.to) | https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91 |
| ex02 | Ford-Johnson algorithm video (YouTube) | https://www.youtube.com/watch?v=w1QXGe295sI |
