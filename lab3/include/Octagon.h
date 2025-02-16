#pragma once
#include "Figure.h"

class Octagon : public Figure
{
private:
    vector<pair<double, double>> vertices;

public:
    Octagon();
    Octagon(const vector<pair<double, double>> &vertices);
    Octagon(const Octagon &other);
    Octagon(Octagon &&other) noexcept;

    Octagon &operator=(const Octagon &other);
    Octagon &operator=(Octagon &&other) noexcept;
    bool operator==(const Octagon &other) const;

    pair<double, double> Center() const override;
    void Print(ostream &os) const override;
    void Read(istream &is) override;
    operator double() const override;
};