#ifndef QUEUE_H
#define QUEUE_H

#include <memory_resource>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& val, Node* nxt = nullptr) : value(val), next(nxt) {}
    };

    Node* head;
    Node* tail;
    size_t queueSize;
    std::pmr::memory_resource* resource;

public:
    explicit Queue(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
        : head(nullptr), tail(nullptr), queueSize(0), resource(resource) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    void push(const T& value) {
        void* memory = resource->allocate(sizeof(Node));
        Node* newNode = new (memory) Node(value);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        ++queueSize;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        Node* oldHead = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        oldHead->~Node();
        resource->deallocate(oldHead, sizeof(Node));
        --queueSize;
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return head->value;
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return head->value;
    }

    bool empty() const {
        return queueSize == 0;
    }

    size_t size() const {
        return queueSize;
    }

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        iterator(Node* node = nullptr) : current(node) {}

        reference operator*() const {
            return current->value;
        }

        pointer operator->() {
            return &current->value;
        }

        iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator retval = *this;
            ++(*this);
            return retval;
        }

        friend bool operator==(const iterator& a, const iterator& b) {
            return a.current == b.current;
        }

        friend bool operator!=(const iterator& a, const iterator& b) {
            return a.current != b.current;
        }

    private:
        Node* current;
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

#endif // QUEUE_H




// #ifndef QUEUE_H
// #define QUEUE_H

// #include <deque>
// #include <memory_resource>
// #include <memory>

// template <typename T>
// class Queue {
// private:
//     std::pmr::deque<T> data;

// public:
//     explicit Queue(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
//             : data(std::pmr::deque<T>(resource)) {}

//     void push(const T& value) {
//         data.push_back(value);
//     }

//     void pop() {
//         data.pop_front();
//     }

//     T& front() {
//         return data.front();
//     }

//     const T& front() const {
//         return data.front();
//     }

//     bool empty() const {
//         return data.empty();
//     }

//     size_t size() const {
//         return data.size();
//     }

//     class iterator {
//     public:
//         using iterator_category = std::forward_iterator_tag;
//         using difference_type = std::ptrdiff_t;
//         using value_type = T;
//         using pointer = T*;
//         using reference = T&;

//         iterator(typename std::pmr::deque<T>::iterator it) : current(it) {}

//         reference operator*() const {
//             return *current;
//         }

//         pointer operator->() {
//             return &**this;
//         }

//         iterator& operator++() {
//             ++current;
//             return *this;
//         }

//         iterator operator++(int) {
//             iterator retval = *this;
//             ++(*this);
//             return retval;
//         }

//         friend bool operator==(const iterator& a, const iterator& b) {
//             return a.current == b.current;
//         }

//         friend bool operator!=(const iterator& a, const iterator& b) {
//             return a.current != b.current;
//         }

//     private:
//         typename std::pmr::deque<T>::iterator current;
//     };

//     iterator begin() {
//         return iterator(data.begin());
//     }

//     iterator end() {
//         return iterator(data.end());
//     }
// };

// #endif // QUEUE_H
