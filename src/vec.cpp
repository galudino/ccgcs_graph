/**
 *  @file       vec.cpp
 *  @brief      Source file for a vector (trajectory) ADT
 *
 *  @author     Gemuele Aludino
 *  @date       12 Jul 2020
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

#include <memory>

#include "header.hpp"
#include "vec.hpp"

using gcs::point2D;
using gcs::vec2D;

/**
 *   @brief
 */
vec2D::vec2D() : m_a{}, m_b{} {
}

/**
 *  @brief
 *  @param[in]  b
 */
vec2D::vec2D(const point2D &b) : m_a{}, m_b{b} {
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
vec2D::vec2D(const point2D &a, const point2D &b) : m_a{a}, m_b{b} {
}

/**
 *  @brief
 *  @param[in]  arr_b
 */
vec2D::vec2D(std::array<double, 2> &arr_b) : m_a{}, m_b{arr_b} {
}

/**
 *  @brief
 *
 *  @param[in]  arr_a
 *  @param[in]  arr_b
 */
vec2D::vec2D(std::array<double, 2> &arr_a, std::array<double, 2> &arr_b)
    : m_a{arr_a}, m_b{arr_b} {
}

/**
 *  @brief
 *
 *  @param[in]  b_x
 *  @param[in]  b_y
 */
vec2D::vec2D(double b_x, double b_y) : m_a{}, m_b{b_x, b_y} {
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 *  @param[in]  b_x
 *  @param[in]  b_y
 */
vec2D::vec2D(double a_x, double a_y, double b_x, double b_y)
    : m_a{a_x, a_y}, m_b{b_x, b_y} {
}

/**
 *  @brief
 *
 *  @param[in]  v
 */
vec2D::vec2D(const vec2D &v) : m_a{v.m_a}, m_b{v.m_b} {
}

/**
 *  @brief
 */
vec2D::~vec2D() {
}

/**
 *  @brief
 *
 *  @return
 */
point2D vec2D::a() const {
    return m_a;
}

/**
 *  @brief
 *
 *  @return
 */
point2D vec2D::b() const {
    return m_b;
}

/**
 *  @brief
 *
 *  @return
 */
std::array<point2D, 2> vec2D::get() const {
    return std::array<point2D, 2>{m_a, m_b};
}

/**
 *  @brief
 *
 *  @param[in] a
 */
void vec2D::set_a(const point2D &a) {
    m_a = a;
}

/**
 *  @brief
 *
 *  @param[in] b
 */
void vec2D::set_b(const point2D &b) {
    m_b = b;
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 */
void vec2D::set_a(double a_x, double a_y) {
    m_a = point2D{a_x, a_y};
}

/**
 *  @brief
 *
 *  @param[in]  b_x
 *  @param[in]  b_y
 */
void vec2D::set_b(double b_x, double b_y) {
    m_b = point2D{b_x, b_y};
}

/**
 *  @brief
 *
 *  @param[in]  a
 */
void vec2D::set_a(std::array<double, 2> &a) {
    m_a = point2D{a};
}

/**
 *  @brief
 *
 *  @param[in]  b
 */
void vec2D::set_b(std::array<double, 2> &b) {
    m_a = point2D{b};
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
void vec2D::set(const point2D &a, const point2D &b) {
    m_a = point2D{a};
    m_b = point2D{b};
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 *  @param[in]  b_x
 *  @param[in]  b_y
 */
void vec2D::set(double a_x, double a_y, double b_x, double b_y) {
    m_a = point2D{a_x, a_y};
    m_b = point2D{b_x, b_y};
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
void vec2D::set(std::array<double, 2> &a, std::array<double, 2> &b) {
    m_a = point2D{a};
    m_b = point2D{b};
}

/**
 *  @brief
 */
void vec2D::reset() {
    m_b = m_a;
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec2D &vec2D::operator=(const vec2D &v) {
    m_a = point2D{v.m_a};
    m_b = point2D{v.m_b};

    return *this;
}

/**
 *  @brief
 *
 *  @param[in]  index
 *
 *  @return
 */
point2D &vec2D::operator[](int index) {
    switch (index) {
    case 0:
        return m_a;
        break;
    case 1:
        return m_b;
        break;
    default:
        // TODO: write a real exception class for this
        throw std::exception();
        break;
    }
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
bool vec2D::operator==(const vec2D &v) {
    return m_a == v.m_a && m_b == v.m_b;
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
bool vec2D::operator!=(const vec2D &v) {
    return !(*(this) == v);
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec2D vec2D::operator+(const vec2D &v) {
    return vec2D{dx() + v.dx(), dy() + v.dy()};
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec2D vec2D::operator-(const vec2D &v) {
    return vec2D{dx() - v.dx(), dy() - v.dy()};
}

/**
 *  @brief
 *
 *  @param[out] os
 *  @param[in]  v
 *
 *  @return
 */
std::ostream &gcs::operator<<(std::ostream &os, const vec2D &v) {
    os << "------------------------------------------------" << std::endl
       << "address        \t(" << &v << ")\t\tvec2D" << std::endl
       << "------------------------------------------------" << std::endl
       << "start point (a)\t" << v.m_a << std::endl
       << "end point   (b)\t" << v.m_b << std::endl
       << "magnitude      \t" << v.magnitude() << std::endl
       << "x-component    \t" << v.dx() << std::endl
       << "y-component    \t" << v.dy() << std::endl
       << "angle x-axis   \t" << v.angle_x() << "˚" << std::endl
       << "angle y-axis   \t" << v.angle_y() << "˚" << std::endl
       << "================================================" << std::endl;
    return os;
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::magnitude() const {
    return point2D::distance(m_a, m_b);
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::angle() const {
    return gcs::to_degrees(std::atan(dy() / dx()));
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
double vec2D::angle(const vec2D &v) const {
    double adjacent = dot_product(*this, v);
    double hypotenuse = magnitude() * v.magnitude();

    return gcs::to_degrees(std::acos(adjacent / hypotenuse));
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::angle_x() const {
    return gcs::to_degrees(std::acos(dx() / magnitude()));
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::angle_y() const {
    return gcs::to_degrees(std::acos(dy() / magnitude()));
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::dx() const {
    return m_b.x() - m_a.x();
}

/**
 *  @brief
 *
 *  @return
 */
double vec2D::dy() const {
    return m_b.y() - m_a.y();
}

/**
 *  @brief
 *
 *  @return
 */
std::array<double, 2> vec2D::components() const {
    return std::array<double, 2>{dx(), dy()};
}

/**
 *  @brief
 *
 *  @param[in]  u
 *  @param[in]  v
 *
 *  @return
 */
double vec2D::dot_product(const vec2D &u, const vec2D &v) {
    return gcs::dot_product<2>(u.components().data(), v.components().data());
}

using gcs::point3D;
using gcs::vec3D;

/**
 *   @brief
 */
vec3D::vec3D() : m_a{}, m_b{} {
}

/**
 *  @brief
 *
 *  @param[in]  b
 */
vec3D::vec3D(const point3D &b) : m_a{}, m_b{b} {
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
vec3D::vec3D(const point3D &a, const point3D &b) : m_a{a}, m_b{b} {
}

/**
 *  @brief
 *  @param[in]  arr_b
 */
vec3D::vec3D(std::array<double, 3> &arr_b) : m_a{}, m_b{arr_b} {
}

/**
 *  @brief
 *
 *  @param[in]  arr_a
 *  @param[in]  arr_b
 */
vec3D::vec3D(std::array<double, 3> &arr_a, std::array<double, 3> &arr_b)
    : m_a{arr_a}, m_b{arr_b} {
}

/**
 *  @brief
 *
 *  @param[in]  b_x
 *  @param[in]  b_y
 *  @param[in]  b_z
 */
vec3D::vec3D(double b_x, double b_y, double b_z) : m_a{}, m_b{b_x, b_y, b_z} {
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 *  @param[in]  a_z
 *  @param[in]  b_x
 *  @param[in]  b_y
 *  @param[in]  b_z
 */
vec3D::vec3D(double a_x, double a_y, double a_z, double b_x, double b_y,
             double b_z)
    : m_a{a_x, a_y, a_z}, m_b{b_x, b_y, b_z} {
}

/**
 *  @brief
 *
 *  @param[in]  v
 */
vec3D::vec3D(const vec3D &v) : m_a{v.m_a}, m_b{v.m_b} {
}

/**
 *  @brief
 */
vec3D::~vec3D() {
}

/**
 *  @brief
 *
 *  @return
 */
point3D vec3D::a() const {
    return m_a;
}

/**
 *  @brief
 *
 *  @return
 */
point3D vec3D::b() const {
    return m_b;
}

/**
 *  @brief
 *
 *  @return
 */
std::array<point3D, 2> vec3D::get() const {
    return std::array<point3D, 2>{m_a, m_b};
}

/**
 *  @brief
 *
 *  @param[in] a
 */
void vec3D::set_a(const point3D &a) {
    m_a = a;
}

/**
 *  @brief
 *
 *  @param[in] b
 */
void vec3D::set_b(const point3D &b) {
    m_b = b;
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 *  @param[in]  a_z
 */
void vec3D::set_a(double a_x, double a_y, double a_z) {
    m_a = point3D{a_x, a_y, a_z};
}

/**
 *  @brief
 *
 *  @param[in]  b_x
 *  @param[in]  b_y
 *  @param[in]  b_z
 */
void vec3D::set_b(double b_x, double b_y, double b_z) {
    m_b = point3D{b_x, b_y, b_z};
}

/**
 *  @brief
 *
 *  @param[in]  a
 */
void vec3D::set_a(std::array<double, 3> &a) {
    m_a = point3D{a};
}

/**
 *  @brief
 *
 *  @param[in]  b
 */
void vec3D::set_b(std::array<double, 3> &b) {
    m_b = point3D{b};
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
void vec3D::set(const point3D &a, const point3D &b) {
    m_a = a;
    m_b = b;
}

/**
 *  @brief
 *
 *  @param[in]  a_x
 *  @param[in]  a_y
 *  @param[in]  a_z
 *  @param[in]  b_x
 *  @param[in]  b_y
 *  @param[in]  b_z
 */
void vec3D::set(double a_x, double a_y, double a_z, double b_x, double b_y,
                double b_z) {
    m_a = point3D{a_x, a_y, a_z};
    m_b = point3D{b_x, b_y, b_z};
}

/**
 *  @brief
 *
 *  @param[in]  a
 *  @param[in]  b
 */
void vec3D::set(std::array<double, 3> &a, std::array<double, 3> &b) {
    m_a = point3D{a};
    m_b = point3D{b};
}

/**
 *  @brief
 */
void vec3D::reset() {
    m_b = m_a;
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec3D &vec3D::operator=(const vec3D &v) {
    m_a = point3D{v.m_a};
    m_b = point3D{v.m_b};

    return *this;
}

/**
 *  @brief
 *
 *  @param[in]  index
 *
 *  @return
 */
point3D &vec3D::operator[](int index) {
    switch (index) {
    case 0:
        return m_a;
        break;
    case 1:
        return m_b;
        break;
    default:
        // TODO: write a real exception class for this
        throw std::exception();
        break;
    }
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
bool vec3D::operator==(const vec3D &v) {
    return m_a == v.m_a && m_b == v.m_b;
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
bool vec3D::operator!=(const vec3D &v) {
    return !(*(this) == v);
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec3D vec3D::operator+(const vec3D &v) {
    return vec3D{dx() + v.dx(), dy() + v.dy(), dz() + v.dz()};
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
vec3D vec3D::operator-(const vec3D &v) {
    return vec3D{dx() - v.dx(), dy() - v.dy(), dz() - v.dz()};
}

/**
 *  @brief
 *
 *  @param[out] os
 *  @param[in]  v
 *
 *  @return
 */
std::ostream &gcs::operator<<(std::ostream &os, const vec3D &v) {
    os << "------------------------------------------------" << std::endl
       << "address        \t(" << &v << ")\t\tvec3D" << std::endl
       << "------------------------------------------------" << std::endl
       << "start point (a)\t" << v.m_a << std::endl
       << "end point   (b)\t" << v.m_b << std::endl
       << "magnitude      \t" << v.magnitude() << std::endl
       << "x-component    \t" << v.dx() << std::endl
       << "y-component    \t" << v.dy() << std::endl
       << "z-component    \t" << v.dz() << std::endl
       << "angle x-axis   \t" << v.angle_x() << "˚" << std::endl
       << "angle y-axis   \t" << v.angle_y() << "˚" << std::endl
       << "angle z-axis   \t" << v.angle_z() << "˚" << std::endl
       << "================================================" << std::endl;

    return os;
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::magnitude() const {
    return point3D::distance(m_a, m_b);
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::angle() const {
    return gcs::to_degrees(std::atan(dy() / dx()));
}

/**
 *  @brief
 *
 *  @param[in]  v
 *
 *  @return
 */
double vec3D::angle(vec3D &v) const {
    double adjacent = dot_product(*this, v);
    double hypotenuse = magnitude() * v.magnitude();

    return gcs::to_degrees(std::acos(adjacent / hypotenuse));
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::angle_x() const {
    return gcs::to_degrees(std::acos(dx() / magnitude()));
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::angle_y() const {
    return gcs::to_degrees(std::acos(dy() / magnitude()));
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::angle_z() const {
    return gcs::to_degrees(std::acos(dz() / magnitude()));
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::dx() const {
    return m_b.x() - m_a.x();
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::dy() const {
    return m_b.y() - m_a.y();
}

/**
 *  @brief
 *
 *  @return
 */
double vec3D::dz() const {
    return m_b.z() - m_a.z();
}

/**
 *  @brief
 *
 *  @return
 */
std::array<double, 3> vec3D::components() const {
    return std::array<double, 3>{dx(), dy(), dz()};
}

/**
 *  @brief
 *
 *  @param[in]  u
 *  @param[in]  v
 *
 *  @return
 */
double vec3D::dot_product(const vec3D &u, const vec3D &v) {
    return gcs::dot_product<3>(u.components().data(), v.components().data());
}

/**
 *  @brief
 *
 *  @param[in]  u
 *  @param[in]  v
 *
 *  @return
 */
vec3D vec3D::cross_product(const vec3D &u, const vec3D &v) {
    auto a = u.components();
    auto b = v.components();

    double x = (a[1] * b[2]) - (a[2] * b[1]);
    double y = (a[2] * b[0]) - (a[0] * b[2]);
    double z = (a[0] * b[1]) - (a[1] * b[0]);

    return vec3D{x, y, z};
}
