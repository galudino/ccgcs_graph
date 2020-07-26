/**
 *  @file       vec_impl.tpp
 *  @brief      Header file for a vector (trajectory) ADT (template
 * implementation code)
 *
 *  @author     Gemuele Aludino
 *  @date       19 Jul 2020
 *  @copyright  Copyright © 2020 Gemuele Aludino
 *
 *  @note       This is an internal header file, used by vec.hpp.
 *              You should not attempt to use it directly.
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

#ifndef VEC_IMPL_TPP
#define VEC_IMPL_TPP

#include "header.hpp"

BEGIN_GCS_NAMESPACE

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec() : m_a{}, m_b{} {
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec(
    const point<dimension, floating_precision> &b)
    : m_a{}, m_b{b} {
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec(
    const point<dimension, floating_precision> &a,
    const point<dimension, floating_precision> &b)
    : m_a{a}, m_b{b} {
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec(std::array<floating_precision, dimension> &arr_b) {

}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec(
    std::array<floating_precision, dimension> &arr_a,
    std::array<floating_precision, dimension> &arr_b)
    : m_a{arr_a}, m_b{arr_b} {
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::vec(
    const vec<dimension, floating_precision> &v)
    : m_a{v.m_a}, m_b{v.m_b} {
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>::~vec() {
}

template <size_t dimension, typename floating_precision>
point<dimension, floating_precision>
vec<dimension, floating_precision>::a() const {
    return m_a;
}

template <size_t dimension, typename floating_precision>
point<dimension, floating_precision>
vec<dimension, floating_precision>::b() const {
    return m_b;
}

template <size_t dimension, typename floating_precision>
std::array<floating_precision, dimension>
vec<dimension, floating_precision>::get() const {
    return std::array<floating_precision, dimension>{m_a, m_b};
}

template <size_t dimension, typename floating_precision>
void vec<dimension, floating_precision>::set_a(
    const point<dimension, floating_precision> &a) {
    m_a = a;
}

template <size_t dimension, typename floating_precision>
void vec<dimension, floating_precision>::set_b(
    const point<dimension, floating_precision> &b) {
    m_b = b;
}

template <size_t dimension, typename floating_precision>
void vec<dimension, floating_precision>::set(
    const point<dimension, floating_precision> &a,
    const point<dimension, floating_precision> &b) {
    m_a = a;
    m_b = b;
}

template <size_t dimension, typename floating_precision>
void vec<dimension, floating_precision>::set(
    std::array<floating_precision, dimension> &arr_a,
    std::array<floating_precision, dimension> &arr_b) {
    m_a = point<dimension, floating_precision>{arr_a};
    m_b = point<dimension, floating_precision>{arr_b};
}

template <size_t dimension, typename floating_precision>
void vec<dimension, floating_precision>::reset() {
    m_b = m_a;
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision> &
vec<dimension, floating_precision>::operator=(
    const vec<dimension, floating_precision> &v) {
    m_a = v.m_a;
    m_b = v.m_b;

    return *(this);
}

template <size_t dimension, typename floating_precision>
point<dimension, floating_precision> &
vec<dimension, floating_precision>::operator[](int index) {
    return *(reinterpret_cast<point<dimension, floating_precision> *>(this) +
             index);
}

template <size_t dimension, typename floating_precision>
bool vec<dimension, floating_precision>::operator==(
    const vec<dimension, floating_precision> &v) {
    return m_a == v.m_a && m_b == v.m_b;
}

template <size_t dimension, typename floating_precision>
bool vec<dimension, floating_precision>::operator!=(
    const vec<dimension, floating_precision> &v) {
    return !(*(this) == v);
}

template <size_t dimension, typename floating_precision>
std::ostream &operator<<(std::ostream &os,
                         const vec<dimension, floating_precision> &v) {
    os << "------------------------------------------------" << std::endl
       << "address        \t(" << &v << ")\t\tvec3D" << std::endl
       << "------------------------------------------------" << std::endl
       << "start point (a)\t" << v.a() << std::endl
       << "end point   (b)\t" << v.b() << std::endl
       << "magnitude      \t" << v.magnitude() << std::endl;

    for (size_t i = 0; i < dimension; i++) {
        os << "component[" << i << "]    \t" << v.component(0) << std::endl;
    }

    for (size_t i = 0; i < dimension; i++) {
        os << "angle with axis[" << i << "]    \t" << v.angle(0) << "˚"
           << std::endl;
    }

    os << "================================================" << std::endl;

    return os;
}

template <size_t dimension, typename floating_precision>
floating_precision vec<dimension, floating_precision>::magnitude() const {
    return point<dimension, floating_precision>::distance(m_a, m_b);
}

template <size_t dimension, typename floating_precision>
floating_precision vec<dimension, floating_precision>::angle() const {
    double adjacent = dot_product(components().data(),
                                  std::array<floating_precision, 3>{0, 0, 1});

    double hypotenuse = magnitude();

    return to_degrees(std::acos(adjacent / hypotenuse));
}

template <size_t dimension, typename floating_precision>
floating_precision
vec<dimension, floating_precision>::angle(size_t axis) const {
    double adjacent = components()[axis]; // axis values; 0 == x, 1 == y, 2 == z
    double hypotenuse = magnitude();

    return to_degrees(std::acos(adjacent / hypotenuse));
}

template <size_t dimension, typename floating_precision>
floating_precision vec<dimension, floating_precision>::angle(
    const vec<dimension, floating_precision> &v) const {
    double adjacent = dot_product(components().data(), v.components().data());
    double hypotenuse = magnitude();

    return to_degrees(std::acos(adjacent / hypotenuse));
}

template <size_t dimension, typename floating_precision>
floating_precision
vec<dimension, floating_precision>::component(size_t axis) const {
    return components()[axis];
}

template <size_t dimension, typename floating_precision>
std::array<floating_precision, dimension>
vec<dimension, floating_precision>::components() const {
    auto arr_a = m_a.get();
    auto arr_b = m_b.get();
    
    std::array<floating_precision, dimension> result = {};

    for (size_t i = 0; i < dimension; i++) {
        result[i] = arr_b[i] - arr_a[i];
    }

    return result;
}

template <size_t dimension, typename floating_precision>
floating_precision vec<dimension, floating_precision>::dot_product(
    const vec<dimension, floating_precision> &u,
    const vec<dimension, floating_precision> &v) {
    return gcs::dot_product<dimension, floating_precision>(
        u.components().data(), v.components().data());
}

template <size_t dimension, typename floating_precision>
vec<dimension, floating_precision>
vec<dimension, floating_precision>::cross_product(
    const vec<dimension, floating_precision> &u,
    const vec<dimension, floating_precision> &v) {
    vec<dimension, floating_precision> result;

    if (dimension == 3) {
        auto U = u.components();
        auto V = v.components();

        struct {
            floating_precision x, y, z;
        } component;

        component.x = (U[1] * V[2]) - (U[2] * V[1]);
        component.y = (U[2] * V[0]) - (U[0] * V[2]);
        component.z = (U[0] * V[1]) - (U[1] * V[0]);

        return vec<dimension, floating_precision>{component.x, component.y,
                                                  component.z

        };
    }

    return result;
}

END_GCS_NAMESPACE

#endif /* VEC_IMPL_TPP */
