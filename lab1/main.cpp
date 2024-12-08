#include "include/lab1.h"

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
