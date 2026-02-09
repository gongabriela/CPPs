#include <iostream>

class BadMemory {
public:
    int* data;

    // Constructor: Allocates memory
    BadMemory(int value) {
        this->data = new int(value);
        std::cout << "Constructor: Allocated memory at address " << this->data << std::endl;
    }

    // Destructor: Frees memory
    ~BadMemory() {
        std::cout << "Destructor: Freeing memory at address " << this->data << std::endl;
        delete this->data;
    }

    // WE DID NOT WRITE A COPY CONSTRUCTOR!
    // The compiler will generate a default one that just copies the pointer address.
};

int main() {
    std::cout << "--- 1. Creating object A ---" << std::endl;
    BadMemory a(42);

    std::cout << "\n--- 2. Creating object B as a copy of A ---" << std::endl;
    // The default copy constructor copies the address from a.data to b.data
    BadMemory b = a; 

    std::cout << "Address inside A: " << a.data << std::endl;
    std::cout << "Address inside B: " << b.data << " (They are the same!)" << std::endl;

    std::cout << "\n--- 3. Exiting scope ---" << std::endl;
    // Destructors are called automatically here.
    // b is destroyed first -> frees the address.
    // a is destroyed second -> tries to free the SAME address -> CRASH.
    
    return 0;
}