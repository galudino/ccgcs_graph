/*
 *  @file       header.hpp
 *  @brief      Header file
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

#ifndef HEADER_HPP
#define HEADER_HPP

// For use with .tpp files only
#define BEGIN_GCS_NAMESPACE namespace gcs {
#define END_GCS_NAMESPACE } // namespace gcs

namespace gcs {
const double epsilon = 0.00000001f;

bool double_approx_eq(double a, double b);

double to_degrees(double radians);
double to_radians(double degrees);

template <size_t dimension, typename float_precision = double>
float_precision euclidean_distance(float_precision u[], float_precision v[]);

template <size_t dimension, typename float_precision = double>
float_precision dot_product(float_precision U[], float_precision V[]);
} // namespace gcs

/**
 *  @brief Retrieves the distance between two points, u and v
 *
 *  @tparam     dimension   minimum number of coordinates to denote a point
 *  @tparam     float_precision floating-point value type, i.e. float or double
 *
 *  @param[in]  u   array of first point's coordinates (start point), size is
 * dimension
 *  @param[in]  v   array of second point's coordinates (end point), size is
 * dimension
 *
 *  @return Euclidean distance between two points, u and v
 */
template <size_t dimension, typename float_precision>
float_precision gcs::euclidean_distance(float_precision u[],
                                        float_precision v[]) {
    double sum = 0;

    for (size_t i = 0; i < dimension; i++) {
        double difference = v[i] - u[i];
        sum += std::pow(difference, 2.0);
    }

    return std::sqrt(sum);
}

/**
 *  @brief Retrieves the dot product of two vectors, U and V
 *
 *  @tparam     dimension   minimum number of coordinates to denote a point
 *  @tparam     float_precision floating-point value type, i.e. float or double
 *
 *  @param[in]  U   array of first vector's components, size is dimension
 *  @param[in]  V   array of second vector's components, size is dimension
 *
 *  @return dot product of vectors U and V
 */
template <size_t dimension, typename float_precision>
float_precision gcs::dot_product(float_precision U[], float_precision V[]) {
    double sum = 0;

    for (size_t i = 0; i < dimension; i++) {
        sum += U[i] * V[i];
    }

    return sum;
}

#endif /* HEADER_HPP */
