#pragma once

#include "figure.h"
#include "geometry_utils.h"
#include <vector>
#include <memory>

template <Scalar T>
class Octagon : public Figure<T> {
private:
    std::vector<std::unique_ptr<Point<T>>> vertices;
public:
    Octagon();
    Octagon(const std::vector<Point<T>> &points);
    Octagon(const Octagon<T> &other);
    Octagon(Octagon<T> &&other) noexcept;

    Octagon<T> &operator=(const Octagon<T> &other);
    Octagon<T> &operator=(Octagon<T> &&other) noexcept;
    bool operator==(const Octagon<T> &other) const;

    std::unique_ptr<Point<double>> Center() const override;
    void Print(std::ostream &os) const override;
    void Read(std::istream &is) override;
    operator double() const override;
};

template <Scalar T>
Octagon<T>::Octagon() {}

template <Scalar T>
Octagon<T>::Octagon(const std::vector<Point<T>> &points) {
    for (const auto &pt : points) {
        vertices.push_back(std::make_unique<Point<T>>(pt.x, pt.y));
    }
}

template <Scalar T>
Octagon<T>::Octagon(const Octagon<T> &other) {
    for (const auto &pt : other.vertices) {
        vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
    }
}

template <Scalar T>
Octagon<T>::Octagon(Octagon<T> &&other) noexcept : vertices(std::move(other.vertices)) {}

template <Scalar T>
Octagon<T> &Octagon<T>::operator=(const Octagon<T> &other) {
    if (this != &other) {
        vertices.clear();
        for (const auto &pt : other.vertices) {
            vertices.push_back(std::make_unique<Point<T>>(pt->x, pt->y));
        }
    }
    return *this;
}

template <Scalar T>
Octagon<T> &Octagon<T>::operator=(Octagon<T> &&other) noexcept {
    if (this != &other) {
        vertices = std::move(other.vertices);
    }
    return *this;
}

template <Scalar T>
bool Octagon<T>::operator==(const Octagon<T> &other) const {
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
std::unique_ptr<Point<double>> Octagon<T>::Center() const {
    return PolygonCenter(vertices);
}

template <Scalar T>
void Octagon<T>::Print(std::ostream &os) const {
    os << "Octagon vertices: ";
    for (const auto &vertex : vertices) {
        os << *vertex << " ";
    }
    os << std::endl;
}

template <Scalar T>
void Octagon<T>::Read(std::istream &is) {
    vertices.clear();
    std::cout << "Введите 8 вершин через пробел (x y): ";
    for (int i = 0; i < 8; ++i) {
        T x, y;
        is >> x >> y;
        vertices.push_back(std::make_unique<Point<T>>(x, y));
    }
}

template <Scalar T>
Octagon<T>::operator double() const {
    return std::abs(PolygonArea(vertices));
}