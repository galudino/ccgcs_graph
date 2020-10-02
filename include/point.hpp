/*!
    \file       point.hpp
    \brief      Header file for a point ADT

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

#ifndef POINT_HPP
#define POINT_HPP

#include <array>
#include <ostream>

#include "gcs_utils.hpp"

namespace gcs {
template <size_t N, typename F = double>
class point;

template <typename F>
class point<2, F>;

template <typename F>
class point<3, F>;
} // namespace gcs

/*!
    \class  gcs::point
    \brief  Templated abstraction for a point on the Cartesian coordinate plane

    \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    \tparam F   Floating-point precision, default is double.
 */
template <size_t N, typename F>
class gcs::point {
public:
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  arr
     */
    point(const std::array<F, N> &arr) : m_coords(arr) {
        
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.

        \param[in]  coords
    */
    point(std::initializer_list<F> coords) {
        std::copy(coords.begin(), coords.begin() + N, m_coords.begin());
    }
    
    /*!
        \brief

        \param[in]  p
    */
    point(const point &p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
        return m_coords.crend();
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    std::array<F, N> get() const {
        return m_coords;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \return
     */
    void set(const std::array<F, N> &arr) {
        m_coords = arr;
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.

        \param[in]  coords
    */
    void set(std::initializer_list<F> coords) {
        *(this) = coords;
    }
    
    /*!
        \brief

        \param[in]  p
    */
    void set(const point &p) {
        *(this) = p;
    }
    
    /*!
        \brief
     */
    void reset() {
        m_coords.fill(0);
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.

        \param[in]  coords
    */
    point &operator=(std::initializer_list<F> coords) {
        m_coords = coords;
        return *this;
    }
    
    /*!
        \brief

        \param[in]  p

        \return
    */
    point &operator=(const point &p) {
        m_coords = p.m_coords;
        return *this;
    }
    
    /*!
        \brief
        \return
     */
    F &operator[](const int index) {
        return m_coords[index];
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator==(const point &p) {
        return m_coords == p.m_coords;
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.

        \param[in]  coords
     
        \return
    */
    F distance(std::initializer_list<F> coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) {
        auto p0 = cbegin();
        auto p1 = p.cbegin();
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    }

    /*!
        \brief

        \param[in]  os
    */
    void print_details(std::ostream &os) const {
        os << "==============================="
           << "\n"
           << *this << "\t\t" << this << "\n"
           << "===============================" << std::endl;
    }

    /*!
        \brief

        \param[out] os
        \param[in]  p

        \return
     */
    friend std::ostream &operator<<(std::ostream &os, const point &p) {
        auto it = p.cbegin();
        auto it_end = p.cend();

        os << "{";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "}";

        return os;
    }

protected:
    std::array<F, N> m_coords; ///< Point coordinates stored here.
};

/*!
    \class  gcs::point<2, F>
    \brief  Template specialization of gcs::point<2, F> (point in R^2)

    \tparam F   Floating-point precision, default is double.
 */
template <typename F>
class gcs::point<2, F> {
public:
    static constexpr auto N = 2;
    
    /*!
        \brief
     */
    point() {
        reset();
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.

        \param[in]  x
        \param[in]  y
     */
    point(const F x, const F y) : m_coords(std::array<F, N>{x, y}) {
        
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \param[in]  arr
     */
    point(const std::array<F, N> &arr) : m_coords(arr) {
        
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords
    */
    point(std::initializer_list<F> &coords) {
        std::copy(coords.begin(), coords.begin() + N, m_coords.begin());
    }
    
    /*!
        \brief

        \param[in]  p
    */
    point(const point &p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
        return m_coords.crend();
    }
    
    /*!
        \brief
     
        \return
     */
    F x() const {
        return m_coords[0];
    }
    
    /*!
        \brief
     
        \return
     */
    F y() const {
        return m_coords[1];
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \return
     */
    std::array<F, N> get() const {
        return m_coords;
    }
    
    /*!
        \brief
     
        \param[in]  x
     */
    void set_x(const F &x) {
        m_coords[0] = x;
    }
    
    /*!
        \brief
     
        \param[in]  y
     */
    void set_y(const F &y) {
        m_coords[1] = y;
    }
    
    /*!
        \brief
     
        \param[in]  x
        \param[in]  y
     */
    void set(const F x, const F y) {
        m_coords[0] = x;
        m_coords[1] = y;
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space
     
        \param[in]  arr
     */
    void set(const std::array<F, N> &arr) {
        m_coords = arr;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords
    */
    void set(std::initializer_list<F> coords) {
        *(this) = coords;
    }

    /*!
        \brief

        \param[in]  p
    */
    void set(const point &p) {
        *(this) = p;
    }
    
    /*!
        \brief
     */
    void reset() {
        m_coords.fill(0);
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords

        \return
    */
    point &operator=(std::initializer_list<F> coords) {
        std::copy(coords.begin(), coords.begin() + N, begin());
        return *this;
    }
    
    /*!
        \brief

        \param[in]  p

        \return
    */
    point &operator=(const point &p) {
        std::copy(p.cbegin(), p.cend(), begin());
        return *this;
    }

    /*!
        \brief
        \return
     */
    F &operator[](const int index) {
        return m_coords[index];
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator==(const point &p) {
        return m_coords == p.m_coords;
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords

        \return
    */
    F distance(std::initializer_list<F> coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) {
        auto p0 = cbegin();
        auto p1 = p.cbegin();
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    };

    /*!
        \brief

        \param[in]  os
    */
    void print_details(std::ostream &os) const {
        os << "==============================="
           << "\n"
           << *this << "\t\t" << this << "\n"
           << "===============================" << std::endl;
    }

    /*!
        \brief

        \param[out] os
        \param[in]  p

        \return
     */
    friend std::ostream &operator<<(std::ostream &os, const point &p) {
        auto it = p.cbegin();
        auto it_end = p.cend();

        os << "{";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "}";

        return os;
    }

protected:
    std::array<F, N> m_coords; ///< Point coordinates stored here.
};

/*!
    \class  gcs::point<3, F>
    \brief  Template specialization for gcs::point<3, F> (point in R^3)

    \tparam F   Floating-point precision, default is double.
 */
template <typename F>
class gcs::point<3, F> {
public:
    static constexpr auto N = 3;

    /*!
        \brief
     */
    point() {
        reset();
    }
    
    /*!
        \brief
     
        \param[in]  x
        \param[in]  y
        \param[in]  z
     */
    point(const F x, const F y, const F z) : m_coords(std::array<F, N>{x, y, z}) {
        
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \param[in]  arr
     */
    point(const std::array<F, N> &arr) : m_coords(arr) {
        
    }
    

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.

        \param[in]  coords
    */
    point(std::initializer_list<F> coords) {
        std::copy(coords.begin(), coords.begin() + N, m_coords.begin());
    }

    /*!
        \brief

        \param[in]  p
    */
    point(const point &p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
    
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    typename std::array<F, N>::const_reverse_iterator crend() const {
        return m_coords.crend();
    }

    /*!
        \brief
     
        \return
     */
    F x() const {
        return m_coords[0];
    }
    
    /*!
        \brief
     
        \return
     */
    F y() const {
        return m_coords[1];
    }
    
    /*!
        \brief
     
        \return
     */
    F z() const {
        return m_coords[2];
    }
    
    /*!
        \brief
     
        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
     
        \return
     */
    std::array<F, N> get() const {
        return m_coords;
    }
    
    /*!
        \brief
     
        \param[in]  x
     */
    void set_x(const F &x) {
        m_coords[0] = x;
    }
    
    /*!
        \brief
     
        \param[in]  y
     */
    void set_y(const F &y) {
        m_coords[1] = y;
    }
    
    /*!
        \brief
     
        \param[in]  z
     */
    void set_z(const F &z) {
        m_coords[2] = z;
    }
    
    /*!
        \brief
     
        \param[in]  x
        \param[in]  y
        \param[in]  z
     */
    void set(const F x, const F y, const F z) {
        m_coords[0] = x;
        m_coords[1] = y;
        m_coords[2] = z;
    }
    
    /*!
        \brief

        \tparam F   Floating-point precision, default is double.
        \tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
      
        \param[in]  arr
     */
    void set(const std::array<F, N> &arr) {
        m_coords = arr;
    }
    
    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords
    */
    void set(std::initializer_list<F> coords) {
        *(this) = coords;
    }

    /*!
        \brief

        \param[in]  p
    */
    void set(const point &p) {
        *(this) = p;
    }
        
    /*!
        \brief
     */
    void reset() {
        m_coords.fill(0);
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords

        \return
    */
    point &operator=(std::initializer_list<F> coords) {
        m_coords = coords;
        return *this;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    point &operator=(const point &p) {
        m_coords = p.m_coords;
        return *this;
    }

    /*!
        \brief
        \return
     */
    F &operator[](const int index) {
        return m_coords[index];
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator==(const point &p) {
        return m_coords == p.m_coords;
    }

    /*!
        \brief
        
        \tparam F   Floating-point precision, default is double.
        
        \param[in]  coords

        \return
    */
    F distance(std::initializer_list<F> coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) {
        auto p0 = cbegin();
        auto p1 = p.cbegin();
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    }

    /*!
        \brief

        \param[in]  os
    */
    void print_details(std::ostream &os) const {
        os << "==============================="
           << "\n"
           << *this << "\t\t" << this << "\n"
           << "===============================" << std::endl;
    }

    /*!
        \brief

        \param[out] os
        \param[in]  p

        \return
     */
    friend std::ostream &operator<<(std::ostream &os, const point &p) {
        auto it = p.cbegin();
        auto it_end = p.cend();

        os << "{";
        while (it < it_end) {
            os << *(it);

            if (it < it_end - 1) {
                os << ", ";
            }

            ++it;
        }
        os << "}";

        return os;
    }

protected:
    std::array<F, N> m_coords; ///< Point coordinates stored here.
};

#endif /* POINT_HPP */
