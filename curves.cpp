#include "curves.h"

// Implementation of Circle methods
Circle::Circle(double radius) : radius(radius) {}
std::pair<double, double> Circle::getPointAndDerivative(double t) const {
    return {radius * cos(t), -radius * sin(t)};
}
double Circle::getRadius() const { return radius; }

// Implementation of Ellipse methods
Ellipse::Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}
std::pair<double, double> Ellipse::getPointAndDerivative(double t) const {
    return {radiusX * cos(t), -radiusY * sin(t)};
}

// Implementation of Helix methods
Helix::Helix(double radius, double step) : radius(radius), step(step) {}
std::pair<double, double> Helix::getPointAndDerivative(double t) const {
    return {radius * cos(t), radius * sin(t)};
}
