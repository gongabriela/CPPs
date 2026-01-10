# CPP Module 00

This is the first C++ module from the 42 School curriculum, introducing the basics of C++98 programming, including namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other fundamental concepts.

## Table of Contents

- [Overview](#overview)
- [Exercises](#exercises)
  - [Exercise 00: Megaphone](#exercise-00-megaphone)
  - [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
- [Compilation](#compilation)
- [Usage](#usage)

---

## Overview

This module focuses on:
- Understanding the differences between C and C++
- Learning about classes and objects
- Working with member attributes and member functions
- Using streams for I/O operations
- Implementing encapsulation (private vs public)
- Understanding references and const correctness

All exercises must be compiled with **C++98 standard** using the flags: `-Wall -Wextra -Werror -std=c++98`

---

## Exercises

### Exercise 00: Megaphone

A simple program that converts command-line arguments to uppercase.

**File:** `ex00/megaphone.cpp`

**Features:**
- Converts all characters of command-line arguments to uppercase
- If no arguments are provided, outputs: `* LOUD AND UNBEARABLE NOISE *`
- Demonstrates basic C++ I/O with `std::cout` and string manipulation

**Example:**
```bash
$ ./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...

$ ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.

$ ./megaphone
* LOUD AND UNBEARABLE NOISE *
```

---

### Exercise 01: My Awesome PhoneBook

A console-based phonebook application that stores up to 8 contacts using object-oriented programming principles.

**Files:**
- `ex01/PhoneBook.hpp` / `phonebook.cpp` - PhoneBook class implementation
- `ex01/Contact.hpp` / `contact.cpp` - Contact class implementation
- `ex01/main.cpp` - Main program loop

**Features:**

#### Contact Class
- Stores contact information (first name, last name, nickname, phone number, darkest secret)
- Implements proper encapsulation with private attributes and public getters
- Uses constructor with parameters for initialization

#### PhoneBook Class
- Stores up to 8 contacts in a circular buffer
- Implements three commands:
  - **ADD**: Adds a new contact (replaces oldest when full)
  - **SEARCH**: Displays all contacts in a formatted table and allows viewing details
  - **EXIT**: Closes the program

**Implementation Highlights:**
- **Encapsulation**: All contact data is private with getter methods
- **Const Correctness**: Methods that don't modify state are marked as `const`
- **Input Validation**: Empty fields are not accepted
- **Formatted Output**: Uses `std::setw()` and `std::iomanip` for column alignment
- **String Truncation**: Fields longer than 10 characters are truncated with a dot

**Example:**
```bash
$ ./phonebook
Welcome to the phonebook!
Choose a command (ADD, SEARCH, EXIT): ADD
Please fill out all contact information
first name: John
last name: Doe
nickname: JD
phone number: 555-1234
darkest secret: Afraid of the dark

Choose a command (ADD, SEARCH, EXIT): SEARCH
|     index|first name| last name|  nickname|
|         0|      John|       Doe|        JD|
Type an index to view further details or ENTER to leave this page: 0

======== CONTACT INFO ========
First name: John
Last name: Doe
Nickname: JD
Phone number: 555-1234
Darkest secret: Afraid of the dark
```

**Class Design:**
- **Private attributes**: Maintain state (contacts array, index, totalContacts)
- **Public methods**: Provide interface for user interaction
- **Helper methods**: `getInfo()`, `printContact()`, `formatField()` - private utilities
- **Constructor**: Initializes phonebook state and displays welcome message

---

## Compilation

Each exercise has its own Makefile. To compile:

```bash
# Exercise 00
cd ex00
make

# Exercise 01
cd ex01
make
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
./megaphone [arguments...]

# Exercise 01
./phonebook
# Then follow the interactive prompts
```

---

## Key C++ Concepts Demonstrated

1. **Classes and Objects**: Defining classes with attributes and methods
2. **Encapsulation**: Private data members with public interfaces
3. **Constructors**: Default and parameterized constructors
4. **Const Correctness**: Using `const` for methods and parameters
5. **References**: Passing by reference (`const std::string&`)
6. **I/O Streams**: Using `std::cout`, `std::cin`, and `std::getline`
7. **String Manipulation**: Working with `std::string` class
8. **Arrays**: Fixed-size array of objects
9. **Modular Design**: Separating declaration (`.hpp`) from implementation (`.cpp`)

---

**Project completed as part of the 42 School Common Core curriculum.**
