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
} // namespace gcs

/*!
    \class  gcs::vec
    \brief  Templated abstraction for a vector (trajectory, direction) on the
   Cartesian coordinate plane

    @tparam N   Represents dimension, i.e. N = 2 is R^2 - 2D space.
    @tparam F   Floating-point precision, default is double.
 */
template <size_t N, typename F>
class gcs::vec {
public:
    using iterator = typename std::array<F, N>::iterator;
    using const_iterator = typename std::array<F, N>::const_iterator;

    using reverse_iterator = typename std::array<F, N>::reverse_iterator;

    using const_reverse_iterator =
        typename std::array<F, N>::const_reverse_iterator;

    /*!
        \brief
    */
    vec() {
        reset();
    }

    /*!
        \brief

        \param[in]  components
    */
    vec(const std::initializer_list<F> &components) {
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
    vec(const vec &&v) : m_components(v.m_components) {
    }

    vec(const point<N, F> &src, const point<N, F> &dst);
    vec(const point<N, F> &&src, const point<N, F> &&dst);
    vec(const std::initializer_list<F> &src_pt,
        const std::initializer_list<F> &dst_pt);

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
    std::array<F, N> get() const {
        return m_components;
    }

    /*!
        \brief

        \param[in]  components
    */
    void set(const std::initializer_list<F> &components) {
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

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point<N, F> &src_pt, const point<N, F> &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const point<N, F> &&src_pt, const point<N, F> &&dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  src_pt
        \param[in]  dst_pt
    */
    void set(const std::initializer_list<F> &src_pt,
             const std::initializer_list<F> &dst_pt) {
        *(this) = vec{src_pt, dst_pt};
    }

    /*!
        \brief

        \param[in]  components

        \return
    */
    vec &operator=(const std::initializer_list<F> &components) {
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
    vec &operator=(const vec &&v) {
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

    vec operator+(const vec &v) const;
    vec operator+(const vec &&v) const;
    vec operator-(const vec &v) const;
    vec operator-(const vec &&v) const;
    F operator*(const vec &v) const;
    F operator*(const vec &&v) const;

    vec &operator+=(const vec &v);
    vec &operator-=(const vec &v);

    F magnitude() const;

    F angle(const std::initializer_list<F> &components);
    F angle(const vec &v) const;
    F angle(const vec &&v) const;
    F angle(const point<N, F> &src_pt, const point<N, F> &dst_pt);
    F angle(const point<N, F> &&src_pt, const point<N, F> &&dst_pt);

    F angle(const std::initializer_list<F> &src_pt,
            const std::initializer_list<F> &dst_pt);

    F dot_product(const std::initializer_list<F> &components) const;
    F dot_product(const vec &v) const;
    F dot_product(const vec &&v) const;
    F dot_product(const point<N, F> &src_pt, const point<N, F> &dst_pt) const;
    F dot_product(const point<N, F> &&src_pt, const point<N, F> &&dst_pt) const;

    F dot_product(const std::initializer_list<F> &src_pt,
                  const std::initializer_list<F> &&dst_pt) const;

    vec cross_product(const std::initializer_list<F> &components) const;
    vec cross_product(const vec &v) const;
    vec cross_product(const vec &&v) const;

    vec cross_product(const point<N, F> &src_pt,
                      const point<N, F> &dst_pt) const;

    vec cross_product(const point<N, F> &&src_pt,
                      const point<N, F> &&dst_pt) const;

    vec cross_product(const std::initializer_list<F> &src_pt,
                      const std::initializer_list<F> &&dst_pt) const;

    void print_details(std::ostream &os);

    static point<N, F> endpoint(const point<N, F> &src_pt,
                                const vec<N, F> &dir);

    static point<N, F> endpoint(const point<N, F> &&src_pt,
                                const vec<N, F> &&dir);

    static point<N, F> endpoint(const std::initializer_list<F> &src_pt,
                                const vec<N, F> &dir);

    static point<N, F> endpoint(const point<N, F> &src_pt,
                                const std::initializer_list<F> &components);

    static point<N, F> endpoint(const std::initializer_list<F> &src_pt,
                                const std::initializer_list<F> &components);

    static point<N, F> srcpoint(const point<N, F> &dst_pt,
                                const vec<N, F> &dir);

    static point<N, F> srcpoint(const point<N, F> &&dst_pt,
                                const vec<N, F> &&dir);

    static point<N, F> srcpoint(const std::initializer_list<F> &dst_pt,
                                const vec<N, F> &dir);

    static point<N, F> srcpoint(const point<N, F> &dst_pt,
                                const std::initializer_list<F> &components);

    static point<N, F> srcpoint(const std::initializer_list<F> &dst_pt,
                                const std::initializer_list<F> &components);

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

#include "vec_impl.hpp" // implementation of templated member functions

#endif /* VEC_HPP */
