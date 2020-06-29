/**
 *  @file       position.cpp
 *  @brief      Source file for a position ADT
 *
 *  @author     Gemuele Aludino
 *  @date       20 Jun 2019
 *  @copyright  Copyright © 2020 Gemuele Aludino
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

#define _USE_MATH_DEFINES
#include <cmath>

#include "position.hpp"
#include <cmath>
#include <memory>

using gcs::position2D;
using gcs::position3D;

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 *
 *  @return
 */
inline bool gcs::double_approx_eq(double a, double b) {
    return std::abs(a - b) < gcs::epsilon;
}

/**
 *  @brief
 *
 *  @param[in]  radians
 *
 *  @return
 */
double gcs::to_degrees(double radians) {
    return radians * (180.0f / M_PI);
}

/**
 *  @brief
 *
 *  @param[in]  degrees
 *
 *  @return
 */
double gcs::to_radians(double degrees) {
    return degrees * (M_PI / 180.0f);
}

/**
 *  @brief
 */
position2D::position2D() : m_x(0.0), m_y(0.0) {
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 */
position2D::position2D(double x, double y) : m_x(x), m_y(y) {
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
position2D::position2D(const position2D &p) : m_x(p.m_x), m_y(p.m_y) {
}

/**
 *  @brief
 *
 *  @param[in]  arr
 */
position2D::position2D(std::array<double, 2> &arr) : m_x(arr[0]), m_y(arr[1]) {
}

/**
 *  @brief
 */
position2D::~position2D() {
}

/**
 *  @brief
 *
 *  @return
 */
inline double position2D::x() const {
    return m_x;
}

/**
 *  @brief
 *
 *  @return
 */
inline double position2D::y() const {
    return m_y;
}

/**
 *  @brief
 *
 *  @return
 */
std::array<double, 2> position2D::get() const {
    return std::array<double, 2>{m_x, m_y};
}

/**
 *  @brief
 *
 *  @param[in]  x
 */
void position2D::set_x(double x) {
    m_x = x;
}

/**
 *  @brief
 *
 *  @param[in]  y
 */
void position2D::set_y(double y) {
    m_y = y;
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 */
void position2D::set(double x, double y) {
    m_x = x;
    m_y = y;
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
void position2D::set(const position2D &p) {
    m_x = p.m_x;
    m_y = p.m_y;
}

/**
 *  @brief
 *
 *  @param[in]  arr
 */
void position2D::set(std::array<double, 2> &arr) {
    m_x = arr[0];
    m_y = arr[1];
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 *
 *  @return
 */
double position2D::distance_to(double x, double y) const {
    double dx = x - m_x;
    double dy = y - m_y;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
double position2D::distance_to(const position2D &p) const {
    double dx = p.m_x - m_x;
    double dy = p.m_y - m_y;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 *
 *  @param[in]  arr
 *
 *  @return
 */
double position2D::distance_to(std::array<double, 2> &arr) const {
    double dx = arr[0] - m_x;
    double dy = arr[1] - m_y;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 */
inline void position2D::reset() {
    m_x = m_y = 0.0;
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
position2D &position2D::operator=(const position2D &p) {
    m_x = p.m_x;
    m_y = p.m_y;

    return *this;
}

/**
 *  @brief
 *
 *  @param[in]  index
 *
 *  @return
 */
inline double &position2D::operator[](int index) const {
    double *base = (double *)(&m_x);
    return *(base + index);
}

/**
 *  @brief
 *
 *  @param[in]
 *
 *  @return
 */
bool position2D::operator==(const position2D &p) const {
    bool xeql = gcs::double_approx_eq(m_x, p.m_x);
    bool yeql = gcs::double_approx_eq(m_y, p.m_y);

    return xeql && yeql;
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
bool position2D::operator!=(const position2D &p) const {
    return !(*(this) == p);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position2D position2D::operator+(const position2D &p) const {
    double x = m_x + p.m_x;
    double y = m_y + p.m_y;

    return position2D(x, y);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position2D position2D::operator-(const position2D &p) const {
    double x = m_x - p.m_x;
    double y = m_y - p.m_y;

    return position2D(x, y);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position2D position2D::operator*(const position2D &p) const {
    double x = (m_x * p.m_x) + (m_x * p.m_y);
    double y = (m_y * p.m_y) + (m_y * p.m_y);

    return position2D(x, y);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position2D position2D::operator/(const position2D &p) const {
    double x = (m_x / p.m_x) + (m_x / p.m_y);
    double y = (m_y / p.m_y) + (m_y / p.m_y);

    return position2D(x, y);
}

/**
 *  @brief
 *
 *  @param[in]  os
 *  @param[in]  p
 *
 *  @return
 */
std::ostream &gcs::operator<<(std::ostream &os, const position2D &p) {
    os << "(" << p.m_x << ", " << p.m_y << ")";
    return os;
}

/**
 *  @brief
 */
position3D::position3D() : m_2d(), m_z(0.0) {
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 *  @param[in]  z
 */
position3D::position3D(double x, double y, double z) : m_2d(x, y), m_z(z) {
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
position3D::position3D(const position3D &p)
    : m_2d(p.m_2d[0], p.m_2d[1]), m_z(p.m_z) {
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
position3D::position3D(const position2D &p) : m_2d(p), m_z(0.0) {
}

/**
 *  @brief
 */
position3D::~position3D() {
}

/**
 *  @brief
 *
 *  @return
 */
double position3D::x() const {
    return m_2d.x();
}

/**
 *  @brief
 *
 *  @return
 */
double position3D::y() const {
    return m_2d.y();
}

/**
 *  @brief
 *
 *  @return
 */
double position3D::z() const {
    return m_z;
}

/**
 *  @brief
 *
 *  @return
 */
std::array<double, 3> position3D::get() const {
    return std::array<double, 3>{m_2d[0], m_2d[1], m_z};
}

/**
 *  @brief
 *
 *  @param[in]  x
 */
void position3D::set_x(double x) {
    m_2d[0] = x;
}

/**
 *  @brief
 *
 *  @param[in]  y
 */
void position3D::set_y(double y) {
    m_2d[1] = y;
}

/**
 *  @brief
 *
 *  @param[in]  z
 */
void position3D::set_z(double z) {
    m_z = z;
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 *  @param[in]  z
 */
void position3D::set(double x, double y, double z) {
    m_2d[0] = x;
    m_2d[1] = y;
    m_z = z;
}

/**
 *  @brief
 *
 *  @param[in]  p
 */
void position3D::set(const position3D &p) {
    m_2d[0] = p.m_2d[0];
    m_2d[1] = p.m_2d[1];
    m_z = p.m_z;
}

/**
 *  @brief
 *
 *  @param[in]  arr
 */
void position3D::set(std::array<double, 3> &arr) {
    m_2d[0] = arr[0];
    m_2d[1] = arr[1];
    m_z = arr[2];
}

/**
 *  @brief
 *
 *  @param[in]  x
 *  @param[in]  y
 *  @param[in]  z
 *
 *  @return
 */
double position3D::distance_to(double x, double y, double z) const {
    double dx = x - m_2d[0];
    double dy = y - m_2d[1];
    double dz = z - m_z;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0) + std::pow(dz, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
double position3D::distance_to(position3D &p) const {
    double dx = p.m_2d[0] - m_2d[0];
    double dy = p.m_2d[1] - m_2d[1];
    double dz = p.m_z - m_z;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0) + std::pow(dz, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 *
 *  @param[in]  arr
 *
 *  @return
 */
double position3D::distance_to(std::array<double, 3> &arr) const {
    double dx = arr[0] - m_2d[0];
    double dy = arr[1] - m_2d[1];
    double dz = arr[2] - m_z;

    double sum = std::pow(dx, 2.0) + std::pow(dy, 2.0) + std::pow(dz, 2.0);
    return std::sqrt(sum);
}

/**
 *  @brief
 */
void position3D::reset() {
    m_2d[0] = m_2d[1] = m_z = 0.0;
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position3D &position3D::operator=(const position3D &p) {
    m_2d[0] = p.m_2d[0];
    m_2d[1] = p.m_2d[1];
    m_z = p.m_2d[2];

    return *this;
}

/**
 *  @brief
 *
 *  @param[in] index
 *
 *  @return
 */
double &position3D::operator[](int index) const {
    return m_2d[index];
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
bool position3D::operator==(const position3D &p) const {
    bool xeql = gcs::double_approx_eq(m_2d[0], p.m_2d[0]);
    bool yeql = gcs::double_approx_eq(m_2d[1], p.m_2d[1]);
    bool zeql = gcs::double_approx_eq(m_z, p.m_z);

    return xeql && yeql && zeql;
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
bool position3D::operator!=(const position3D &p) const {
    return !(*this == p);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position3D position3D::operator+(const position3D &p) const {
    double x = m_2d[0] + p.m_2d[0];
    double y = m_2d[1] + p.m_2d[1];
    double z = m_z + p.m_z;

    return position3D(x, y, z);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position3D position3D::operator-(const position3D &p) const {
    double x = m_2d[0] - p.m_2d[0];
    double y = m_2d[1] - p.m_2d[1];
    double z = m_z - p.m_z;

    return position3D(x, y, z);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position3D position3D::operator*(const position3D &p) const {
    double x =
        (m_2d[0] * p.m_2d[0]) + (m_2d[0] * p.m_2d[1]) + (m_2d[0] * p.m_z);
    double y =
        (m_2d[1] * p.m_2d[0]) + (m_2d[1] * p.m_2d[1]) + (m_2d[1] * p.m_z);
    double z = (m_z * p.m_2d[0]) + (m_z * p.m_2d[1]) + (m_z * p.m_z);

    return position3D(x, y, z);
}

/**
 *  @brief
 *
 *  @param[in]  p
 *
 *  @return
 */
position3D position3D::operator/(const position3D &p) const {
    double x =
        (m_2d[0] / p.m_2d[0]) + (m_2d[0] / p.m_2d[1]) + (m_2d[0] / p.m_z);
    double y =
        (m_2d[1] / p.m_2d[0]) + (m_2d[1] / p.m_2d[1]) + (m_2d[1] / p.m_z);
    double z = (m_z / p.m_2d[0]) + (m_z / p.m_2d[1]) + (m_z / p.m_z);

    return position3D(x, y, z);
}

/**
 *  @brief
 *
 *  @param[out] os
 *  @param[in]  p
 *
 *  @return
 */
std::ostream &gcs::operator<<(std::ostream &os, const position3D &p) {
    os << "(" << p.m_2d.x() << ", " << p.m_2d.y() << ", " << p.m_z << ")";
    return os;
}
