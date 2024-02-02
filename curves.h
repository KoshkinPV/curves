// curves.h
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

class Curve3D {
public:
    virtual ~Curve3D() = default;
    virtual std::pair<double, double> getPointAndDerivative(double t) const = 0;
};

// Define the Circle class
class Circle : public Curve3D {
public:
    Circle(double radius);
    std::pair<double, double> getPointAndDerivative(double t) const override;
    double getRadius() const;

private:
    double radius;
};

// Define the Ellipse class
class Ellipse : public Curve3D {
public:
    Ellipse(double radiusX, double radiusY);
    std::pair<double, double> getPointAndDerivative(double t) const override;

private:
    double radiusX, radiusY;
};

// Define the Helix class
class Helix : public Curve3D {
public:
    Helix(double radius, double step);
    std::pair<double, double> getPointAndDerivative(double t) const override;

private:
    double radius, step;
};
