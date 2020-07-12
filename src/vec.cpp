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

vec2D::vec2D() : m_a{}, m_b{} {

}

vec2D::vec2D(const point2D &b) : m_a{}, m_b{b} {

}

vec2D::vec2D(const point2D &a, const point2D &b) : m_a{a}, m_b{b} {
    
}

vec2D::vec2D(std::array<double, 2> &arr_b) : m_a{}, m_b{arr_b} {
    
}

vec2D::vec2D(std::array<double, 2> &arr_a, std::array<double, 2> &arr_b) : m_a{arr_a}, m_b{arr_b} {
    
}

vec2D::vec2D(double b_x, double b_y) : m_a{}, m_b{b_x, b_y} {
    
}

vec2D::vec2D(double a_x, double a_y, double b_x, double b_y) : m_a{a_x, a_y}, m_b{b_x, b_y} {
    
}

vec2D::vec2D(const vec2D &v) : m_a{v.m_a}, m_b{v.m_b} {
    
}

vec2D::~vec2D() {
    
}

point2D vec2D::a() const {
    return m_a;
}

point2D vec2D::b() const {
    return m_b;
}

std::array<point2D, 2> vec2D::get() const {
    return std::array<point2D, 2>{m_a, m_b};
}

void vec2D::set_a(const point2D &a) {
    m_a = a;
}

void vec2D::set_b(const point2D &b) {
    m_b = b;
}

void vec2D::set_a(double a_x, double a_y) {
    m_a = point2D{a_x, a_y};
}

void vec2D::set_b(double b_x, double b_y) {
    m_b = point2D{b_x, b_y};
}

void vec2D::set_a(std::array<double, 2> &a) {
    m_a = point2D{a};
}

void vec2D::set_b(std::array<double, 2> &b) {
    m_a = point2D{b};
}

void vec2D::set(const point2D &a, const point2D &b) {
    m_a = point2D{a};
    m_b = point2D{b};
}

void vec2D::set(double a_x, double a_y, double b_x, double b_y) {
    m_a = point2D{a_x, a_y};
    m_b = point2D{b_x, b_y};
}

void vec2D::set(std::array<double, 2> &a, std::array<double, 2> &b) {
    m_a = point2D{a};
    m_b = point2D{b};
}

void vec2D::reset() {
    m_b = m_a;
}

vec2D &vec2D::operator=(const vec2D &v) {
    m_a = point2D{v.m_a};
    m_b = point2D{v.m_b};
    return *this;
}

point2D &vec2D::operator[](int index){
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

bool vec2D::operator==(const vec2D &v) {
    return m_a == v.m_a && m_b == v.m_b;
}

bool vec2D::operator!=(const vec2D &v) {
    return !(*(this) == v);
}

vec2D vec2D::operator+(const vec2D &v) {
    return vec2D{dx() + v.dx(), dy() + v.dy()};
}

vec2D vec2D::operator-(const vec2D &v) {
    return vec2D{dx() - v.dx(), dy() - v.dy()};
}

std::ostream &gcs::operator<<(std::ostream &os, const vec2D &v) {
    os << "a = " << v.m_a << "\t" << "b = " << v.m_b << std::endl
       << "magnitude = " << v.magnitude() << std::endl
    << "angle = " << v.angle() << "˚";
    
    return os;
}

double vec2D::magnitude() const {
    return point2D::distance(m_a, m_b);
}

double vec2D::angle() const {
    return gcs::to_degrees(std::atan(dy() / dx()));
}

double vec2D::angle_x() const {
    return angle(vec2D{dx(), 0.0});
}

double vec2D::angle_y() const {
    return angle(vec2D{0.0, dy()});
}

double vec2D::angle(const vec2D &v) const {
    double adjacent = dot_product(*this, v);
    double hypotenuse = magnitude() * v.magnitude();

    return gcs::to_degrees(std::acos(adjacent / hypotenuse));
}

double vec2D::dx() const {
    return std::abs(m_b.x() - m_a.x());
}

double vec2D::dy() const {
    return std::abs(m_b.y() - m_a.y());
}

std::array<double, 2> vec2D::components() const {
    return std::array<double, 2>{dx(), dy()};
}

double vec2D::dot_product(const vec2D &u, const vec2D &v) {
    double A = u.dx() * v.dx();
    double B = u.dy() * v.dy();
    return A + B;
}
