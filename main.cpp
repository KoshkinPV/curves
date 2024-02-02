#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>
#include "curves.h"
#include "omp.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
struct CompareRadius {
    bool operator()(const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) const {
        return a->getRadius() < b->getRadius();
    }
};

double computeTotalSumOfRadii(const std::vector<std::shared_ptr<Circle>>& circles) {
    double sum = 0.0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < circles.size(); i++) {
        sum += circles[i]->getRadius();
    }
    return sum;
}

int main() {
    // Create some curves
    std::shared_ptr<Curve3D> circle = std::make_shared<Circle>(5.0);
    std::shared_ptr<Curve3D> ellipse = std::make_shared<Ellipse>(3.0, 4.0);
    std::shared_ptr<Curve3D> helix = std::make_shared<Helix>(2.0, 6.0);

    // Add the curves to a container
    std::vector<std::shared_ptr<Curve3D>> curves {circle, ellipse, helix};

    // Create a second container for circles
    std::vector<std::shared_ptr<Circle>> circles;

    // Add circles to the second container
    for (const auto& curve : curves) {
        if (auto circlePtr = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circlePtr);
        }
    }

    // Sort the circles in ascending order of radius
    std::sort(circles.begin(), circles.end(), CompareRadius());

    // Compute the total sum of radii
    double sum = computeTotalSumOfRadii(circles);
    std::cout << "Total sum of radii: " << sum << std::endl;

    return 0;
}
