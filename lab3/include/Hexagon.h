#pragma once
#include "Figure.h"

class Hexagon : public Figure
{
private:
    vector<pair<double, double>> vertices;

public:
    Hexagon();
    Hexagon(const vector<pair<double, double>> &vertices);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;

    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;
    bool operator==(const Hexagon &other) const;

    pair<double, double> Center() const override;
    void Print(ostream &os) const override;
    void Read(istream &is) override;
    operator double() const override;
};