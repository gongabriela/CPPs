# C++ Modules - 42 School

This repository contains my solutions to the C++ modules from the 42 School Common Core curriculum. These modules provide a comprehensive introduction to C++ programming, covering fundamental concepts from basic syntax to advanced object-oriented programming principles.

## 📚 Modules Overview

### ✅ [CPP Module 00](./CPP_00) - Introduction to C++
Introduction to C++ basics, including namespaces, classes, member functions, stdio streams, initialization lists, static, and const.

**Topics covered:**
- Namespaces and classes
- Member attributes and functions
- I/O streams (`std::cout`, `std::cin`)
- Encapsulation (public/private)
- References and const correctness

**Exercises:**
- **ex00**: Megaphone - String manipulation and I/O
- **ex01**: PhoneBook - First OOP project with classes

---

### ✅ [CPP Module 01](./CPP_01) - Memory Allocation and References
Deep dive into memory management, pointers, references, and understanding the differences between stack and heap allocation.

**Topics covered:**
- Memory allocation (`new`/`delete`)
- Stack vs Heap
- Pointers vs References
- Pointers to member functions
- File I/O and string manipulation

**Exercises:**
- **ex00**: BraiiiiiiinnnzzzZ - Stack vs Heap allocation
- **ex01**: Moar Brainz! - Array allocation
- **ex02**: HI THIS IS BRAIN - Pointers and references
- **ex03**: Unnecessary Violence - References vs pointers in class design
- **ex04**: Sed is for Losers - File manipulation
- **ex05**: Harl 2.0 - Pointers to member functions

---

### ✅ [CPP Module 02](./CPP_02) - Ad-hoc Polymorphism, Operator Overloading and Orthodoxy
Introduction to Ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form (OCF). This module focuses on creating a robust Fixed-Point number class to understand class mechanics deeply.

**Topics covered:**
- Ad-hoc polymorphism (Operator Overloading)
- Orthodox Canonical Form (Default constructor, Copy constructor, Copy assignment operator, Destructor)
- Fixed-point arithmetic vs Floating-point
- `const` correctness in member functions

**Exercises:**
- **ex00**: My First Class in Orthodox Canonical Form - Fixed point class basics
- **ex01**: Towards a more useful fixed-point number class - Bit shifting and int/float conversion
- **ex02**: Now we’re talking - Overloading arithmetic, comparison, and increment/decrement operators

---

### ✅ [CPP Module 03](./CPP_03) - Inheritance
Introduction to Inheritance in C++. This module involves creating a hierarchy of robots (ClapTrap, ScavTrap, FragTrap, DiamondTrap) to understand how attributes and behaviors are shared, extended, or overridden between parent and child classes.

**Topics covered:**
- Inheritance mechanics (Single and Multiple)
- Access specifiers (`public`, `protected`, `private`)
- Constructor and Destructor chaining
- Virtual destructors and memory management in inheritance

**Exercises:**
- **ex00**: Aaaaand... OPEN! - Creating the base ClapTrap class
- **ex01**: Serena, my love! - Creating ScavTrap (Inheritance and Guard Gate)
- **ex02**: Repetitive work - Creating FragTrap (Inheritance and High Fives)

---

### ✅ CPP Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces
Introduction to subtype polymorphism, abstract classes, and interfaces in C++. This module explores how to use virtual functions to achieve dynamic binding and interface implementation.

**Topics covered:**
- Subtype polymorphism
- Abstract classes and pure virtual functions
- Interfaces
- Deep copies with polymorphic classes

**Exercises:**
- **ex00**: Polymorphism - Base and derived classes (`Animal`, `Dog`, `Cat`)
- **ex01**: I don’t want to set the world on fire - Deep copy and memory management (`Brain`)
- **ex02**: Abstract class - Preventing instantiation of base classes
- **ex03**: Interface & recap - Comprehensive exercise with Materias and Interfaces

---

### ✅ CPP Module 05 - Repetition and Exceptions
Introduction to exception handling in C++. This module focuses on using `try`, `catch`, and custom exception classes to handle runtime errors gracefully.

**Topics covered:**
- Exception handling (`try`, `catch`, `throw`)
- Standard exceptions (`std::exception`)
- Custom nested exception classes (e.g., `GradeTooHighException`)

**Exercises:**
- **ex00**: Mommy, when I grow up, I want to be a bureaucrat! - Basic exceptions with the `Bureaucrat` class
- **ex01**: Form up, maggots! - The `Form` class and signing logic
- **ex02**: No, you need form 28B, not 28C... - Concrete executable forms (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`)
- **ex03**: At least this beat coffee making - The `Intern` class creating forms dynamically

---

### ✅ CPP Module 06 - C++ Casts
Deeply understand the different casting operators available in C++ (`static_cast`, `reinterpret_cast`, and `dynamic_cast`), moving away from the traditional C-style casts.

**Topics covered:**
- `static_cast` for well-defined logical conversions
- `reinterpret_cast` for raw memory manipulation
- `dynamic_cast` for Run-Time Type Identification (RTTI)
- Object serialization and deserialization

**Exercises:**
- **ex00**: Scalar Converter - Parsing strings and converting between scalar types
- **ex01**: Serialization - Simulating serialization using `uintptr_t`
- **ex02**: Identify Real Type - Identifying true object types at run-time without `<typeinfo>`

---

### 🚧 More Modules Coming Soon...

---

## 🛠️ Compilation

All modules are compiled with **C++98 standard** using:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Each module and exercise contains its own `Makefile` for easy compilation:
```bash
cd CPP_XX/exXX
make
```

---

## 🧠 Knowledge Base & Wiki

Beyond the code implementation, I have documented the theoretical concepts, logic, and "gotchas" of each module in the repository's **Wiki**. 

This documentation serves as a study guide for students who want to understand the *why* behind the code, covering topics such as:

* **Memory Management:** Stack vs Heap, `new`/`delete`, and deep copies.
* **OOP Principles:** Encapsulation, Inheritance, and Polymorphism.
* **C++ Specifics:** Orthodox Canonical Form, Virtual Destructors, and References.
* **Math & Logic:** Fixed-Point arithmetic and bitwise operations.

👉 **[Click here to access the Wiki](https://github.com/gongabriela/CPPs/wiki)** and dive deeper into the concepts!

---

## 🎯 Learning Objectives

These modules aim to teach:
1. **Fundamentals**: Basic C++ syntax and features
2. **OOP**: Classes, inheritance, polymorphism
3. **Memory**: Proper memory management and resource handling
4. **Best Practices**: Writing clean, efficient, and maintainable C++ code

---

**42 School - Common Core**  
*Each module builds upon the previous one, creating a solid foundation in C++ programming.*
