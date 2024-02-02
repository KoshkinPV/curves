#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define the base class for 3D curves
class Curve3D {
public:
    virtual ~Curve3D() = default;
    virtual std::pair<double, double> getPointAndDerivative(double t) const = 0;
};

// Define the Circle class
class Circle : public Curve3D {
public:
    Circle(double radius) : radius(radius) {}
    std::pair<double, double> getPointAndDerivative(double t) const override {
        return {radius * cos(t), -radius * sin(t)};
    }
    double getRadius() const { return radius; }

private:
    double radius;
};

// Define the Ellipse class
class Ellipse : public Curve3D {
public:
    Ellipse(double radiusX, double radiusY) : radiusX(radiusX), radiusY(radiusY) {}
    std::pair<double, double> getPointAndDerivative(double t) const override {
        return {radiusX * cos(t), -radiusY * sin(t)};
    }

private:
    double radiusX, radiusY;
};

// Define the Helix class
class Helix : public Curve3D {
public:
    Helix(double radius, double step) : radius(radius), step(step) {}
    std::pair<double, double> getPointAndDerivative(double t) const override {
        return {radius * cos(t), radius * sin(t)};
    }

private:
    double radius, step;
};

// Comparison function
struct CompareRadius {
    bool operator()(const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) const {
        return a->getRadius() < b->getRadius();
    }
};

// Function to populate the first container
std::vector<std::shared_ptr<Curve3D>> populateFirstContainer() {
    std::vector<std::shared_ptr<Curve3D>> curves;
    // Populate the container with random curves
    // For simplicity, we'll just add a few manually
    curves.push_back(std::make_shared<Circle>(5.0));
    curves.push_back(std::make_shared<Ellipse>(3.0, 4.0));
    curves.push_back(std::make_shared<Helix>(2.0, 6.0));
    return curves;
}

// Function to populate the second container
std::vector<std::shared_ptr<Circle>> populateSecondContainer(const std::vector<std::shared_ptr<Curve3D>>& curves) {
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }
    return circles;
}

// Function to print coordinates of points and derivatives
void printCoordinatesAndDerivatives(const std::vector<std::shared_ptr<Curve3D>>& curves, double t) {
    for (const auto& curve : curves) {
        auto [point, derivative] = curve->getPointAndDerivative(t);
        std::cout << "Point: " << point << ", Derivative: " << derivative << std::endl;
    }
}

// Function to compute the total sum of radii
double computeTotalSumOfRadii(const std::vector<std::shared_ptr<Circle>>& circles) {
    double sum = 0.0;
    for (const auto& circle : circles) {
        sum += circle->getRadius();
    }
    return sum;
}

int main() {
    // Populate the first container
    auto curves = populateFirstContainer();

    // Print coordinates of points and derivatives at t=PI/4
    printCoordinatesAndDerivatives(curves, M_PI / 4);

    // Populate the second container
    auto circles = populateSecondContainer(curves);

    // Sort the second container in ascending order of circles' radii
    std::sort(circles.begin(), circles.end(), CompareRadius());

    // Compute the total sum of radii of all curves in the second container
    double sum = computeTotalSumOfRadii(circles);
    std::cout << "Total sum of radii: " << sum << std::endl;

    return 0;
}