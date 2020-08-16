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

#include "header.hpp"
#include "vec.hpp"

/*!
    \brief  Program execution begins and ends here
    
    \param[in]  argc    Command line argument count
    \param[in]  argv    Command line arguments
 
    \return     0 on success, else failure (see error code)
 */
int main(int argc, const char *argv[]) {
    gcs::point2D p {3, 5};
    p.set(std::array<double, 2> {22, 34});
    
    return EXIT_SUCCESS;
}
