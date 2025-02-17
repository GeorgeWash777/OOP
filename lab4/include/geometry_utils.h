#pragma once

#include <vector>
#include <memory>
#include <cmath>
#include "point.h"
#include "concepts.h"

template<Scalar T>
double PolygonArea(const std::vector<std::unique_ptr<Point<T>>>& vertices){
    double a=0.0;
    const size_t n=vertices.size();
    for(size_t i=0;i<n;++i){
        const double x1=static_cast<double>(vertices[i]->x),
                     y1=static_cast<double>(vertices[i]->y),
                     x2=static_cast<double>(vertices[(i+1)%n]->x),
                     y2=static_cast<double>(vertices[(i+1)%n]->y);
        a+=(x1*y2)-(x2*y1);
    }
    return a / 2.0; 
}

template<Scalar T>
std::unique_ptr<Point<double>> PolygonCenter(
    const std::vector<std::unique_ptr<Point<T>>>& vertices)
{
    double cx=0.0, cy=0.0;
    const double area=PolygonArea(vertices);
    const size_t n=vertices.size();
    const double f=1.0/(6.0*area);
    
    for(size_t i=0;i<n;++i){
        const double xi=static_cast<double>(vertices[i]->x),
                     yi=static_cast<double>(vertices[i]->y),
                     xi1=static_cast<double>(vertices[(i+1)%n]->x),
                     yi1=static_cast<double>(vertices[(i+1)%n]->y),
                     cross=(xi*yi1)-(xi1*yi);
        
        cx+=(xi+xi1)*cross;
        cy+=(yi+yi1)*cross;
    }
    
    cx*=f;
    cy*=f;
    return std::make_unique<Point<double>>(cx,cy);
}