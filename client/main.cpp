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

#include "graph.hpp"

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
    
    vec<2> m;
    m.set({3, 4}, {2, 1});

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
    std::cout << std::endl;
    
    // node is a subclass of point.
    // if the caller does not want/need vertices to store
    // node_val (additional data) -- and only need position data,
    // the point class will work.
    // since all nodes are points, we must upcast our node instances
    // to point.
    gcs::node<2, std::string> parent({0, 0}, "Gem A");
    gcs::node<2, std::string> child({3, 4}, "Sarah F");
    
    gcs::node<2, std::string> other({5, 12}, "Laura C");
    other = point<2>{ 55, 44 };
    std::cout << parent << std::endl;
    std::cout << child << std::endl;
    std::cout << other << std::endl;
    
    // Here, we decide not to supply an edge_val type.
    // This is okay. (A type was actually assigned, but it is a 'dummy' type)
    gcs::edge<2> e0(child.id(), parent.distance(child));
    std::cout << e0 << std::endl;
        
    // Here, we decide not to supply a node_val type.
    // This is okay. (A type was actually assigned, but it is a 'dummy' type)
    gcs::node<2> dummy;
    std::cout << dummy << std::endl;
    
    std::cout << std::endl;
    
    // No node value type, no edge value type.
    // Just a plain graph with node position data (2D) and edge weights.
    gcs::graph<2> plain_graph;
    
    // Nodes store a std::string and a 2D point
    // edges store a std::string and a weight (double)
    gcs::graph<2, std::string, std::string> value_graph;

    return EXIT_SUCCESS;
}
