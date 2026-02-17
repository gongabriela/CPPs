# CPP Module 02

This is the third C++ module from the 42 School curriculum, focusing on Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form (OCF). This module introduces the creation of a robust Fixed-Point number class to understand class mechanics deeply.

## Table of Contents

* [Overview]()
* [Exercises]()
* [Exercise 00: My First Class in Orthodox Canonical Form]()
* [Exercise 01: Towards a more useful fixed-point number class]()
* [Exercise 02: Now we’re talking]()


* [Compilation]()
* [Usage]()

---

## Overview

This module introduces:

* **Ad-hoc polymorphism**: Function and operator overloading
* **Operator Overloading**: Defining custom behaviors for standard operators (+, -, *, <<, etc.)
* **Orthodox Canonical Form (OCF)**: The standard class structure in C++98 (Constructor, Copy Constructor, Assignment Operator, Destructor)
* **Fixed-point arithmetic**: Precision management without floating-point errors
* **Static members**: Shared variables and functions across objects
* **Const correctness**: Proper use of const in member functions

All exercises must be compiled with **C++98 standard** using the flags: `-Wall -Wextra -Werror -std=c++98`

---

## Exercises

### Exercise 00: My First Class in Orthodox Canonical Form

Introduction to the Orthodox Canonical Form and basic Fixed-Point number representation.

**Files:**

* `ex00/Fixed.hpp` / `Fixed.cpp` - Fixed class
* `ex00/main.cpp` - Test program

**Features:**

* **Orthodox Canonical Form**: Implementation of Default Constructor, Copy Constructor, Copy Assignment Operator, and Destructor
* **Fixed-point storage**: Storing numbers as integers with fractional bits
* **getRawBits()**: Returns the raw integer value
* **setRawBits()**: Sets the raw integer value
* **Static constant**: `_fractionalBits` always set to 8

**Key Concepts:**

* **OCF**: Essential for memory management and object copying safety
* **Copy Semantics**: Deep copy vs Shallow copy
* **Self-assignment check**: Protecting objects during assignment (`if (this != &rhs)`)
* **Member function logging**: Tracking object life cycle

---

### Exercise 01: Towards a more useful fixed-point number class

Adding conversion capabilities between integers, floats, and fixed-point numbers.

**Files:**

* `ex01/Fixed.hpp` / `Fixed.cpp` - Enhanced Fixed class
* `ex01/main.cpp` - Test program

**Features:**

* **Int Constructor**: Converts integer to fixed-point using bitshifting
* **Float Constructor**: Converts float to fixed-point using scaling and rounding
* **toFloat()**: Converts fixed-point back to float
* **toInt()**: Converts fixed-point back to integer
* **Operator << overload**: Allows printing `Fixed` objects directly to `std::cout`

**Key Concepts:**

* **Bitwise operations**: Using `<<` and `>>` for fast multiplication/division by powers of 2
* **Stream Insertion Operator**: Overloading `std::ostream& operator<<`
* **Floating point precision**: Managing conversion accuracy
* **Roundf**: Rounding to nearest integer during conversion

---

### Exercise 02: Now we’re talking

Implementing a complete set of arithmetic and comparison operators.

**Files:**

* `ex02/Fixed.hpp` / `Fixed.cpp` - Fully functional Fixed class
* `ex02/main.cpp` - Test program

**Features:**

* **Comparison operators**: `>`, `<`, `>=`, `<=`, `==`, `!=`
* **Arithmetic operators**: `+`, `-`, `*`, `/`
* **Increment/Decrement**: Pre-increment (`++i`), Post-increment (`i++`), Pre-decrement, Post-decrement
* **Min/Max functions**: Static member functions to find the smallest/largest of two numbers (const and non-const versions)

**Key Concepts:**

* **Operator Overloading syntax**: Member functions vs Non-member functions
* **Pre vs Post Increment**: Returning reference vs returning copy (and the dummy `int` parameter)
* **Const Correctness**: Ensuring comparison operators don't modify the object
* **Static Member Functions**: Utility functions called on the class itself (`Fixed::max(a, b)`)
  
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

```

The Makefiles include:

* `make` - Compiles the program
* `make clean` - Removes object files
* `make fclean` - Removes object files and executable
* `make re` - Recompiles everything

---

## Usage

```bash
# Exercise 00
./fixed

# Exercise 01
./fixed

# Exercise 02
./fixed

```

---

## Key C++ Concepts Demonstrated

1. **Orthodox Canonical Form (OCF)**
* Ensuring classes are safe to copy and assign
* Managing resource lifecycles manually


2. **Operator Overloading**
* Making user-defined classes behave like built-in types
* Understanding `this` pointer and reference returns


3. **Fixed-Point Arithmetic**
* Bitwise manipulation (`<<`, `>>`)
* Performance optimization over floating-point math
* Precision handling


4. **Static Members**
* Variables shared across all instances
* Functions that operate without a specific object instance


5. **Const Correctness**
* Overload resolution based on const-ness
* `mutable` members (if applicable) and const methods



---

**Project completed as part of the 42 School Common Core curriculum.**
