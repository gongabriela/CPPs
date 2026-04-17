# C++ Module 06 - C++ Casts

## 📖 Overview
This repository contains the solutions for **C++ Module 06** from the 42 School curriculum. The primary objective of this module is to deeply understand the different casting operators available in C++ (`static_cast`, `reinterpret_cast`, and `dynamic_cast`), moving away from the traditional C-style casts. 

By the end of this module, the goal is to understand not just *how* to convert data, but *when* and *why* to use specific casts for mathematical conversions, memory manipulation, and run-time type identification.

---

## 🛠️ Exercises Breakdown

### Exercise 00: Scalar Converter
**Purpose:**
To build a static class capable of parsing a string representation of a C++ scalar type (`char`, `int`, `float`, or `double`) and converting it into its actual numeric value, before casting it to the other three scalar types. 

**What I Learned:**
* **`static_cast`:** Used for well-defined, logical conversions between related types (e.g., truncating a `float` to an `int`, or finding the ASCII character of an `int`).
* **Parsing & Validation:** Building a robust state machine to identify data types from raw strings without relying on heavy external libraries.
* **Memory Limits & Overflows:** Using `<limits>` (`std::numeric_limits`) to protect the program from silent memory overflows when casting massive numbers into smaller types like `int` or `char`.
* **Standard Library Tools:** Utilizing `<cstdlib>` (`std::strtod`) for safe string-to-number extraction, and `<iomanip>` (`std::setprecision`, `std::fixed`) to format terminal output correctly.
* **Edge Cases:** Handling special floating-point pseudo-literals (`-inff`, `+inff`, `nanf`, `-inf`, `+inf`, `nan`).

### Exercise 01: Serialization
**Purpose:**
To simulate the process of serialization and deserialization by taking a pointer to a data structure, converting it to an unsigned integer type, and then reverting it back to a usable pointer.

**What I Learned:**
* **`reinterpret_cast`:** The most dangerous and powerful cast in C++. It performs no mathematical conversion; it simply instructs the compiler to treat a specific sequence of bits in memory as a completely different type.
* **`uintptr_t`:** A special unsigned integer type guaranteed to be large enough to hold a pointer safely, preventing data loss (overflows) on different system architectures (e.g., 32-bit vs 64-bit systems).
* **Memory Addresses:** Understanding that a pointer is ultimately just a numeric address in the physical memory.

### Exercise 02: Identify Real Type
**Purpose:**
To create a polymorphic base class and randomly generate derived classes (`A`, `B`, or `C`). The challenge is to identify the true identity of the object at run-time, given only a `Base` pointer or reference, without using the `<typeinfo>` header.

**What I Learned:**
* **RTTI (Run-Time Type Information):** Understanding that C++ needs a virtual method (like a virtual destructor) in the base class to generate a `vtable`, which allows the program to remember object identities while running.
* **`dynamic_cast`:** The only cast that happens at run-time. It safely downcasts polymorphic objects.
* **Pointers vs. References (The Core Trap):** * When `dynamic_cast` fails with a **pointer**, it gracefully returns `NULL`.
  * Because C++ does not allow null references, when `dynamic_cast` fails with a **reference**, it throws a `std::bad_cast` exception.
* **Exception Handling:** Using `try { ... } catch (std::exception& e) { ... }` blocks to cleanly figure out an object's identity by process of elimination without crashing the program.

---

## 🚀 Compilation & Usage

Each exercise is contained within its own directory. 
Navigate to the desired exercise folder and compile using the provided `Makefile`.

### Ex00: Scalar Converter
```bash
cd ex00
make
./convert 0
./convert nan
./convert 42.0f
```

### Ex01: Serializer
```bash
cd ex01
make
./serialize
```

### Ex02: Identify Real Type
```bash
cd ex02
make
./identify_real_type
```

## ⚙️ Compilation Flags
All programs are compiled using strict 42 norms:
`c++ -Wall -Wextra -Werror -std=c++98`

---

*This project was completed as part of the 42 School Core Curriculum.*