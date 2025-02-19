#ifndef QUEUE_H
#define QUEUE_H

#include <deque>
#include <memory_resource>
#include <memory>

template <typename T>
class Queue {
private:
    std::pmr::deque<T> data;

public:
    explicit Queue(std::pmr::memory_resource* resource = std::pmr::get_default_resource())
            : data(std::pmr::deque<T>(resource)) {}

    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        data.pop_front();
    }

    T& front() {
        return data.front();
    }

    const T& front() const {
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        iterator(typename std::pmr::deque<T>::iterator it) : current(it) {}

        reference operator*() const {
            return *current;
        }

        pointer operator->() {
            return &**this;
        }

        iterator& operator++() {
            ++current;
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
        typename std::pmr::deque<T>::iterator current;
    };

    iterator begin() {
        return iterator(data.begin());
    }

    iterator end() {
        return iterator(data.end());
    }
};

#endif // QUEUE_H
