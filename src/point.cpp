/*!
    \file       point.cpp
    \brief      Source file for a point ADT

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

#define _USE_MATH_DEFINES
#include <cmath>

#include <memory>

#include "header.hpp"
#include "point.hpp"

using gcs::point2D;

/*!
    \brief
 */
point2D::point2D() : m_x{0.0}, m_y{0.0} {
}

/*!
    \brief

    \param[in]  x
    \param[in]  y
 */
point2D::point2D(double x, double y) : m_x{x}, m_y{y} {
}

/*!
    \brief

    \param[in]  p
 */
point2D::point2D(const point2D &p) : m_x{p.m_x}, m_y{p.m_y} {
}

/*!
    \brief

    \param[in]  arr
*/
point2D::point2D(std::array<double, 2> &arr) : m_x{arr[0]}, m_y{arr[1]} {
}

/*!
    \brief
*/
point2D::~point2D() {
}

/*!
    \brief

    \return
*/
double point2D::x() const {
    return m_x;
}

/*!
    \brief

    \return
*/
double point2D::y() const {
    return m_y;
}

/*!
    \brief

    \return
*/
std::array<double, 2> point2D::get() const {
    return std::array<double, 2>{m_x, m_y};
}

/*!
    \brief

    \param[in]  x
*/
void point2D::set_x(double x) {
    m_x = x;
}

/*!
    \brief

    \param[in]  y
*/
void point2D::set_y(double y) {
    m_y = y;
}

/*!
    \brief

    \param[in]  x
    \param[in]  y
*/
void point2D::set(double x, double y) {
    m_x = x;
    m_y = y;
}

/*!
    \brief

    \param[in]  p
*/
void point2D::set(const point2D &p) {
    m_x = p.m_x;
    m_y = p.m_y;
}

/*!
    \brief

    \param[in]  arr
*/
void point2D::set(std::array<double, 2> &arr) {
    m_x = arr[0];
    m_y = arr[1];
}

/*!
    \brief
*/
void point2D::reset() {
    m_x = m_y = 0.0;
}

/*!
    \brief

    \param[in]  p

    \return
*/
point2D &point2D::operator=(const point2D &p) {
    m_x = p.m_x;
    m_y = p.m_y;

    return *this;
}

/*!
    \brief

    \param[in]  index

    \return
*/
inline double &point2D::operator[](int index) const {
    double *base = (double *)(&m_x);
    return *(base + index);
}

/*!
    \brief

    \param[in]  p

    \return
*/
bool point2D::operator==(const point2D &p) {
    bool xeql = gcs::double_approx_eq(m_x, p.m_x);
    bool yeql = gcs::double_approx_eq(m_y, p.m_y);

    return xeql && yeql;
}

/*!
    \brief

    \param[in]  p

    \return
*/
bool point2D::operator!=(const point2D &p) {
    return !(*(this) == p);
}

/*!
    \brief

    \param[in]  os
    \param[in]  p

    \return
*/
std::ostream &gcs::operator<<(std::ostream &os, const point2D &p) {
    os << "(" << p.m_x << ", " << p.m_y << ")   \t(" << &p << ")";
    return os;
}

/*!
    \brief

    \param[in]  u_x
    \param[in]  u_y
    \param[in]  v_x
    \param[in]  v_y

    \return
*/
double point2D::distance(double u_x, double u_y, double v_x, double v_y) {
    double u[] = {u_x, u_y};
    double v[] = {v_x, v_y};

    return gcs::euclidean_distance<2>(u, v);
}

/*!
    \brief

    \param[in]  u
    \param[in]  v

    \return
 */
double point2D::distance(const point2D &u, const point2D &v) {
    return gcs::euclidean_distance<2>(u.get().data(), v.get().data());
}

/*!
    \brief

    \param[in]  arr_u
    \param[in]  arr_v

    \return
*/
double point2D::distance(std::array<double, 2> &arr_u,
                         std::array<double, 2> &arr_v) {
    return gcs::euclidean_distance<2>(arr_u.data(), arr_v.data());
}

using gcs::point3D;

/*!
    \brief
*/
point3D::point3D() : m_2d{}, m_z{0.0} {
}

/*!
    \brief

    \param[in]  x
    \param[in]  y
    \param[in]  z
*/
point3D::point3D(double x, double y, double z) : m_2d{x, y}, m_z{z} {
}

