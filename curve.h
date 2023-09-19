#pragma once
#include <cmath>
#include <iostream>

class Curve3D
{
public:
    virtual ~Curve3D() {}
    virtual void printPointAndDerivative(const double& t) = 0;
};

class Circle : public Curve3D
{
public:
    Circle();
    Circle(const double& _radius);

    void printPointAndDerivative(const double& t) override;
    
    double getRadius() const;
private:
    double radius;
};

class Ellipse : public Curve3D
{
public:
    Ellipse();
    Ellipse(const double& _a, const double& _b);

    void printPointAndDerivative(const double& t) override;

private:
    double a;
    double b;
};

class Helix : public Curve3D
{
public:
    Helix();
    Helix(const double& _radius, const double& _step);

    void printPointAndDerivative(const double& t) override;

private:
    double radius;
    double step;

};