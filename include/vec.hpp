/*!
    \file       vec.hpp
    \brief      Header file for a vector (trajectory) ADT

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

#ifndef VEC_HPP
#define VEC_HPP

#include <array>
#include <ostream>

namespace gcs {
template <size_t N, typename F>
class point;

template <size_t N, typename F = double>
class vec;

template <typename F>
class vec<2, F>;

template <typename F>
class vec<3, F>;
} // namespace gcs

/*!
    \class  gcs::vec
    \brief  Templated abstraction for a vector (trajectory, direction) on the
   Cartesian coordinate plane

    \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    \tparam F   Floating-point precision, default is double.
 */
template <size_t N, typename F>
class gcs::vec {
public:
    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;

    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    using point = point<N, F>;

    /*!
        \brief
     */
    vec() {
        reset();
    }
    
    /*!
        \brief
     
        \param[in]  arr
     */
    vec(const array &arr) : m_components(arr) {
        
    }
    
    /*!
        \brief
     
        \param[in]  arr
     */
    vec(array &&arr) : m_components(arr) {
        
    }

    /*!
        \brief

        \param[in]  components
    */
    vec(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }

    /*!
        \brief

        \param[in]  components
    */
    vec(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }
    
    /*!
        \brief

        \param[in]  v
    */
    vec(const vec &v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \param[in]  v
    */
    vec(vec &&v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point &src, const point &dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();
        
        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(point &&src, point &&dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const initializer_list &src_pt, const initializer_list &dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }
    
    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(initializer_list &&src_pt, initializer_list &&dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief
     */
    ~vec() {
    }

    /*!
        \brief

        \return
     */
    iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \return
     */
    iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \return
     */
    const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \return
     */
    const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crend() const {
        return m_components.crend();
    }

    /*!
        \brief

        \return
     */
    array get() const {
        return m_components;
    }
    
    /*!
        \brief

        \param[in]  arr
    */
    void set(const array &arr) {
        *(this) = arr;
    }
    
    /*!
        \brief

        \param[in]  arr
    */
    void set(array &&arr) {
        *(this) = arr;
    }

    /*!
        \brief

        \param[in]  components
    */
    void set(const initializer_list &components) {
        *(this) = components;
    }
    
    /*!
        \brief

        \param[in]  components
    */
    void set(initializer_list &&components) {
        *(this) = components;
    }

    /*!
        \brief

        \param[in]  v
    */
    void set(const vec &v) {
        *(this) = v;
    }
    
    /*!
        \brief

        \param[in]  v
    */
    void set(vec &&v) {
        *(this) = v;
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point &src_pt, const point &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(point &&src_pt, point &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const initializer_list &src_pt, const initializer_list &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }
    
    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(initializer_list &&src_pt, initializer_list &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }
    
    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(const vec &v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(vec &&v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    void reset() {
        m_components.fill(0);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    F &operator[](const int index) {
        return m_components[index];
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) const {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) {
        return !(*(this) == v);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) const {
        return !(*(this) == v);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec operator+(const vec &v) const {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec operator-(const vec &v) const {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F operator*(const vec &v) const {
        auto v0 = cbegin();
        auto v1 = v.cbegin();
        auto U = const_cast<F *>(v0);
        auto V = const_cast<F *>(v1);
        return gcs::dot_product<N>(U, V);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec &operator+=(const vec &v) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec &operator-=(const vec &v) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \return
    */
    F magnitude() const {
        vec origin;
        const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F angle(const initializer_list &components) {
        return angle(vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F angle(const vec &v) const {
        F dot_product = *(this) * v;

        F product_magnitude = magnitude() * v.magnitude();
        F reciprocal_product_magnitude = 1 / product_magnitude;

        return std::acos(dot_product * reciprocal_product_magnitude);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const point &src_pt, const point &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const initializer_list &src_pt, const initializer_list &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(const initializer_list &components) const {
        vec v{components};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F dot_product(const vec &v) const {
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const point &src_pt, const point &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const initializer_list &src_pt,
                  const initializer_list &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  os
    */
    void print_details(std::ostream &os) {
        os << "==============================="
           << "\n"
           << "V = " << *this << "\t\t" << this << "\n"
           << "-------------------------------"
           << "\n"
           << "Magnitude:      " << magnitude() << "\n";

        vec unit_vector;

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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const point &src_pt, const vec &dir) {
        auto result = src_pt;
        auto dir_it = dir.cbegin();

        std::for_each(result.begin(), result.end(), [&dir_it](F &res) {
            res += *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const initializer_list &src_pt, const vec &dir) {
        return endpoint(point{src_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const point &src_pt,
                          const initializer_list &components) {
        return endpoint(src_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const initializer_list &src_pt,
                          const initializer_list &components) {
        return endpoint(point{src_pt}, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const point &dst_pt, const vec &dir) {
        auto result = dst_pt;
        auto dir_it = const_cast<F *>(dir.cbegin());

        std::for_each(result.begin(), result.end(), [&](F &res) {
            res -= *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const initializer_list &dst_pt, const vec &dir) {
        return srcpoint(point{dst_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const point &dst_pt,
                          const initializer_list &components) {
        return srcpoint(dst_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const initializer_list &dst_pt,
                          const initializer_list &components) {
        return srcpoint(point{dst_pt}, vec{components});
    }

    friend std::ostream &operator<<(std::ostream &os, const vec &v) {
        auto it = v.cbegin();
        auto it_end = v.cend();

        os << "[";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "]";

        return os;
    }

private:
    array m_components; ///< Vector components stored here.
};

/*!
    \class  gcs::vec<2, F>
    \brief  Template specialization for gcs::vec<2, F> (vector in R^2)

    \tparam F   Floating-point precision, default is double.
 */
template <typename F>
class gcs::vec<2, F> {
public:
    static constexpr auto N = 2;

    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;

    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    using point = point<N, F>;
    
    /*!
        \brief
    */
    vec() {
        reset();
    }

    /*!
        \brief
     
        \param[in]  arr
     */
    vec(const array &arr) : m_components(arr) {
        
    }
    
    /*!
        \brief
     
        \param[in]  arr
     */
    vec(array &&arr) : m_components(arr) {
        
    }
    
    /*!
        \brief

        \param[in]  components
    */
    vec(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }

    /*!
        \brief

        \param[in]  components
    */
    vec(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }
    
    /*!
        \brief

        \param[in]  v
    */
    vec(const vec &v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \param[in]  v
    */
    vec(vec &&v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point &src, const point &dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(point &&src, point &&dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const initializer_list &src_pt, const initializer_list &dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }
    
    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(initializer_list &&src_pt, initializer_list &&dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief
     */
    ~vec() {
    }

    /*!
        \brief

        \return
     */
    iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \return
     */
    iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \return
     */
    const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \return
     */
    const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crend() const {
        return m_components.crend();
    }

    /*!
        \brief

        \return
     */
    F x() const {
        return m_components[0];
    }

    /*!
        \brief

        \return
     */
    F y() const {
        return m_components[1];
    }
    
    /*!
        \brief

        \return
     */
    array get() const {
        return m_components;
    }

    /*!
        \brief

        \param[in]  x
     */
    void set_x(const F x) {
        m_components[0] = x;
    }

    /*!
        \brief

        \param[in]  y
     */
    void set_y(const F y) {
        m_components[1] = y;
    }
    
    /*!
        \brief
     
        \param[in]  x
        \param[in]  y
        \param[in]  z
     */
    void set(const F x, const F y) {
        m_components = std::array<F, N>{x, y};
    }

   /*!
        \brief

        \param[in]  arr
    */
    void set(const array &arr) {
        *(this) = arr;
    }
    
    /*!
        \brief

        \param[in]  arr
    */
    void set(array &&arr) {
        *(this) = arr;
    }

    /*!
        \brief

        \param[in]  components
    */
    void set(const initializer_list &components) {
        *(this) = components;
    }
    
    /*!
        \brief

        \param[in]  components
    */
    void set(initializer_list &&components) {
        *(this) = components;
    }

    /*!
        \brief

        \param[in]  v
    */
    void set(const vec &v) {
        *(this) = v;
    }
    
    /*!
        \brief

        \param[in]  v
    */
    void set(vec &&v) {
        *(this) = v;
    }
    
    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point &src_pt, const point &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(point &&src_pt, point &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const initializer_list &src_pt, const initializer_list &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }
    
    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(initializer_list &&src_pt, initializer_list &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }
    
    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(const vec &v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(vec &&v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    void reset() {
        m_components.fill(0);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    F &operator[](const int index) {
        return m_components[index];
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) const {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) {
        return !(*(this) == v);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) const {
        return !(*(this) == v);
    }

    /*!
          \brief

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      vec operator+(const vec &v) const {
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

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      vec operator-(const vec &v) const {
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

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      F operator*(const vec &v) const {
          auto v0 = cbegin();
          auto v1 = v.cbegin();
          auto U = const_cast<F *>(v0);
          auto V = const_cast<F *>(v1);
          return gcs::dot_product<N>(U, V);
      }

      /*!
          \brief

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      vec &operator+=(const vec &v) {
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

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      vec &operator-=(const vec &v) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \return
    */
    F magnitude() const {
        vec origin;
        const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F angle(const initializer_list &components) {
        return angle(vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F angle(const vec &v) const {
        F dot_product = *(this) * v;

        F product_magnitude = magnitude() * v.magnitude();
        F reciprocal_product_magnitude = 1 / product_magnitude;

        return std::acos(dot_product * reciprocal_product_magnitude);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const point &src_pt, const point &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const initializer_list &src_pt, const initializer_list &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(const initializer_list &components) const {
        vec v{components};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F dot_product(const vec &v) const {
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const point &src_pt, const point &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }
    
    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const initializer_list &src_pt,
                  const initializer_list &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  os
    */
    void print_details(std::ostream &os) {
        os << "==============================="
           << "\n"
           << "V = " << *this << "\t\t" << this << "\n"
           << "-------------------------------"
           << "\n"
           << "Magnitude:      " << magnitude() << "\n";

        vec unit_vector;

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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const point &src_pt, const vec &dir) {
        point result = src_pt;
        auto dir_it = dir.cbegin();

        std::for_each(result.begin(), result.end(), [&dir_it](F &res) {
            res += *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const initializer_list &src_pt, const vec &dir) {
        return endpoint(point{src_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const point &src_pt,
                          const initializer_list &components) {
        return endpoint(src_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const initializer_list &src_pt,
                          const initializer_list &components) {
        return endpoint(point{src_pt}, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const point &dst_pt, const vec &dir) {
        point result = dst_pt;
        auto dir_it = const_cast<F *>(dir.cbegin());

        std::for_each(result.begin(), result.end(), [&](F &res) {
            res -= *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const initializer_list &dst_pt, const vec &dir) {
        return srcpoint(point{dst_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const point &dst_pt,
                          const initializer_list &components) {
        return srcpoint(dst_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const initializer_list &dst_pt,
                          const initializer_list &components) {
        return srcpoint(point{dst_pt}, vec{components});
    }

    friend std::ostream &operator<<(std::ostream &os, const vec &v) {
        auto it = v.cbegin();
        auto it_end = v.cend();

        os << "[";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "]";

        return os;
    }

private:
    array m_components; ///< Vector components stored here.
};

/*!
    \class  gcs::vec<3, F>
    \brief  Template specialization for gcs::vec<3, F> (vector in R^3)

    \tparam F   Floating-point precision, default is double.
 */
template <typename F>
class gcs::vec<3, F> {
public:
    static constexpr auto N = 3;

    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;

    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    using point = point<N, F>;

    /*!
        \brief
    */
    vec() {
        reset();
    }
    
    /*!
        \brief
     
        \param[in]  arr
     */
    vec(const array &arr) : m_components(arr) {
        
    }
    
    /*!
        \brief
     
        \param[in]  arr
     */
    vec(array &&arr) : m_components(arr) {
        
    }
    
    /*!
        \brief

        \param[in]  components
    */
    vec(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }

    /*!
        \brief

        \param[in]  components
    */
    vec(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
    }
    
    /*!
        \brief

        \param[in]  v
    */
    vec(const vec &v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \param[in]  v
    */
    vec(vec &&v) : m_components(v.m_components) {
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point &src, const point &dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(point &&src, point &&dst) {
        auto src_it = src.cbegin();
        auto src_end = src.cend();
        auto dst_it = dst.cbegin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const initializer_list &src_pt, const initializer_list &dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }
    
    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(initializer_list &&src_pt, initializer_list &&dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        array result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief
     */
    ~vec() {
    }


    /*!
        \brief

        \return
     */
    iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \return
     */
    iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \return
     */
    const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \return
     */
    const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \return
     */
    reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \return
     */
    const_reverse_iterator crend() const {
        return m_components.crend();
    }

    /*!
        \brief

        \return
     */
    F x() const {
        return m_components[0];
    }

    /*!
        \brief

        \return
     */
    F y() const {
        return m_components[1];
    }
    
    /*!
        \brief
     
        \return
     */
    F z() const {
        return m_components[2];
    }
    
    /*!
        \brief

        \return
     */
    array get() const {
        return m_components;
    }
    
    /*!
        \brief

        \param[in]  x
     */
    void set_x(const F x) {
        m_components[0] = x;
    }

    /*!
        \brief

        \param[in]  y
     */
    void set_y(const F y) {
        m_components[1] = y;
    }
    
    /*!
        \brief
     
        \param[in]  z
     */
    void set_z(const F z) {
        m_components[2] = z;
    }
    
    /*!
        \brief
     
        \param[in]  x
        \param[in]  y
        \param[in]  z
     */
    void set(const F x, const F y, const F z) {
        m_components = std::array<F, N>{x, y, z};
    }
    
    /*!
        \brief

        \param[in]  arr
    */
    void set(const array &arr) {
        *(this) = arr;
    }
    
    /*!
        \brief

        \param[in]  arr
    */
    void set(array &&arr) {
        *(this) = arr;
    }

    /*!
        \brief

        \param[in]  components
    */
    void set(const initializer_list &components) {
        *(this) = components;
    }
    
    /*!
        \brief

        \param[in]  components
    */
    void set(initializer_list &&components) {
        *(this) = components;
    }

    /*!
        \brief

        \param[in]  v
    */
    void set(const vec &v) {
        *(this) = v;
    }
    
    /*!
        \brief

        \param[in]  v
    */
    void set(vec &&v) {
        *(this) = v;
    }
    
    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point &src_pt, const point &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(point &&src_pt, point &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const initializer_list &src_pt, const initializer_list &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }
    
    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(initializer_list &&src_pt, initializer_list &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(const initializer_list &components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }
    
    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(initializer_list &&components) {
        std::copy(components.begin(), components.begin() + N, begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(const vec &v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    vec &operator=(vec &&v) {
        std::copy(v.cbegin(), v.cend(), begin());
        return *this;
    }

    void reset() {
        m_components.fill(0);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    F &operator[](const int index) {
        return m_components[index];
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator==(const vec &v) const {
        return m_components == v.m_components;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) {
        return !(*(this) == v);
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    bool operator!=(const vec &v) const {
        return !(*(this) == v);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec operator+(const vec &v) const {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec operator-(const vec &v) const {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F operator*(const vec &v) const {
        auto v0 = cbegin();
        auto v1 = v.cbegin();

        auto U = const_cast<F *>(v0);
        auto V = const_cast<F *>(v1);

        return gcs::dot_product<N>(U, V);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec &operator+=(const vec &v) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec &operator-=(const vec &v) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \return
    */
    F magnitude() const {
        vec origin;
        const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F angle(const initializer_list &components) {
        return angle(vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F angle(const vec &v) const {
        F dot_product = *(this) * v;

        F product_magnitude = magnitude() * v.magnitude();
        F reciprocal_product_magnitude = 1 / product_magnitude;

        return std::acos(dot_product * reciprocal_product_magnitude);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const point &src_pt, const point &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(const initializer_list &src_pt, const initializer_list &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(const initializer_list &components) const {
        vec v{components};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F dot_product(const vec &v) const {
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const point &src_pt, const point &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }
    
    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(const initializer_list &src_pt,
                  const initializer_list &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    vec cross_product(const initializer_list &components) const {
        return cross_product(vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    vec cross_product(const vec &v) const {
        const auto U = m_components;
        const auto V = v.m_components;

        const F u1_v2 = U[1] * V[2];
        const F v1_u2 = V[1] * U[2];
        
        const F u0_v2 = U[0] * V[2];
        const F v0_u2 = V[0] * U[2];
        
        const F u0_v1 = U[0] * V[1];
        const F v0_u1 = V[0] * U[1];

        const auto x = (u1_v2 - v1_u2);
        const auto y = (u0_v2 - v0_u2) * (-1);    // v0u2 - u0v2
        const auto z = (u0_v1 - v0_u1);

        return vec{x, y, z};
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    vec cross_product(const point &src_pt, const point &dst_pt) const {
        return cross_product(vec{src_pt, dst_pt});
    }

    /*!
        \brief


        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    vec cross_product(const initializer_list &src_pt,
                      const initializer_list &dst_pt) const {
        return cross_product(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  os
    */
    void print_details(std::ostream &os) {
        os << "==============================="
           << "\n"
           << "V = " << *this << "\t\t" << this << "\n"
           << "-------------------------------"
           << "\n"
           << "Magnitude:      " << magnitude() << "\n";

        vec unit_vector;

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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const point &src_pt, const vec &dir) {
        point result = src_pt;
        auto dir_it = dir.cbegin();

        std::for_each(result.begin(), result.end(), [&dir_it](F &res) {
            res += *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dir

        \return
    */
    static point endpoint(const initializer_list &src_pt, const vec &dir) {
        return endpoint(point{src_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const point &src_pt,
                          const initializer_list &components) {
        return endpoint(src_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  components

        \return
    */
    static point endpoint(const initializer_list &src_pt,
                          const initializer_list &components) {
        return endpoint(point{src_pt}, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const point &dst_pt, const vec &dir) {
        point result = dst_pt;
        auto dir_it = const_cast<F *>(dir.cbegin());

        std::for_each(result.begin(), result.end(), [&](F &res) {
            res -= *(dir_it++);
        });

        return result;
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  dir

        \return
    */
    static point srcpoint(const initializer_list &dst_pt, const vec &dir) {
        return srcpoint(point{dst_pt}, dir);
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const point &dst_pt,
                          const initializer_list &components) {
        return srcpoint(dst_pt, vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  dst_pt
        \param[in]  components

        \return
    */
    static point srcpoint(const initializer_list &dst_pt,
                          const initializer_list &components) {
        return srcpoint(point{dst_pt}, vec{components});
    }

    friend std::ostream &operator<<(std::ostream &os, const vec &v) {
        auto it = v.cbegin();
        auto it_end = v.cend();

        os << "[";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "]";

        return os;
    }

private:
    array m_components; ///< Vector components stored here.
};

#endif /* VEC_HPP */
