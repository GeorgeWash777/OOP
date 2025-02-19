#include <iostream>
#include "include/DynamicMemoryResource.h"
#include "include/Queue.h"

struct ComplexType {
    int a{};
    double b{};
    std::string c;
};

int main() {
    DynamicMemoryResource memory_resource;
    Queue<int> intQueue(&memory_resource);
    Queue<ComplexType> complexQueue(&memory_resource);

    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);

    std::cout << "Int Queue: ";
    for (int & it : intQueue) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    complexQueue.push({1, 2.2, "Hello"});
    complexQueue.push({2, 3.3, "World"});

    std::cout << "Complex Queue: ";
    for (auto & it : complexQueue) {
        std::cout << it.a << " " << it.b << " " << it.c << "; ";
    }
    std::cout << std::endl;

    return 0;
}
