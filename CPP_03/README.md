Aqui tens o **README para o CPP Module 03**, no mesmo formato de texto normal para copiares.

---

# CPP Module 03

This is the fourth C++ module from the 42 School curriculum, focusing on Inheritance. This module involves creating a hierarchy of robots (ClapTrap, ScavTrap, FragTrap) to understand how attributes and behaviors are shared, extended, or overridden between parent and child classes.

## Table of Contents

* [Overview]()
* [Exercises]()
* [Exercise 00: Aaaaand... OPEN!]()
* [Exercise 01: Serena, my love!]()
* [Exercise 02: Repetitive work]()


* [Compilation]()
* [Usage]()

---

## Overview

This module introduces:

* **Inheritance**: Creating derived classes from base classes
* **Access Specifiers**: `public`, `protected`, and `private` visibility
* **Construction/Destruction Chaining**: Order of operations in inheritance
* **Virtual Destructors**: Preventing memory leaks in polymorphism
* **Multiple Inheritance**: Inheriting from more than one class

All exercises must be compiled with **C++98 standard** using the flags: `-Wall -Wextra -Werror -std=c++98`

---

## Exercises

### Exercise 00: Aaaaand... OPEN!

Creating the base class `ClapTrap`.

**Files:**

* `ex00/ClapTrap.hpp` / `ClapTrap.cpp` - Base robot class
* `ex00/main.cpp` - Test program

**Features:**

* **Attributes**: Name, Hit Points (10), Energy Points (10), Attack Damage (0)
* **Methods**: `attack()`, `takeDamage()`, `beRepaired()`
* **Logic**: Actions cost energy; cannot act if HP or Energy is 0
* **OCF**: Compliant with Orthodox Canonical Form

**Key Concepts:**

* **Class Design**: Encapsulation of robot state
* **Member Functions**: Logic validation (checking energy/HP before acting)
* **Constructors/Destructors**: Logging creation and destruction for debugging

---

### Exercise 01: Serena, my love!

Creating the `ScavTrap` class that inherits from `ClapTrap`.

**Files:**

* `ex01/ScavTrap.hpp` / `ScavTrap.cpp` - Derived class
* `ex01/main.cpp` - Test program

**Features:**

* **Inheritance**: `class ScavTrap : public ClapTrap`
* **New Stats**: HP (100), EP (50), AD (20)
* **New Method**: `guardGate()` (ScavTrap exclusive mode)
* **Override**: Custom `attack()` message
* **Protected attributes**: Using `protected` in base class to allow access by derived class

**Key Concepts:**

* **Constructor Chaining**: Calling base constructor first, then derived
* **Destructor Chaining**: Calling derived destructor first, then base
* **Protected Access**: Sharing data with children but hiding from the public
* **Virtual Destructors**: Essential for cleaning up derived classes via base pointers

---

### Exercise 02: Repetitive work

Creating the `FragTrap` class that also inherits from `ClapTrap`.

**Files:**

* `ex02/FragTrap.hpp` / `FragTrap.cpp` - Derived class
* `ex02/main.cpp` - Test program

**Features:**

* **Inheritance**: `class FragTrap : public ClapTrap`
* **New Stats**: HP (100), EP (100), AD (30)
* **New Method**: `highFivesGuys()` (Positive interaction request)
* **Construction**: Shows distinct construction chain from ScavTrap

**Key Concepts:**

* **Code Reusability**: Leveraging the base ClapTrap for common logic
* **Specialization**: Creating distinct robot types from a common ancestor
* **Polymorphism preparation**: Handling different types of traps

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
./claptrap

# Exercise 01
./scavtrap

# Exercise 02
./fragtrap

```

---

## Key C++ Concepts Demonstrated

1. **Inheritance Mechanics**
* Single Inheritance (`: public Base`)
* Multiple Inheritance (`: public A, public B`)


2. **Access Control**
* Understanding `private` vs `protected` vs `public` inheritance
* Encapsulation in hierarchies


3. **Polymorphism & Memory**
* Virtual destructors
* Upcasting and slicing (avoidance)


4. **Object Lifecycle**
* Construction order (Base -> Derived)
* Destruction order (Derived -> Base)
* Initialization lists in inheritance


5. **Scope Resolution**
* Resolving ambiguity using `Class::method`
* Shadowing variables in derived classes



---

**Project completed as part of the 42 School Common Core curriculum.**
