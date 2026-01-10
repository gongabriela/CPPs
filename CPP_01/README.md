# CPP Module 01

This is the second C++ module from the 42 School curriculum, focusing on memory allocation, pointers to members, references, and the switch statement. This module deepens understanding of memory management and C++ specific features.

## Table of Contents

- [Overview](#overview)
- [Exercises](#exercises)
  - [Exercise 00: BraiiiiiiinnnzzzZ](#exercise-00-braiiiiiiinnnzzzzz)
  - [Exercise 01: Moar Brainz!](#exercise-01-moar-brainz)
  - [Exercise 02: HI THIS IS BRAIN](#exercise-02-hi-this-is-brain)
  - [Exercise 03: Unnecessary Violence](#exercise-03-unnecessary-violence)
  - [Exercise 04: Sed is for Losers](#exercise-04-sed-is-for-losers)
  - [Exercise 05: Harl 2.0](#exercise-05-harl-20)
- [Compilation](#compilation)
- [Usage](#usage)

---

## Overview

This module introduces:
- **Memory allocation**: Understanding stack vs heap allocation
- **new and delete**: C++ memory management operators
- **References**: Working with references vs pointers
- **Pointers to member functions**: Advanced function pointer concepts
- **File I/O**: Reading from and writing to files
- **String manipulation**: Advanced string operations

All exercises must be compiled with **C++98 standard** using the flags: `-Wall -Wextra -Werror -std=c++98`

---

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ

Understanding the difference between stack and heap allocation in C++.

**Files:**
- `ex00/Zombie.hpp` / `Zombie.cpp` - Zombie class
- `ex00/newZombie.cpp` - Creates zombie on the heap
- `ex00/randomChump.cpp` - Creates zombie on the stack
- `ex00/main.cpp` - Test program

**Features:**
- **Zombie class** with name attribute and `announce()` method
- **newZombie()**: Allocates a zombie on the heap using `new` - zombie survives outside function scope
- **randomChump()**: Creates a zombie on the stack - zombie is destroyed when function ends
- Demonstrates proper memory management with `delete`
- Shows when destructors are called

**Key Concepts:**
- **Stack allocation**: Automatic memory management, limited lifetime
- **Heap allocation**: Manual memory management with `new`/`delete`, persists until explicitly freed
- **new vs malloc**: `new` calls the constructor, `malloc` doesn't
- **Destructors**: Automatically called when objects go out of scope or are deleted

**Example:**
```bash
$ ./zombie
Creating a zombie in the heap: 
Constructor was called!
Gabi: BraiiiiiiinnnzzzZ...
Gabi was destroyed!
Creating a zombie in the stack: 
Constructor was called!
StackZombie: BraiiiiiiinnnzzzZ...
StackZombie was destroyed!
```

**When to use heap vs stack:**
- Use **heap** when the object needs to outlive the function scope
- Use **stack** for temporary objects with limited lifetime

---

### Exercise 01: Moar Brainz!

Creating an array of objects dynamically allocated in a single allocation.

**Files:**
- `ex01/Zombie.hpp` / `Zombie.cpp` - Zombie class
- `ex01/zombieHorde.cpp` - Creates array of N zombies
- `ex01/main.cpp` - Test program

**Features:**
- **zombieHorde(int N, std::string name)**: Allocates N zombies in a single allocation
- Uses `new[]` for array allocation
- Initializes all zombies with the same name
- Properly deallocates with `delete[]`

**Key Concepts:**
- **Array allocation**: Using `new[]` to allocate arrays on the heap
- **Array deallocation**: Must use `delete[]` (not just `delete`) to properly free array memory
- **Default constructor**: Required for array allocation
- **Post-initialization**: Setting attributes after construction

**Example:**
```bash
$ ./zombie_horde
Creating a zombie horde: 
Constructor was called!
Constructor was called!
...
gabi: BraiiiiiiinnnzzzZ...
gabi: BraiiiiiiinnnzzzZ...
...
Deleting the horde. . .
gabi was destroyed!
gabi was destroyed!
...
```

---

### Exercise 02: HI THIS IS BRAIN

Understanding the difference between pointers and references in C++.

**Files:**
- `ex02/main.cpp` - Demonstration program

**Features:**
- Creates a string variable
- Creates a pointer to the string
- Creates a reference to the string
- Displays memory addresses and values for all three

**Key Concepts:**
- **Pointers**: Store memory addresses, can be reassigned, use `*` to dereference
- **References**: Aliases for variables, cannot be reassigned, no special syntax to access value
- **Memory addresses**: Using `&` operator to get addresses
- **Dereferencing**: Using `*` to access value through a pointer

**Output:**
```bash
$ ./brain
memory address of the string variable: 0x7ffc...
memory adress held by stringPTR:       0x7ffc...
memory adress held by stringREF:       0x7ffc...
value of the string variable:          HI THIS IS BRAIN
value pointed to by stringPTR:         HI THIS IS BRAIN
value pointed to by stringREF:         HI THIS IS BRAIN
```

**Key Difference:**
- **Pointer**: Can be NULL, can change what it points to
- **Reference**: Must be initialized, always refers to the same object

---

### Exercise 03: Unnecessary Violence

Understanding when to use references vs pointers in class design.

**Files:**
- `ex03/Weapon.hpp` / `Weapon.cpp` - Weapon class
- `ex03/HumanA.hpp` / `HumanA.cpp` - Human that always has a weapon
- `ex03/HumanB.hpp` / `HumanB.cpp` - Human that may not have a weapon
- `ex03/main.cpp` - Test program

**Features:**

#### Weapon Class
- Stores weapon type as a string
- `getType()`: Returns weapon type by const reference
- `setType()`: Changes the weapon type

#### HumanA Class
- **Always armed**: Takes weapon in constructor
- Stores weapon as a **reference** (`Weapon& weapon`)
- Constructor: `HumanA(std::string name, Weapon& weapon)`
- `attack()`: Displays attack with current weapon type

#### HumanB Class
- **May be unarmed**: Doesn't take weapon in constructor
- Stores weapon as a **pointer** (`Weapon* weapon`)
- Constructor: `HumanB(std::string name)`
- `setWeapon()`: Assigns weapon later
- `attack()`: Displays attack if armed

**Key Concepts:**
- **Use references when**: The object must always exist (non-optional)
- **Use pointers when**: The object is optional (can be NULL)
- **Initialization lists**: Required to initialize references in constructors
- **Const references**: Efficient parameter passing without copying

**Example:**
```bash
$ ./violence
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```

---

### Exercise 04: Sed is for Losers

Creating a file manipulation program that replaces all occurrences of a string.

**Files:**
- `ex04/Replace.hpp` / `Replace.cpp` - String replacement functions
- `ex04/main.cpp` - Main program

**Features:**
- Takes 3 parameters: filename, string to find (s1), string to replace (s2)
- Opens and reads the entire file
- Replaces all occurrences of s1 with s2
- Creates a new file `<filename>.replace` with the modified content
- Error handling for file operations and empty parameters

**Implementation Highlights:**
- **File I/O**: Using `std::ifstream` and `std::ofstream`
- **String manipulation**: `find()`, `erase()`, `insert()` methods
- **std::stringstream**: Efficient file reading with `rdbuf()`
- **Error handling**: Checking if files can be opened
- **C++98 compatibility**: Using `.c_str()` for file operations

**Key Concepts:**
- **File streams**: Input/output file operations
- **String algorithms**: Finding and replacing substrings
- **size_t and npos**: String position handling
- **Buffer management**: Reading entire file into memory

**Example:**
```bash
$ echo "Hello world, hello everyone!" > test.txt
$ ./replace test.txt hello hi
$ cat test.replace
Hi world, hi everyone!

$ ./replace nonexistent.txt test test
Input file cannot be opened.

$ ./replace
Error: missing parameters
```

---

### Exercise 05: Harl 2.0

Using pointers to member functions to call different methods based on input.

**Files:**
- `ex05/Harl.hpp` / `Harl.cpp` - Harl class
- `ex05/main.cpp` - Test program

**Features:**

#### Harl Class
- Four private complaint methods:
  - `debug()`: Detailed diagnostic information
  - `info()`: General information
  - `warning()`: Warning messages
  - `error()`: Critical errors
- `complain(std::string level)`: Calls appropriate method based on level

**Implementation:**
- **Array of function pointers**: Stores pointers to member functions
- **Array of level names**: Matches strings to functions
- **Dynamic dispatch**: Selects and calls the correct function at runtime

**Key Concepts:**
- **Pointers to member functions**: `void (Class::*funcPtr)(void)`
- **Calling member function pointers**: `(this->*funcPtr)()`
- **Arrays of function pointers**: Creating dispatch tables
- **String comparison**: Finding the right function to call

**Syntax:**
```cpp
void (Harl::*ptrFunctions[])(void) = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
// Call: (this->*ptrFunctions[i])();
```

**Example:**
```bash
$ ./harl
--- TESTING VALID LEVELS ---
[ DEBUG ]
I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!
[ INFO ]
I cannot believe adding extra bacon costs more money...
[ WARNING ]
I think I deserve to have some extra bacon for free...
[ ERROR ]
This is unacceptable! I want to speak to the manager now.
```

---

## Compilation

Each exercise has its own Makefile. To compile:

```bash
# Exercise 00
cd ex00 && make

# Exercise 01
cd ex01 && make

# Exercise 02
cd ex02 && make

# Exercise 03
cd ex03 && make

# Exercise 04
cd ex04 && make

# Exercise 05
cd ex05 && make
```

The Makefiles include:
- `make` - Compiles the program
- `make clean` - Removes object files
- `make fclean` - Removes object files and executable
- `make re` - Recompiles everything

---

## Usage

```bash
# Exercise 00
./zombie

# Exercise 01
./zombie_horde

# Exercise 02
./brain

# Exercise 03
./violence

# Exercise 04
./replace <filename> <string_to_find> <string_to_replace>

# Exercise 05
./harl
```

---

## Key C++ Concepts Demonstrated

1. **Memory Management**
   - Stack vs Heap allocation
   - `new` and `delete` operators
   - `new[]` and `delete[]` for arrays

2. **Pointers vs References**
   - When to use each
   - Pointer syntax and dereferencing
   - Reference initialization and usage

3. **Object Lifetime**
   - Constructors and destructors
   - Automatic vs manual memory management
   - Scope and object destruction

4. **Advanced Features**
   - Pointers to member functions
   - Function dispatch tables
   - Const correctness with references

5. **File I/O**
   - Reading from files with `std::ifstream`
   - Writing to files with `std::ofstream`
   - Using `std::stringstream` for buffering

6. **String Manipulation**
   - `find()`, `erase()`, `insert()` methods
   - `std::string::npos` for position handling
   - Efficient string operations

---

**Project completed as part of the 42 School Common Core curriculum.**
