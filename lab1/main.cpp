#include <iostream>
#include "include/lab1.h"


std::string intToBinary(long long n) {
    std::string binary = "";
    for(int i = 0; i < 32; i++) {
    if(n & (1 << i))
        binary = "1" + binary;
    else
        binary = "0" + binary;
    }
    return binary;
}

int main() {
    long long n;
    std::cout << "Введите число: ";
    std::cin >> n;
    std::string binary = intToBinary(n);
    for(char c : binary)
        std::cout << c;
    std::cout << '\n';
    return 0;
}

// чтобы забилдить/запустить
// mkdir -p build
// cd build
// cmake ..
// make
// ./lab1/lab1_exe
// ./lab1/lab1_tests
