/*!
    \file       vec_impl.hpp
    \brief      Template implementation file for vec.hpp

    \details    This header file is private and should not be included by any
   other file.

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

#ifndef VEC_IMPL_HPP_PRIVATE
#define VEC_IMPL_HPP_PRIVATE

#include "gcs_utils.hpp"

#include <algorithm>
#include <memory>

BEGIN_GCS_NAMESPACE

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src
    \param[in]  dst
*/
template <size_t N, typename F>
vec<N, F>::vec(const point<N, F> &src, const point<N, F> &dst) {
    auto src_it = src.cbegin();
    auto src_end = src.cend();
    auto dst_it = dst.cbegin();

    std::array<F, N> result;
    auto it = result.begin();

    while (src_it < src_end) {
        *(it++) = *(dst_it++) - *(src_it++);
    }

    m_components = result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src
    \param[in]  dst
*/
template <size_t N, typename F>
vec<N, F>::vec(const point<N, F> &&src, const point<N, F> &&dst) {
    auto src_it = src.cbegin();
    auto src_end = src.cend();
    auto dst_it = dst.cbegin();

    std::array<F, N> result;
    auto it = result.begin();

    while (src_it < src_end) {
        *(it++) = *(dst_it++) - *(src_it++);
    }

    m_components = result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src
    \param[in]  dst
*/
template <size_t N, typename F>
vec<N, F>::vec(const std::initializer_list<F> &src,
               const std::initializer_list<F> &dst) {
    auto src_it = src.begin();
    auto src_end = src.end();
    auto dst_it = dst.begin();

    std::array<F, N> result;
    auto it = result.begin();

    while (src_it < src_end) {
        *(it++) = *(dst_it++) - *(src_it++);
    }

    m_components = result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::operator+(const vec &v) const {
    auto it = cbegin();
    auto end = cend();
    auto v_it = v.cbegin();

    vec result = *this;
    auto it_result = result.begin();

    while (it < end) {
        *(it_result++) = *(it++) + *(v_it++);
    }

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::operator+(const vec &&v) const {
    auto it = cbegin();
    auto end = cend();
    auto v_it = v.cbegin();

    vec result = *this;
    auto it_result = result.begin();

    while (it < end) {
        *(it_result++) = *(it++) + *(v_it++);
    }

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::operator-(const vec &v) const {
    auto it = cbegin();
    auto end = cend();
    auto v_it = v.cbegin();

    vec result = *this;
    auto it_result = result.begin();

    while (it < end) {
        *(it_result++) = *(it++) - *(v_it++);
    }

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::operator-(const vec &&v) const {
    auto it = cbegin();
    auto end = cend();
    auto v_it = v.cbegin();

    vec result = *this;
    auto it_result = result.begin();

    while (it < end) {
        *(it_result++) = *(it++) - *(v_it++);
    }

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::operator*(const vec &v) const {
    auto v0 = cbegin();
    auto v1 = v.cbegin();
    auto U = const_cast<F *>(v0);
    auto V = const_cast<F *>(v1);
    return gcs::dot_product<N>(U, V);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::operator*(const vec &&v) const {
    auto it = const_cast<F *>(cbegin());
    auto v_it = const_cast<F *>(v.cbegin());
    return gcs::dot_product<N, F>(it, v_it);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> &vec<N, F>::operator+=(const vec &v) {
    auto it = begin();
    auto end = cend();
    auto v_it = v.cbegin();

    while (it < end) {
        *(it++) += *(v_it++);
    }

    return *this;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> &vec<N, F>::operator-=(const vec &v) {
    auto it = begin();
    auto end = cend();
    auto v_it = v.cbegin();

    while (it < end) {
        *(it++) -= *(v_it++);
    }

    return *this;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \return
*/
template <size_t N, typename F>
F vec<N, F>::magnitude() const {
    vec origin;
    typename std::array<F, N>::const_iterator it = cbegin();
    return gcs::euclidean_distance<N, F>(origin.begin(), const_cast<F *>(it));
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  components

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const std::initializer_list<F> &components) {
    return angle(vec{components});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const vec &v) const {
    F dot_product = *(this) * v;

    F product_magnitude = magnitude() * v.magnitude();
    F reciprocal_product_magnitude = 1 / product_magnitude;

    return std::acos(dot_product * reciprocal_product_magnitude);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const vec &&v) const {
    F dot_product = *(this) * v;

    F product_magnitude = magnitude() * v.magnitude();
    F reciprocal_product_magnitude = 1 / product_magnitude;

    return std::acos(dot_product * reciprocal_product_magnitude);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
    return angle(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const point<N, F> &&src_pt, const point<N, F> &&dst_pt) {
    return angle(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::angle(const std::initializer_list<F> &src_pt,
                   const std::initializer_list<F> &dst_pt) {
    return angle(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  components

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const std::initializer_list<F> &components) const {
    vec v{components};
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const vec &v) const {
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const vec &&v) const {
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const point<N, F> &src_pt,
                         const point<N, F> &dst_pt) const {
    vec v{src_pt, dst_pt};
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const point<N, F> &&src_pt,
                         const point<N, F> &&dst_pt) const {
    vec v{src_pt, dst_pt};
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
F vec<N, F>::dot_product(const std::initializer_list<F> &src_pt,
                         const std::initializer_list<F> &&dst_pt) const {
    vec v{src_pt, dst_pt};
    return *(this) * v;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  components

    \return
*/
template <size_t N, typename F>
vec<N, F>
vec<N, F>::cross_product(const std::initializer_list<F> &components) const {
    if (N != 3) {
        vec null_vec;
        return null_vec;
    }

    return cross_product(vec{components});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::cross_product(const vec &v) const {
    if (N != 3) {
        std::cerr << "Cannot run cross_product on dimension " << N
                  << ".\nWill return null vector." << std::endl;

        vec null_vec;
        return null_vec;
    }

    const auto U = m_components;
    const auto V = v.m_components;

    const F u1v2 = U[1] * V[2];
    const F v1u2 = V[1] * U[2];
    const F u0v2 = U[0] * V[2];
    const F v0u2 = V[0] * U[2];
    const F u0v1 = U[0] * V[1];
    const F v0u1 = V[0] * U[1];

    const auto x = (u1v2 - v1u2);
    const auto y = (u0v2 - v0u2) * (-1);
    const auto z = (u0v1 - v0u1);

    return vec{x, y, z};
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  v

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::cross_product(const vec &&v) const {
    if (N != 3) {
        std::cerr << "Cannot run cross_product on dimension " << N
                  << ".\nWill return zero vector." << std::endl;

        vec null_vec;
        return null_vec;
    }

    const auto U = m_components;
    const auto V = v.m_components;

    const F u1v2 = U[1] * V[2];
    const F v1u2 = V[1] * U[2];
    const F u0v2 = U[0] * V[2];
    const F v0u2 = V[0] * U[2];
    const F u0v1 = U[0] * V[1];
    const F v0u1 = V[0] * U[1];

    const auto x = (u1v2 - v1u2);
    const auto y = (u0v2 - v0u2) * (-1);
    const auto z = (u0v1 - v0u1);

    return vec{x, y, z};
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::cross_product(const point<N, F> &src_pt,
                                   const point<N, F> &dst_pt) const {
    if (N != 3) {
        std::cerr << "Cannot run cross_product on dimension " << N
                  << ".\nWill return zero vector." << std::endl;

        vec null_vec;
        return null_vec;
    }

    return cross_product(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
vec<N, F> vec<N, F>::cross_product(const point<N, F> &&src_pt,
                                   const point<N, F> &&dst_pt) const {
    if (N != 3) {
        std::cerr << "Cannot run cross_product on dimension " << N
                  << ".\nWill return zero vector." << std::endl;

        vec null_vec;
        return null_vec;
    }

    return cross_product(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dst_pt

    \return
*/
template <size_t N, typename F>
vec<N, F>
vec<N, F>::cross_product(const std::initializer_list<F> &src_pt,
                         const std::initializer_list<F> &&dst_pt) const {
    if (N != 3) {
        std::cerr << "Cannot run cross_product on dimension " << N
                  << ".\nWill return zero vector." << std::endl;

        vec null_vec;
        return null_vec;
    }

    return cross_product(vec{src_pt, dst_pt});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  os
*/
template <size_t N, typename F>
void vec<N, F>::print_details(std::ostream &os) {
    os << "==============================="
       << "\n"
       << "V = " << *this << "\t\t" << this << "\n"
       << "-------------------------------"
       << "\n"
       << "Magnitude:      " << magnitude() << "\n";

    vec<N, F> unit_vector;

    for (size_t i = 0; i < N; i++) {
        unit_vector[i] = 1;

        os << "Angle (axis " << i << "): " << gcs::deg(angle(unit_vector))
           << "°\n";

        unit_vector[i] = 0;
    }

    os << "===============================" << std::endl;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::endpoint(const point<N, F> &src_pt,
                                const vec<N, F> &dir) {
    point<N, F> result = src_pt;
    auto dir_it = dir.cbegin();

    std::for_each(result.begin(), result.end(), [&dir_it](F &res) {
        res += *(dir_it++);
    });

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::endpoint(const point<N, F> &&src_pt,
                                const vec<N, F> &&dir) {
    point<N, F> result = src_pt;
    auto dir_it = dir.cbegin();

    std::for_each(result.begin(), result.end(), [&dir_it](F &res) {
        res += *(dir_it++);
    });

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::endpoint(const std::initializer_list<F> &src_pt,
                                const vec<N, F> &dir) {
    return endpoint(point<N, F>{src_pt}, dir);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  components

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::endpoint(const point<N, F> &src_pt,
                                const std::initializer_list<F> &components) {
    return endpoint(src_pt, vec<N, F>{components});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  src_pt
    \param[in]  components

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::endpoint(const std::initializer_list<F> &src_pt,
                                const std::initializer_list<F> &components) {
    return endpoint(point<N, F>{src_pt}, vec<N, F>{components});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  dst_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::srcpoint(const point<N, F> &dst_pt,
                                const vec<N, F> &dir) {
    point<N, F> result = dst_pt;
    auto dir_it = const_cast<F *>(dir.cbegin());

    std::for_each(result.begin(), result.end(), [&](F &res) {
        res -= *(dir_it++);
    });

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  dst_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::srcpoint(const point<N, F> &&dst_pt,
                                const vec<N, F> &&dir) {
    point<N, F> result = dst_pt;
    auto dir_it = const_cast<F *>(dir.cbegin());

    std::for_each(result.begin(), result.end(), [&](F &res) {
        res -= *(dir_it++);
    });

    return result;
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  dst_pt
    \param[in]  dir

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::srcpoint(const std::initializer_list<F> &dst_pt,
                                const vec<N, F> &dir) {
    return srcpoint(point<N, F>{dst_pt}, dir);
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  dst_pt
    \param[in]  components

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::srcpoint(const point<N, F> &dst_pt,
                                const std::initializer_list<F> &components) {
    return srcpoint(dst_pt, vec<N, F>{components});
}

/*!
    \brief

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.

    \param[in]  dst_pt
    \param[in]  components

    \return
*/
template <size_t N, typename F>
point<N, F> vec<N, F>::srcpoint(const std::initializer_list<F> &dst_pt,
                                const std::initializer_list<F> &components) {
    return srcpoint(point<N, F>{dst_pt}, vec<N, F>{components});
}

END_GCS_NAMESPACE

#endif /* VEC_IMPL_HPP_PRIVATE */
