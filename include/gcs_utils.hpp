/*!
    \file       gcs_utils.hpp
    \brief      Header file for utilities (constants, miscellaneous functions,
   etc.)

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

#ifndef GCS_UTILS_HPP
#define GCS_UTILS_HPP

#include <cmath>
#include <cstddef>

// For use with template implementation files
#define BEGIN_GCS_NAMESPACE namespace gcs {
#define END_GCS_NAMESPACE } // namespace gcs

namespace gcs {
constexpr const double epsilon = 0.00000001f;

template <typename F = double>
bool approx_eq(F a, F b);

template <typename F = double>
F deg(F radians);

template <typename F = double>
F rad(F degrees);

template <size_t N, typename F = double>
F euclidean_distance(F u[], F v[]);

template <size_t N, typename F = double>
F dot_product(F U[], F V[]);
} // namespace gcs

/*!
    \brief      Retrieves the distance between two points, u and v

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  u    array of first point's cooridnates (start point), size is
   dimension
    \param[in]  v   array of second point's coordinates (end point), size
   is dimension

    \return     Euclidean distance between two points, u and v
 */
template <size_t N, typename F>
F gcs::euclidean_distance(F u[], F v[]) {
    F sum = 0;

    for (size_t i = 0; i < N; i++) {
        F difference = v[i] - u[i];
        sum += std::pow(difference, 2.0);
    }

    return std::sqrt(sum);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  U   array of first vector's components, size is dimension
    \param[in]  V   array of second vector's components, size is dimension

    \return     dot product of vectors U and V
 */
template <size_t N, typename F>
F gcs::dot_product(F U[], F V[]) {
    F sum = 0;

    for (size_t i = 0; i < N; i++) {
        sum += U[i] * V[i];
    }

    return sum;
}

/*!
    \brief

    @tparam F   Floating-point precision, default is double.

    \param[in]  a
    \param[in]  b

    \return
 */
template <typename F>
bool gcs::approx_eq(F a, F b) {
    return std::abs(a - b) < gcs::epsilon;
}

/*!
    \brief

    @tparam F   Floating-point precision, default is double.

    \param[in]  radians

    \return
 */
template <typename F>
F gcs::deg(F radians) {
    return radians * (180.0 / M_PI);
}

/*!
    \brief

    @tparam F   Floating-point precision, default is double.

    \param[in]  degrees

    \return
 */
template <typename F>
F gcs::rad(F degrees) {
    return degrees * (M_PI / 180.0);
}

#endif /* GCS_UTILS_HPP */
