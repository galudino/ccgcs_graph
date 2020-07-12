/**
 *  @file       vec.hpp
 *  @brief      Header file for a vector (trajectory) ADT
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

#ifndef VEC_HPP
#define VEC_HPP

#include <array>
#include <iostream>

#include "point.hpp"

namespace gcs {
class vec2D;
class vec3D;
} // namespace gcs

class gcs::vec2D {
public:
    vec2D();
    
    vec2D(const point2D &b);
    vec2D(const point2D &a, const point2D &b);
    
    vec2D(std::array<double, 2> &arr_b);
    vec2D(std::array<double, 2> &arr_a, std::array<double, 2> &arr_b);
    
    vec2D(double b_x, double b_y);
    vec2D(double a_x, double a_y, double b_x, double b_y);

    vec2D(const vec2D &v);

    ~vec2D();

    point2D a() const;
    point2D b() const;

    std::array<point2D, 2> get() const;

    void set_a(const point2D &a);
    void set_b(const point2D &b);

    void set_a(double a_x, double a_y);
    void set_b(double b_x, double b_y);

    void set_a(std::array<double, 2> &a);
    void set_b(std::array<double, 2> &b);

    void set(const point2D &a, const point2D &b);
    void set(double a_x, double a_y, double b_x, double b_y);
    void set(std::array<double, 2> &a, std::array<double, 2> &b);

    void reset();

    vec2D &operator=(const vec2D &v);
    point2D &operator[](int index);

    bool operator==(const vec2D &v);
    bool operator!=(const vec2D &v);

    vec2D operator+(const vec2D &v);
    vec2D operator-(const vec2D &v);

    friend std::ostream &operator<<(std::ostream &os, const vec2D &v);

    double magnitude() const;
    double angle() const;
    double angle_x() const;
    double angle_y() const;
    double angle(const vec2D &v) const;

    double dx() const;
    double dy() const;

    std::array<double, 2> components() const;

    static double dot_product(const vec2D &u, const vec2D &v);

private:
    point2D m_a; /**< Starting position of 2D vector */
    point2D m_b; /**< Ending position of 2D vector */
};

class gcs::vec3D {
public:
    vec3D();

    vec3D(const point3D &a, const point3D &b);
    vec3D(std::array<double, 3> &arr_a, std::array<double, 3> &arr_b);
    vec3D(double a_x, double a_y, double a_z, double b_x, double b_y,
          double b_z);

    vec3D(const vec3D &v);

    ~vec3D();

    point3D a() const;
    point3D b() const;

    std::array<point3D, 2> get() const;

    void set_a(const point3D &a);
    void set_b(const point3D &b);

    void set_a(double a_x, double a_y, double a_z);
    void set_b(double b_x, double b_y, double b_z);

    void set_a(std::array<double, 3> &a);
    void set_b(std::array<double, 3> &b);

    void set(const point3D &a, const point3D &b);
    void set(double a_x, double a_y, double a_z, double b_x, double b_y,
             double b_z);
    void set(std::array<double, 3> &a, std::array<double, 3> &b);

    vec3D &operator=(const vec3D &v);
    point3D &operator[](int index);

    bool operator==(const vec3D &v);
    bool operator!=(const vec3D &v);

    vec3D operator+(const vec3D &v);
    vec3D operator-(const vec3D &v);

    friend std::ostream &operator<<(std::ostream &os, const vec3D &v);

    double magnitude() const;
    double angle() const;
    double angle(vec3D &v) const;

    double dx() const;
    double dy() const;
    double dz() const;

    std::array<double, 3> components() const;

    static double dot_product(vec3D &u, vec3D &v);
    static double cross_product(vec3D &u, vec3D &v);

private:
    point3D m_a; /**< Starting position of 3D vector */
    point3D m_b; /**< Ending position of 3D vector */
};

#endif /* VEC_HPP */
