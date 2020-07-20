/**
 *  @file       point_impl.tpp
 *  @brief      Header file for a point ADT (template implementation code)
 *
 *  @author     Gemuele Aludino
 *  @date       19 Jul 2020
 *  @copyright  Copyright © 2020 Gemuele Aludino
 *
 *  @note       This is an internal header file, used by point.hpp.
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

#ifndef POINT_IMPL_TPP
#define POINT_IMPL_TPP

BEGIN_GCS_NAMESPACE

template <size_t dimension, typename FloatType>
point<dimension, FloatType>::point() : m_coords{Coordinates{}} {
}

template <size_t dimension, typename FloatType>
point<dimension, FloatType>::point(Coordinates coords) : m_coords{coords} {
}

template <size_t dimension, typename FloatType>
point<dimension, FloatType>::point(Coordinates &coords) : m_coords{coords} {
}

template <size_t dimension, typename FloatType>
point<dimension, FloatType>::point(const Point &p) : m_coords{p.m_coords} {
}

template <size_t dimension, typename FloatType>
point<dimension, FloatType>::~point() {
}

template <size_t dimension, typename FloatType>
std::array<FloatType, dimension> point<dimension, FloatType>::get() const {
    return m_coords;
}

template <size_t dimension, typename FloatType>
void point<dimension, FloatType>::set(const Point &p) {
    return *this;
}

template <size_t dimension, typename FloatType>
void point<dimension, FloatType>::set(Coordinates coords) {
    m_coords = coords;
}

template <size_t dimension, typename FloatType>
void point<dimension, FloatType>::set(Coordinates &coords) {
    m_coords = coords;
}

template <size_t dimension, typename FloatType>
void point<dimension, FloatType>::reset() {
    m_coords = Coordinates{};
}

template <size_t dimension, typename FloatType>
point<dimension, FloatType> &
point<dimension, FloatType>::operator=(const Point &p) {
    m_coords = p.m_coords;
    return *this;
}

template <size_t dimension, typename FloatType>
FloatType &point<dimension, FloatType>::operator[](int index) {
    return m_coords[index];
}

template <size_t dimension, typename FloatType>
bool point<dimension, FloatType>::operator==(const Point &p) {
    return m_coords == p.m_coords;
}

template <size_t dimension, typename FloatType>
bool point<dimension, FloatType>::operator!=(const Point &p) {
    return !(*(this) == p);
}

template <size_t dimension, typename FloatType>
std::ostream &operator<<(std::ostream &os,
                         const point<dimension, FloatType> &p) {
    auto it = p.m_coords.begin();

    os << "{ ";
    while (it < p.m_coords.end()) {
        bool last_element = it < p.m_coords.end() - 1;
        os << *(it++);

        if (last_element) {
            os << ", ";
        }
    }
    os << " }";

    return os;
}

template <size_t dimension, typename FloatType>
FloatType point<dimension, FloatType>::distance(const Point &u,
                                                const Point &v) {
    return euclidean_distance<dimension, FloatType>(u.get().data(),
                                                    v.get().data());
}

template <size_t dimension, typename FloatType>
FloatType point<dimension, FloatType>::distance(Coordinates arr_u,
                                                Coordinates arr_v) {
    return euclidean_distance<dimension, FloatType>(arr_u.data(), arr_v.data());
}

template <size_t dimension, typename FloatType>
FloatType point<dimension, FloatType>::distance(Coordinates &arr_u,
                                                Coordinates &arr_v) {
    return euclidean_distance<dimension, FloatType>(arr_u.data(), arr_v.data());
}

///
/// Template specialization: gcs::point<2>
///

template <typename FloatType>
point<2, FloatType>::point() : m_coords{Coordinates{}} {
}

template <typename FloatType>
point<2, FloatType>::point(Coordinates coords) : m_coords{coords} {
}

template <typename FloatType>
point<2, FloatType>::point(Coordinates &coords) : m_coords{coords} {
}

template <typename FloatType>
point<2, FloatType>::point(const Point &p) : m_coords{p.m_coords} {
}

template <typename FloatType>
point<2, FloatType>::~point() {
}

template <typename FloatType>
FloatType point<2, FloatType>::x() const {
    return m_coords[0];
}

template <typename FloatType>
FloatType point<2, FloatType>::y() const {
    return m_coords[1];
}

template <typename FloatType>
std::array<FloatType, 2> point<2, FloatType>::get() const {
    return m_coords;
}

template <typename FloatType>
void point<2, FloatType>::set_x(FloatType x) {
    m_coords[0] = x;
}

template <typename FloatType>
void point<2, FloatType>::set_y(FloatType y) {
    m_coords[1] = y;
}

template <typename FloatType>
void point<2, FloatType>::set(const Point &p) {
    return *this;
}

template <typename FloatType>
void point<2, FloatType>::set(FloatType x, FloatType y) {
    m_coords[0] = x;
    m_coords[1] = y;
}

template <typename FloatType>
void point<2, FloatType>::set(Coordinates coords) {
    m_coords = coords;
}

template <typename FloatType>
void point<2, FloatType>::set(Coordinates &coords) {
    m_coords = coords;
}

template <typename FloatType>
void point<2, FloatType>::reset() {
    m_coords = Coordinates{};
}

template <typename FloatType>
point<2, FloatType> &point<2, FloatType>::operator=(const Point &p) {
    m_coords = p.m_coords;
    return *this;
}

template <typename FloatType>
FloatType &point<2, FloatType>::operator[](int index) {
    return m_coords[index];
}

template <typename FloatType>
bool point<2, FloatType>::operator==(const Point &p) {
    return m_coords == p.m_coords;
}

template <typename FloatType>
bool point<2, FloatType>::operator!=(const Point &p) {
    return !(*(this) == p);
}

template <typename FloatType>
std::ostream &operator<<(std::ostream &os, const point<2, FloatType> &p) {
    auto it = p.m_coords.begin();

    os << "{ ";
    while (it < p.m_coords.end()) {
        bool last_element = it < p.m_coords.end() - 1;
        os << *(it++);

        if (last_element) {
            os << ", ";
        }
    }
    os << " }";

    return os;
}

template <typename FloatType>
FloatType point<2, FloatType>::distance(FloatType u_x, FloatType u_y,
                                        FloatType v_x, FloatType v_y) {
    return euclidean_distance<2>(Coordinates{u_x, u_y}.data(),
                                 Coordinates{v_x, v_y}.data());
}

template <typename FloatType>
FloatType point<2, FloatType>::distance(const Point &u, const Point &v) {
    return euclidean_distance<2, FloatType>(u.get().data(), v.get().data());
}

template <typename FloatType>
FloatType point<2, FloatType>::distance(Coordinates arr_u, Coordinates arr_v) {
    return euclidean_distance<2, FloatType>(arr_u.data(), arr_v.data());
}

template <typename FloatType>
FloatType point<2, FloatType>::distance(Coordinates &arr_u,
                                        Coordinates &arr_v) {
    return euclidean_distance<2, FloatType>(arr_u.data(), arr_v.data());
}

///
/// Template specialization: gcs::point<3>
///

template <typename FloatType>
point<3, FloatType>::point() : m_coords{Coordinates{}} {
}

template <typename FloatType>
point<3, FloatType>::point(Coordinates coords) : m_coords{coords} {
}

template <typename FloatType>
point<3, FloatType>::point(Coordinates &coords) : m_coords{coords} {
}

template <typename FloatType>
point<3, FloatType>::point(const Point &p) : m_coords{p.m_coords} {
}

template <typename FloatType>
point<3, FloatType>::~point() {
}

template <typename FloatType>
FloatType point<3, FloatType>::x() const {
    return m_coords[0];
}

template <typename FloatType>
FloatType point<3, FloatType>::y() const {
    return m_coords[1];
}

template <typename FloatType>
std::array<FloatType, 3> point<3, FloatType>::get() const {
    return m_coords;
}

template <typename FloatType>
void point<3, FloatType>::set_x(FloatType x) {
    m_coords[0] = x;
}

template <typename FloatType>
void point<3, FloatType>::set_y(FloatType y) {
    m_coords[1] = y;
}

template <typename FloatType>
void point<3, FloatType>::set(const Point &p) {
    return *this;
}

template <typename FloatType>
void point<3, FloatType>::set(FloatType x, FloatType y, FloatType z) {
    m_coords[0] = x;
    m_coords[1] = y;
    m_coords[2] = z;
}

template <typename FloatType>
void point<3, FloatType>::set(Coordinates coords) {
    m_coords = coords;
}

template <typename FloatType>
void point<3, FloatType>::set(Coordinates &coords) {
    m_coords = coords;
}

template <typename FloatType>
void point<3, FloatType>::reset() {
    m_coords = Coordinates{};
}

template <typename FloatType>
point<3, FloatType> &point<3, FloatType>::operator=(const Point &p) {
    m_coords = p.m_coords;
    return *this;
}

template <typename FloatType>
FloatType &point<3, FloatType>::operator[](int index) {
    return m_coords[index];
}

template <typename FloatType>
bool point<3, FloatType>::operator==(const Point &p) {
    return m_coords == p.m_coords;
}

template <typename FloatType>
bool point<3, FloatType>::operator!=(const Point &p) {
    return !(*(this) == p);
}

template <typename FloatType>
std::ostream &operator<<(std::ostream &os, const point<3, FloatType> &p) {
    auto it = p.m_coords.begin();

    os << "{ ";
    while (it < p.m_coords.end()) {
        bool last_element = it < p.m_coords.end() - 1;
        os << *(it++);

        if (last_element) {
            os << ", ";
        }
    }
    os << " }";

    return os;
}

template <typename FloatType>
FloatType point<3, FloatType>::distance(FloatType u_x, FloatType u_y,
                                        FloatType u_z, FloatType v_x,
                                        FloatType v_y, FloatType v_z) {
    return euclidean_distance<3>(Coordinates{u_x, u_y, u_z}.data(),
                                 Coordinates{v_x, v_y, v_z}.data());
}

template <typename FloatType>
FloatType point<3, FloatType>::distance(const Point &u, const Point &v) {
    return euclidean_distance<3, FloatType>(u.get().data(), v.get().data());
}

template <typename FloatType>
FloatType point<3, FloatType>::distance(Coordinates arr_u, Coordinates arr_v) {
    return euclidean_distance<3, FloatType>(arr_u.data(), arr_v.data());
}

template <typename FloatType>
FloatType point<3, FloatType>::distance(Coordinates &arr_u,
                                        Coordinates &arr_v) {
    return euclidean_distance<3, FloatType>(arr_u.data(), arr_v.data());
}

END_GCS_NAMESPACE

#endif /* POINT_IMPL_TPP */