/*!
    \brief

    \param[in]  arr
*/
point3D::point3D(std::array<double, 3> &arr)
    : m_2d{arr[0], arr[1]}, m_z{arr[2]} {
}

/*!
    \brief

    \param[in]  p
*/
point3D::point3D(const point3D &p) : m_2d{p.m_2d[0], p.m_2d[1]}, m_z{p.m_z} {
}

/*!
    \brief

    \param[in]  p
*/
point3D::point3D(const point2D &p) : m_2d{p}, m_z{0.0} {
}

/*!
    \brief
*/
point3D::~point3D() {
}

/*!
    \brief

    \return
*/
double point3D::x() const {
    return m_2d.x();
}

/*!
    \brief

    \return
*/
double point3D::y() const {
    return m_2d.y();
}

/*!
    \brief

    \return
*/
double point3D::z() const {
    return m_z;
}

/*!
    \brief

    \return
*/
std::array<double, 3> point3D::get() const {
    return std::array<double, 3>{m_2d[0], m_2d[1], m_z};
}

/*!
    \brief

    \param[in]  x
*/
void point3D::set_x(double x) {
    m_2d[0] = x;
}

/*!
    \brief

    \param[in]  y
*/
void point3D::set_y(double y) {
    m_2d[1] = y;
}

/*!
    \brief

    \param[in]  z
*/
void point3D::set_z(double z) {
    m_z = z;
}

/*!
    \brief

    \param[in]  x
    \param[in]  y
    \param[in]  z
*/
void point3D::set(double x, double y, double z) {
    m_2d[0] = x;
    m_2d[1] = y;
    m_z = z;
}

/*!
    \brief

    \param[in]  p
*/
void point3D::set(const point3D &p) {
    m_2d[0] = p.m_2d[0];
    m_2d[1] = p.m_2d[1];
    m_z = p.m_z;
}

/*!
    \brief

    \param[in]  arr
*/
void point3D::set(std::array<double, 3> &arr) {
    m_2d[0] = arr[0];
    m_2d[1] = arr[1];
    m_z = arr[2];
}

/*!
    \brief
*/
void point3D::reset() {
    m_2d[0] = m_2d[1] = m_z = 0.0;
}

/*!
    \brief

    \param[in]  p

    \return
*/
point3D &point3D::operator=(const point3D &p) {
    m_2d[0] = p.m_2d[0];
    m_2d[1] = p.m_2d[1];
    m_z = p.m_2d[2];

    return *this;
}

/*!
    \brief

    \param[in]  index

    \return
*/
double &point3D::operator[](int index) const {
    return m_2d[index];
}

/*!
    \brief

    \param[in]  p

    \return
*/
bool point3D::operator==(const point3D &p) {
    bool xeql = gcs::double_approx_eq(m_2d[0], p.m_2d[0]);
    bool yeql = gcs::double_approx_eq(m_2d[1], p.m_2d[1]);
    bool zeql = gcs::double_approx_eq(m_z, p.m_z);

    return xeql && yeql && zeql;
}

/*!
    \brief

    \param[in]  p

    \return
*/
bool point3D::operator!=(const point3D &p) {
    return !(*this == p);
}

/*!
    \brief

    \param[out] os
    \param[in]  p

    \return
*/
std::ostream &gcs::operator<<(std::ostream &os, const point3D &p) {
    os << "(" << p.m_2d.x() << ", " << p.m_2d.y() << ", " << p.m_z << ")\t("
       << &p << ")";
    return os;
}

/*!
    \brief

    \param[in]  u_x
    \param[in]  u_y
    \param[in]  u_z
    \param[in]  v_x
    \param[in]  v_y
    \param[in]  v_z
 
    \return
*/
double point3D::distance(double u_x, double u_y, double u_z, double v_x,
                         double v_y, double v_z) {
    double u[] = {u_x, u_y, u_z};
    double v[] = {v_x, v_y, v_z};

    return gcs::euclidean_distance<3>(u, v);
}

/*!
   \brief

   \param[in]  u
   \param[in]  v

   \return
*/
double point3D::distance(const point3D &u, const point3D &v) {
    return gcs::euclidean_distance<3>(u.get().data(), v.get().data());
}

/*!
   \brief

   \param[in]  arr_u
   \param[in]  arr_v

   \return
*/
double point3D::distance(std::array<double, 3> &arr_u,
                         std::array<double, 3> &arr_v) {
    return gcs::euclidean_distance<3>(arr_u.data(), arr_v.data());
}
