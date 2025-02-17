#pragma once

#include <memory>
#include <stdexcept>

template <class T>
class Array 
{
private:
    size_t _capacity;
    size_t _size;
    std::unique_ptr<std::shared_ptr<T>[]> _data;

    void _resize() 
    {
        size_t newCapacity = _capacity * 2;
        std::unique_ptr<std::shared_ptr<T>[]> newData(new std::shared_ptr<T>[newCapacity]);

        for (size_t i = 0; i < _size; ++i) 
        {
            newData[i] = std::move(_data[i]);
        }

        _data = std::move(newData);
        _capacity = newCapacity;
    }

public:
    Array() : _capacity(4), _size(0), _data(new std::shared_ptr<T>[_capacity]) {}

    void push_back(std::shared_ptr<T> value) 
    {
        if (_size == _capacity) 
        {
            _resize();
        }
        _data[_size++] = std::move(value);
    }

    void remove_at(size_t index) 
    {
        if (index >= _size) 
        {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }

        for (size_t i = index; i < _size - 1; ++i) 
        {
            _data[i] = std::move(_data[i + 1]);
        }

        _data[_size - 1].reset();
        --_size;
    }

    size_t get_size() const 
    {
        return _size;
    }

    std::shared_ptr<T>& operator[](size_t index) 
    {
        if (index >= _size) 
        {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return _data[index];
    }

    const std::shared_ptr<T>& operator[](size_t index) const 
    {
        if (index >= _size) 
        {
            throw std::out_of_range("Индекс вне допустимого диапазона");
        }
        return _data[index];
    }
};