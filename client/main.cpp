/*!
    \file       main.cpp
    \brief      Client C++ source file

    \author     Gemuele Aludino
    \date       15 Aug 2020
    \copyright  Copyright (c) 2020 Gemuele Aludino
 */

/*!
    Copyright © 2020 Gemuele Aludino

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
    DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH
    THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <cmath>
#include <iostream>

#include "gcs_utils.hpp"
#include "point.hpp"
#include "vec.hpp"

/*!
    \brief  Program execution begins and ends here

    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments

    \return     0 on success, else failure (see error code)
 */
int main(int argc, const char *argv[]) {
    using gcs::point;
    using gcs::vec;

    // unit vector i in R2
    vec<2> i{1, 0};
    i.print_details(std::cout);

    // vector for a 3, 4, 5 triangle
    vec<2> v{3, 4};
    v.print_details(std::cout);

    std::cout << "angle between " << i << " and " << v << ": "
              << gcs::deg(v.angle(i)) << "°\n"
              << std::endl;

    // variable p_origin will initialize to {0, 0}
    point<2> p_origin;

    // setting point p_origin to position {1, 2}
    p_origin.set({1, 2});

    // determining end point
    // from start position {1, 2},
    // with direction {3, 4}
    auto p_end = vec<2>::endpoint(p_origin, v);
    std::cout << "endpoint from " << p_origin << " with direction " << v << ": "
              << p_end << std::endl;

    // determining start position
    // from terminal position {4, 7},
    // with vector components {3, 4}
    auto p_beg = vec<2>::srcpoint(p_end, {3, 4}); // initializer_list for vec
    std::cout << "startpoint from " << p_end << " with direction " << v << ": "
              << p_beg << std::endl;

    // vectors can be created using two points (start and end points);
    // these points are initializer lists --
    // but gcs::point instances can be used too.
    vec<2>({0, 0}, {6, 8}).print_details(std::cout);

    return EXIT_SUCCESS;
}
