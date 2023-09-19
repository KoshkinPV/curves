#include "curve.h"

Circle::Circle()
    : radius(0)
{

}

Circle::Circle(const double& _radius)
    : radius(_radius)
{

}

void Circle::printPointAndDerivative(const double& t)
{
    // point
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = 0;

    std::cout << "Point: (" << x << ", " << y << ", " << z << ")" << std::endl;

    double dx_dt = -radius * sin(t);
    double dy_dt = radius * cos(t);
    double dz_dt = 0; 
    std::cout << "Derivative: (" << dx_dt << ", " << dy_dt << ", " << dz_dt << ")" << std::endl;
}

double Circle::getRadius() const
{
    return radius;
}

Ellipse::Ellipse()
    : a(0),
    b(0)
{

}

Ellipse::Ellipse(const double& _a, const double& _b)
    : a(_a),
    b(_b)
{

}

void Ellipse::printPointAndDerivative(const double& t)
{
    double x = a * cos(t);
    double y = b * sin(t);
    double z = 0;

    std::cout << "Point: (" << x << ", " << y << ", " << z << ")" << std::endl;

    double dx_dt = -a * sin(t);
    double dy_dt = b * cos(t);
    double dz_dt = 0; 

    std::cout << "Derivative: (" << dx_dt << ", " << dy_dt << ", " << dz_dt << ")" << std::endl;
}

Helix::Helix()
    : radius(0),
    step(0)
{

}

Helix::Helix(const double& _radius, const double& _step)
    : radius(_radius),
    step(_step)
{

}

void Helix::printPointAndDerivative(const double& t)
{
    //Point
    double x = radius * cos(t);
    double y = radius * sin(t);
    double z = step * t;

    std::cout << "Point: (" << x << ", " << y << ", " << z << ")" << std::endl;

    // Derivative
    double dx_dt = -radius * sin(t);
    double dy_dt = radius * cos(t);
    double dz_dt = step;

    std::cout << "Derivative: (" << dx_dt << ", " << dy_dt << ", " << dz_dt << ")" << std::endl;
}
