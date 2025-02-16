#include "../include/Octagon.h"
using namespace std;

Octagon::Octagon() : vertices(8) {}

Octagon::Octagon(const vector<pair<double, double>> &vertices) : vertices(vertices) {}

Octagon::Octagon(const Octagon &other) : vertices(other.vertices) {}

Octagon::Octagon(Octagon &&other) noexcept : vertices(move(other.vertices)) {}

Octagon &Octagon::operator=(const Octagon &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Octagon &Octagon::operator=(Octagon &&other) noexcept
{
    if (this != &other)
    {
        vertices = move(other.vertices);
    }
    return *this;
}

bool Octagon::operator==(const Octagon &other) const
{
    return vertices == other.vertices;
}

pair<double, double> Octagon::Center() const
{
    return PolygonCenter(vertices);
}

void Octagon::Print(ostream &os) const
{
    os << "Octagon vertices: ";
    for (const auto &vertex : vertices)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Octagon::Read(istream &is)
{
    vertices.resize(8);
    cout << "Введите 8 вершин через пробелы (x y): ";
    for (auto &vertex : vertices)
    {
        is >> vertex.first >> vertex.second;
    }
}

Octagon::operator double() const
{
    return PolygonArea(vertices);
}
