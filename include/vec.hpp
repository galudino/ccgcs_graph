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
    /*!
        \brief
     */
    vec() {
        reset();
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  arr
     */
    vec(const std::array<F, N> &arr) : m_components(arr) {
        
    }
    

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    vec(std::initializer_list<F> components) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point<N, F> &src, const point<N, F> &dst) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        std::array<F, N> result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }
  
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
        return m_components.crend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    std::array<F, N> get() const {
        return m_components;
    }
    
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
         
        \param[in]  arr
    */
    void set(const std::array<F, N> &arr) {
        *(this) = arr;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    void set(std::initializer_list<F> components) {
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
        
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        
        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components

        \return
    */
    vec &operator=(std::initializer_list<F> components) {
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

        \return
    */
    F magnitude() const {
        vec origin;
        typename std::array<F, N>::const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \param[in]  components

        \return
    */
    F angle(std::initializer_list<F> components) {
        return angle(vec{components});
    }

    /*!
        \brief

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
    F angle(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(std::initializer_list<F> components) {
        vec v{components};
        return *(this) * v;
    }

    /*!
        \brief

        \param[in]  v

        \return
    */
    F dot_product(const vec &v) {
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
    F dot_product(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F dot_product(std::initializer_list<F> src_pt,
                  std::initializer_list<F> dst_pt) {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

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
    static point<N, F> endpoint(const point<N, F> &src_pt, const vec<N, F> &dir) {
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
    static point<N, F> endpoint(std::initializer_list<F> src_pt, const vec &dir) {
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
    static point<N, F> endpoint(const point<N, F> &src_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> endpoint(std::initializer_list<F> src_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt, const vec<N, F> &dir) {
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
    static point<N, F> srcpoint(std::initializer_list<F> dst_pt, const vec<N, F> &dir) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> srcpoint(std::initializer_list<F> dst_pt,
                          std::initializer_list<F> components) {
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
    std::array<F, N> m_components; ///< Vector components stored here.
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
    
    /*!
        \brief
    */
    vec() {
        reset();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  arr
     */
    vec(const std::array<F, N> &arr) : m_components(arr) {
        
    }
        
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    vec(std::initializer_list<F> components) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point<N, F> &src, const point<N, F> &dst) {
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

        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        std::array<F, N> result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
        return m_components.crend();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \return
     */
    F x() const {
        return m_components[0];
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \return
     */
    F y() const {
        return m_components[1];
    }
    
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    std::array<F, N> get() const {
        return m_components;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  x
     */
    void set_x(const F x) {
        m_components[0] = x;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  y
     */
    void set_y(const F y) {
        m_components[1] = y;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  x
        \param[in]  y
     */
    void set(const F x, const F y) {
        m_components = std::array<F, N>{x, y};
    }

   /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  arr
    */
    void set(const std::array<F, N> &arr) {
        *(this) = arr;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    void set(std::initializer_list<F> components) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components

        \return
    */
    vec &operator=(std::initializer_list<F> components) {
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

          \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
          \tparam F   Floating-point precision, default is double.

          \param[in]  v

          \return
      */
      vec operator+(const vec &v) {
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
      vec operator-(const vec &v) {
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
      F operator*(const vec &v) {
          auto v0 = cbegin();
          auto v1 = v.cbegin();
          return gcs::dot_product<N>(v0, v1);
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
        typename std::array<F, N>::const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F angle(std::initializer_list<F> components) {
        return angle(vec{components});
    }

    /*!
        \brief

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  v

        \return
    */
    F angle(const vec &v) {
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
    F angle(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(std::initializer_list<F> components) {
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
    F dot_product(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
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
    F dot_product(std::initializer_list<F> src_pt,
                  std::initializer_list<F> dst_pt) {
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
    static point<N, F> endpoint(const point<N, F> &src_pt, const vec &dir) {
        point<N, F> result = src_pt;
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
    static point<N, F> endpoint(std::initializer_list<F> src_pt, const vec &dir) {
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
    static point<N, F> endpoint(const point<N, F> &src_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> endpoint(std::initializer_list<F> src_pt,
                                std::initializer_list<F> components) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt, const vec &dir) {
        point<N, F> result = dst_pt;
        auto dir_it = dir.cbegin();

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
    static point<N, F> srcpoint(std::initializer_list<F> dst_pt, const vec &dir) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt,
                                std::initializer_list<F> components) {
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
    static point<N, F> srcpoint(std::initializer_list<F> dst_pt,
                                std::initializer_list<F> components) {
        return srcpoint(point{dst_pt}, vec{components});
    }
    
    /*!
        \brief
     
        \param[out] os
        \param[in]  v
     
        \return
    */
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
    std::array<F, N> m_components; ///< Vector components stored here.
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

    /*!
        \brief
    */
    vec() {
        reset();
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  arr
     */
    vec(const std::array<F, N> &arr) : m_components(arr) {
        
    }
    
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    vec(std::initializer_list<F> components) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(const point<N, F> &src, const point<N, F> &dst) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src
        \param[in]  dst
    */
    vec(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        auto src_it = src_pt.begin();
        auto src_end = src_pt.end();
        auto dst_it = dst_pt.begin();

        std::array<F, N> result;
        auto it = result.begin();

        while (src_it < src_end) {
            *(it++) = *(dst_it++) - *(src_it++);
        }

        m_components = result;
    }
    
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_components.begin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_components.end();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_components.cbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_components.cend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_components.rbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_components.rend();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_components.crbegin();
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
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

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        
        \return
     */
    std::array<F, N> get() const {
        return m_components;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  x
     */
    void set_x(const F x) {
        m_components[0] = x;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  y
     */
    void set_y(const F y) {
        m_components[1] = y;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  z
     */
    void set_z(const F z) {
        m_components[2] = z;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  x
        \param[in]  y
        \param[in]  z
     */
    void set(const F x, const F y, const F z) {
        m_components = std::array<F, N>{x, y, z};
    }
    
    /*!
         \brief
         
         \tparam F   Floating-point precision, default is double.
         \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

         \param[in]  arr
     */
    void set(const std::array<F, N> &arr) {
        *(this) = arr;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components
    */
    void set(std::initializer_list<F> components) {
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

        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  components

        \return
    */
    vec &operator=(std::initializer_list<F> components) {
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
        typename std::array<F, N>::const_iterator it = cbegin();
        return gcs::euclidean_distance<N, F>(origin.begin(),
                                             const_cast<F *>(it));
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F angle(std::initializer_list<F> components) {
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
    F angle(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  src_pt
        \param[in]  dst_pt

        \return
    */
    F angle(std::initializer_list<F> src_pt, std::initializer_list<F> dst_pt) {
        return angle(vec{src_pt, dst_pt});
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    F dot_product(std::initializer_list<F> components) const {
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
    F dot_product(const point<N, F> &src_pt, const point<N, F> &dst_pt) const {
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
    F dot_product(std::initializer_list<F> &src_pt,
                  std::initializer_list<F> &dst_pt) const {
        vec v{src_pt, dst_pt};
        return *(this) * v;
    }

    /*!
        \brief

        \tparam F   Floating-point precision, default is double.

        \param[in]  components

        \return
    */
    vec cross_product(std::initializer_list<F> components) const {
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
    vec cross_product(const point<N, F> &src_pt, const point<N, F> &dst_pt) const {
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
    vec cross_product(std::initializer_list<F> src_pt,
                      std::initializer_list<F> dst_pt) const {
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
    static point<N, F> endpoint(const point<N, F> &src_pt, const vec &dir) {
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
    static point<N, F> endpoint(std::initializer_list<F> &src_pt, const vec &dir) {
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
    static point<N, F> endpoint(const point<N, F> &src_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> endpoint(std::initializer_list<F>src_pt,
                          std::initializer_list<F> components) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt, const vec &dir) {
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
    static point<N, F> srcpoint(std::initializer_list<F> &dst_pt, const vec &dir) {
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
    static point<N, F> srcpoint(const point<N, F> &dst_pt,
                          std::initializer_list<F> &components) {
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
    static point<N, F> srcpoint(std::initializer_list<F> dst_pt,
                          std::initializer_list<F> components) {
        return srcpoint(point{dst_pt}, vec{components});
    }
    
    /*!
        \brief
     
        \param[out] os
        \param[in]  v
     
        \return
    */
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
    std::array<F, N> m_components; ///< Vector components stored here.
};

#endif /* VEC_HPP */
