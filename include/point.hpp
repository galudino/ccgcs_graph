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

#include <algorithm>
#include <array>
#include <iostream>

#include "header.hpp"

namespace gcs {
class point2D;
class point3D;
} // namespace gcs

/*!
    \class      gcs::point2D
    \brief      An abstraction for a two-dimensional Cartesian coordinate
 */
class gcs::point2D {
public:
    point2D();

    point2D(double x, double y);
    point2D(std::array<double, 2> &arr);

    point2D(const point2D &p);

    ~point2D();

    double x() const;
    double y() const;

    std::array<double, 2> get() const;

    void set_x(double x);
    void set_y(double y);

    void set(double x, double y);
    void set(const point2D &p);
    void set(std::array<double, 2> &arr);

    void reset();

    point2D &operator=(const point2D &p);
    double &operator[](int index) const;

    bool operator==(const point2D &p);
    bool operator!=(const point2D &p);

    friend std::ostream &operator<<(std::ostream &os, const point2D &p);

    static double distance(double u_x, double u_y, double v_x, double v_y);
    static double distance(const point2D &u, const point2D &v);
    static double distance(std::array<double, 2> &arr_u,
                           std::array<double, 2> &arr_v);

private:
    double m_x; ///< x-coordinate
    double m_y; ///< y-coordinate
};

/*!
    \class      gcs::point3D
    \brief      An abstraction for a three-dimensional Cartesian coordinate
 */
class gcs::point3D {
public:
    point3D();

    point3D(double x, double y, double z);
    point3D(std::array<double, 3> &arr);

    point3D(const point3D &p);
    point3D(const point2D &p);

    ~point3D();

    double x() const;
    double y() const;
    double z() const;

    std::array<double, 3> get() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    void set(double x, double y, double z);
    void set(const point3D &p);
    void set(std::array<double, 3> &arr);

    void reset();

    point3D &operator=(const point3D &p);
    double &operator[](int index) const;

    bool operator==(const point3D &p);
    bool operator!=(const point3D &p);

    friend std::ostream &operator<<(std::ostream &os, const point3D &p);

    static double distance(double u_x, double u_y, double u_z, double v_x,
                           double v_y, double v_z);
    static double distance(const point3D &u, const point3D &v);
    static double distance(std::array<double, 3> &arr_u,
                           std::array<double, 3> &arr_v);

private:
    gcs::point2D m_2d; ///< 2D portion of a 3D point, x and y coordinates
    double m_z;        ///< z-coordinate
};

namespace gcs {
class vector2;
}

class gcs::vector2 {
public:
    vector2();
    vector2(double vx, double vy);

    ~vector2();

    double vx() const;
    double vy() const;
    std::array<double, 2> get() const;

    void set_vx(double vx);
    void set_vy(double vy);
    void set(std::array<double, 2> &arr);

    void reset();

    vector2 &operator=(const vector2 &v);
    double &operator[](int component);

    bool operator==(const vector2 &v);
    bool operator!=(const vector2 &v);

    vector2 operator+(const vector2 &v);
    vector2 operator-(const vector2 &v);
    vector2 operator*(const vector2 &v);

    double magnitude() const;
    double angle_x() const;
    double angle_y() const;
    double angle(const vector2 &v) const;

    friend std::ostream &operator<<(std::ostream &os, const vector2 &v);

private:
    double m_vx; ///< x-component of 2D vector
    double m_vy; ///< y-component of 2D vector
};

#endif /* POINT_HPP */
