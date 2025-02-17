#pragma once

#include "figure.h"
#include "geometry_utils.h"
#include <vector>
#include <memory>

template <Scalar T>
class Hexagon : public Figure<T> {
    
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;

public:
    Hexagon();
    Hexagon(const std::vector<Point<T>> &points);
    Hexagon(const Hexagon<T> &other);
    Hexagon(Hexagon<T> &&other) noexcept;

    Hexagon<T> &operator=(const Hexagon<T> &other);
    Hexagon<T> &operator=(Hexagon<T> &&other) noexcept;
    bool operator==(const Hexagon<T> &other) const;

    std::unique_ptr<Point<double>> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};


template <Scalar T>
Hexagon<T>::Hexagon() {}

template <Scalar T>
Hexagon<T>::Hexagon(const std::vector<Point<T>> &points) {
    for (const auto &pt : points) {
        vertices.push_back(std::make_unique<Point<T>>(pt.x, pt.y));
    }
}

template <Scalar T>
Hexagon<T>::Hexagon(const Hexagon<T> &other) {
    for (const auto &pt : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
    }
}

template <Scalar T>
Hexagon<T>::Hexagon(Hexagon<T> &&other) noexcept : vertices(std::move(other.vertices)) {}

template <Scalar T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &other) {
    if (this != &other) {
        vertices.clear();
        for (const auto &pt : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
        }
    }
    return *this;
}

template <Scalar T>
Hexagon<T> &Hexagon<T>::operator=(Hexagon<T> &&other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template <Scalar T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const {
    if (vertices.size() != other.vertices.size()) {
        return false;
    }
    for (size_t i = 0; i < vertices.size(); ++i) {
        if (vertices[i]->x != other.vertices[i]->x || vertices[i]->y != other.vertices[i]->y) {
            return false;
        }
    }
    return true;
}

template <Scalar T>
std::unique_ptr<Point<double>> Hexagon<T>::Center() const {
    return PolygonCenter(vertices);
}

template <Scalar T>
void Hexagon<T>::Print(std::ostream &os) const {
    os << "Hexagon vertices: ";
    for (const auto &vertex : vertices) {
        os << *vertex << " ";
    }
    os << std::endl;
}

template <Scalar T>
void Hexagon<T>::Read(std::istream &is) {
    vertices.clear();
    std::cout << "Введите 6 вершин через пробел (x y): ";
    for (int i = 0; i < 6; ++i) {
        T x, y;
        is >> x >> y;
        vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template <Scalar T>
Hexagon<T>::operator double() const {
    return PolygonArea(vertices);
}