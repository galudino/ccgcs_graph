/**
 *  @file       main.cpp
 *  @brief      Client C++ source file
 *
 *  @author     Gemuele Aludino
 *  @date       20 Jun 2020
 *  @copyright  Copyright © 2020 Gemuele Aludino
 */
/**
 *  Copyright © 2020 Gemuele Aludino
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 *  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
 *  THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <cmath>

#include "header.hpp"
#include "point.hpp"
#include "vec.hpp"

using gcs::point2D;
using gcs::point3D;
using gcs::vec2D;
using gcs::vec3D;

double calculate_slope(const std::array<double, 3> &point_a, const std::array<double, 3> &point_b) {
    double dx = point_b[0] - point_a[0];
    double dy = point_b[1] - point_a[1];
    double dz = point_b[2] - point_a[2];
    
    double rise = dz;
    double run = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
    
    return std::atan(rise / run) * (180 / M_PI);
}

/**
 *  @brief  Program execution begins here
 *
 *  @param[in]  argc    argument count
 *  @param[in]  argv    command line arguments
 *
 *  @return     exit status
 */
int main(int argc, const char *argv[]) {
    // Create vec3D using a single point3D (extends from origin)
    // or provide two point3D - the start and end points.
    vec3D v3d_0{point3D{3, 2, 1}};
    //vec3D v3d_0{point3D{0, 0, 0}, point3D{3, 2, 1}};

    // Create vec3D using endpoint coordinates (extends from origin)
    // or provide two sets of three doubles - the start and end points
    // vec3D v3d_0{3, 2, 1}
    // vec3D v3d_0{0, 0, 0, 3, 2, 1};

    // Create vec3D using a single std::array<double, 3> (extends from origin)
    // or provide two std::array<double, 3> - the start and end points
    // vec3D v3d_0{{3, 2, 1}};
    // vec3D v3d_0{{0, 0, 0}, {3, 2, 1}};
    
    //vec3D v3d_0{3, 2, 1};
    vec3D v3d_1{-1, 1, 1};

    std::cout << v3d_0 << "\n" << v3d_1 << std::endl;

    std::cout << "dot product of v3d_0 and v3d_1 = "
              << vec3D::dot_product(v3d_0, v3d_1) << std::endl;

    // This vector, by components, is {6, 6, 6}.
    // {3, 2, 1} is the start point, {9, 8, 7} is the end point.
    vec3D v3d_2{{3, 2, 1}, {9, 8, 7}};

    // This vector, by components, is also {6, 6, 6}.
    // {0, 0, 0} is the start point, {6, 6, 6} is the end point.
    // Although v3d_2 and v3d_3 have the same dimensions,
    // they extend from different locations in space.
    vec3D v3d_3{{6, 6, 6}};

    std::cout << v3d_2 << "\n" << v3d_3 << std::endl;
     
    return 0;
}
