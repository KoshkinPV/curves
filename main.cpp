#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "curve.h"

double M_PI = 3.14;

bool compareCircles(Circle* a, Circle* b)
{
    return a->getRadius() < b->getRadius();
}

int main() {
    std::vector<Curve3D*> curves;
    std::vector<Circle*> circles;

    // Populate the curves vector with random parameters

    // Creating a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Create distribution for radius, a, b and step 
    std::uniform_real_distribution<> radiusDist(1.0, 10.0);
    std::uniform_real_distribution<> aDist(1.0, 10.0);
    std::uniform_real_distribution<> bDist(1.0, 10.0);
    std::uniform_real_distribution<> stepDist(1.0, 10.0);
    
    // Populate curves and circles with random parameters
    for(int i = 0; i < 100; i++)
    {
        int curveType = i % 3;
        if(curveType == 0) // Circle
        {
            double radius = radiusDist(gen);
            Circle* circle = new Circle(radius);
            curves.push_back(circle);
        }
        if(curveType == 1) // Ellipse
        {
            double a = aDist(gen);
            double b = bDist(gen);
            Ellipse* ellipse = new Ellipse(a, b);
            curves.push_back(ellipse);
        }
        if(curveType == 2) // Helix
        {
            double radius = radiusDist(gen);
            double step = stepDist(gen);
            Helix* helix = new Helix(radius, step);
            curves.push_back(helix);
        }
    }

    // Print coordinates of points and derivatives at t=PI/4
    for (auto& curve : curves)
        curve->printPointAndDerivative(M_PI / 4);

    // Populate the circles vector
    for (auto& curve : curves) {
        Circle* circle = dynamic_cast<Circle*>(curve);
        if (circle)
            circles.push_back(circle);
    }

    // Sort the circles vector in ascending order of radii
    std::sort(circles.begin(), circles.end(), compareCircles);

    // Compute the total sum of radii of all circles
    double totalRadius = 0;
    for (auto& circle : circles)
        totalRadius += circle->getRadius();

    std::cout << "Total sum of radii: " << totalRadius << std::endl;

    return 0;
}