#include "../include/Hexagon.h"
using namespace std;

Hexagon::Hexagon() : vertices(6) {}

Hexagon::Hexagon(const vector<pair<double, double>> &vertices) : vertices(vertices) {}

Hexagon::Hexagon(const Hexagon &other) : vertices(other.vertices) {}

Hexagon::Hexagon(Hexagon &&other) noexcept : vertices(move(other.vertices)) {}

Hexagon &Hexagon::operator=(const Hexagon &other)
{
    if (this != &other)
    {
        vertices = other.vertices;
    }
    return *this;
}

Hexagon &Hexagon::operator=(Hexagon &&other) noexcept
{
    if (this != &other)
    {
        vertices = move(other.vertices);
    }
    return *this;
}

bool Hexagon::operator==(const Hexagon &other) const
{
    return vertices == other.vertices;
}

pair<double, double> Hexagon::Center() const
{
    return PolygonCenter(vertices);
}

void Hexagon::Print(ostream &os) const
{
    os << "Hexagon vertices: ";
    for (const auto &vertex : vertices)
    {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Hexagon::Read(istream &is)
{
    vertices.resize(6);
    cout << "Введите 6 вершин через пробел (x y): ";
    for (auto &vertex : vertices)
    {
        is >> vertex.first >> vertex.second;
    }
}

Hexagon::operator double() const
{
    return PolygonArea(vertices);
}
