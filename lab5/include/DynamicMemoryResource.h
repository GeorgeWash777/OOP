#ifndef DYNAMIC_MEMORY_RESOURCE_H
#define DYNAMIC_MEMORY_RESOURCE_H

#include <memory_resource>
#include <list>
#include <cstdlib> // Для std::malloc и std::free

class DynamicMemoryResource : public std::pmr::memory_resource {
private:
    std::list<void*> allocated_blocks;

public:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override {
        void* ptr = std::malloc(bytes);
        if (ptr) {
            allocated_blocks.push_back(ptr);
        }
        return ptr;
    }

    void do_deallocate(void* ptr, std::size_t bytes, std::size_t alignment) override {
        allocated_blocks.remove(ptr);
        std::free(ptr);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
        return this == &other;
    }

    ~DynamicMemoryResource() {
        for (void* ptr : allocated_blocks) {
            std::free(ptr);
        }
    }
};

#endif // DYNAMIC_MEMORY_RESOURCE_H
