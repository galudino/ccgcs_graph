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
    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;
    
    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    /*!
        \brief
     */
    point() {
        reset();
    }

    /*!
        \brief

        \param[in]  coords
    */
    point(const initializer_list &coords) {
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

        \param[in]  p
    */
    point(const point &&p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
    */
    ~point() {
    }

    /*!
        \brief
        \return
     */
    iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
        \return
     */
    iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
        \return
     */
    const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
        \return
     */
    const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crend() const {
        return m_coords.crend();
    }

    /*!
        \brief
        \return
     */
    array get() const {
        return m_coords;
    }

    /*!
        \brief

        \param[in]  coords
    */
    void set(const initializer_list &coords) {
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

        \param[in]  p
    */
    void set(const point &&p) {
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

        \param[in]  coords

        \return
    */
    point &operator=(const initializer_list &coords) {
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

        \param[in]  p

        \return
    */
    point &operator=(const point &&p) {
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

        \param[in]  p

        \return
    */
    bool operator==(const point &p) const {
        return m_coords == p.m_coords;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) const {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  coords

        \return
    */
    F distance(const initializer_list &coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &&p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
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
    array m_coords; ///< Point coordinates stored here.
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
    
    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;
    
    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    /*!
        \brief
     */
    point() {
        reset();
    }

    /*!
        \brief

        \param[in]  coords
    */
    point(const initializer_list &coords) {
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

        \param[in]  p
    */
    point(const point &&p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
    */
    ~point() {
    }

    /*!
        \brief
        \return
     */
    iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
        \return
     */
    iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
        \return
     */
    const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
        \return
     */
    const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crend() const {
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
    void set(const F &x, const F &y) {
        m_coords[0] = x;
        m_coords[1] = y;
    }

    /*!
        \brief
        \return
     */
    array get() const {
        return m_coords;
    }

    /*!
        \brief

        \param[in]  coords
    */
    void set(const initializer_list &coords) {
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

        \param[in]  p
    */
    void set(const point &&p) {
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

        \param[in]  coords

        \return
    */
    point &operator=(const initializer_list &coords) {
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

        \param[in]  p

        \return
    */
    point &operator=(const point &&p) {
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

        \param[in]  p

        \return
    */
    bool operator==(const point &p) const {
        return m_coords == p.m_coords;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) const {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  coords

        \return
    */
    F distance(const initializer_list &coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &&p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
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
    array m_coords; ///< Point coordinates stored here.
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
    
    using array = std::array<F, N>;
    using initializer_list = std::initializer_list<F>;
    
    using iterator = typename array::iterator;
    using const_iterator = typename array::const_iterator;
    using reverse_iterator = typename array::reverse_iterator;
    using const_reverse_iterator = typename array::const_reverse_iterator;

    /*!
        \brief
     */
    point() {
        reset();
    }

    /*!
        \brief

        \param[in]  coords
    */
    point(const initializer_list &coords) {
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

        \param[in]  p
    */
    point(const point &&p) : m_coords(p.m_coords) {
    }

    /*!
        \brief
    */
    ~point() {
    }

    /*!
        \brief
        \return
     */
    iterator begin() {
        return m_coords.begin();
    }

    /*!
        \brief
        \return
     */
    iterator end() {
        return m_coords.end();
    }

    /*!
        \brief
        \return
     */
    const_iterator cbegin() const {
        return m_coords.cbegin();
    }

    /*!
        \brief
        \return
     */
    const_iterator cend() const {
        return m_coords.cend();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rbegin() {
        return m_coords.rbegin();
    }

    /*!
        \brief
        \return
     */
    reverse_iterator rend() {
        return m_coords.rend();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crbegin() const {
        return m_coords.crbegin();
    }

    /*!
        \brief
        \return
     */
    const_reverse_iterator crend() const {
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
     */
    void set(const F &x, const F &y, const F &z) {
        m_coords[0] = x;
        m_coords[1] = y;
        m_coords[2] = z;
    }
    
    /*!
        \brief
        \return
     */
    array get() const {
        return m_coords;
    }

    /*!
        \brief

        \param[in]  coords
    */
    void set(const initializer_list &coords) {
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

        \param[in]  p
    */
    void set(const point &&p) {
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

        \param[in]  coords

        \return
    */
    point &operator=(const initializer_list &coords) {
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

        \param[in]  p

        \return
    */
    point &operator=(const point &&p) {
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

        \param[in]  p

        \return
    */
    bool operator==(const point &p) const {
        return m_coords == p.m_coords;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    bool operator!=(const point &p) const {
        return !(*(this) == p);
    }

    /*!
        \brief

        \param[in]  coords

        \return
    */
    F distance(const initializer_list &coords) const {
        return euclidean_distance<N, F>(cbegin(), coords.cbegin());
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
        return res;
    }

    /*!
        \brief

        \param[in]  p

        \return
    */
    F distance(const point &&p) const {
        auto p0 = const_cast<F *>(cbegin());
        auto p1 = const_cast<F *>(p.cbegin());
        auto res = euclidean_distance<N, F>(p0, p1);
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
    array m_coords; ///< Point coordinates stored here.
};

#endif /* POINT_HPP */
