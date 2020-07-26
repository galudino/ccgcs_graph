/**
 *  @file       point.hpp
 *  @brief      Header file for a point ADT
 *
 *  @author     Gemuele Aludino
 *  @date       20 Jun 2020
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

#ifndef POINT_HPP
#define POINT_HPP

#include <algorithm>
#include <array>
#include <iostream>

#include "header.hpp"

namespace gcs {
class point2D;
class point3D;

template <size_t dimension, typename floating_precision = double>
class point;

template <size_t dimension, typename floating_precision = double>
std::ostream &operator<<(std::ostream &os,
                         const gcs::point<dimension, floating_precision> &p);

template <typename floating_precision>
class point<2, floating_precision>;

template <typename floating_precision>
std::ostream &operator<<(std::ostream &os,
                         const gcs::point<2, floating_precision> &p);

template <typename floating_precision>
class point<3, floating_precision>;

template <typename floating_precision>
std::ostream &operator<<(std::ostream &os,
                         const gcs::point<3, floating_precision> &p);
} // namespace gcs

/**
 *  @class  gcs::point<dimension, floating_precision>
 *  @brief  A templated abstraction for an n-dimensional Cartesian coordinate
 *
 *  @tparam dimension    An integral value, n, representing the space R^n, i.e.
 * R^2 for 2D or R^3 for 3D
 *  @tparam floating_precision  A floating point type, i.e. float, double, long
 * double
 */
template <size_t dimension, typename floating_precision>
class gcs::point {
public:
    using FloatType = floating_precision;
    using Point = gcs::point<dimension, FloatType>;
    using Coordinates = std::array<FloatType, dimension>;

    point();

    point(Coordinates coords);
    point(Coordinates &coords);

    point(const Point &p);

    ~point();

    Coordinates get() const;

    void set(const Point &p);
    void set(Coordinates coords);
    void set(Coordinates &coords);

    void reset();

    Point &operator=(const Point &p);
    FloatType &operator[](int index);

    bool operator==(const Point &p);
    bool operator!=(const Point &p);
    
    friend std::ostream &operator<<(std::ostream &os, const Point &p);
    
    static FloatType distance(const Point &u, const Point &v);
    static FloatType distance(Coordinates arr_u, Coordinates arr_v);
    static FloatType distance(Coordinates &arr_u, Coordinates &arr_v);

private:
    Coordinates m_coords;
};

/**
 *  @class  gcs::point<2, floating_precision>
 *  @brief  A template specialization of gcs::point<size_t dimension, typename
 * floating_precision> for two-dimensional Cartesian coordinates (R^2)
 *
 *  @tparam floating_precision  A floating point type, i.e. float, double, long
 * double
 */
template <typename floating_precision>
class gcs::point<2, floating_precision> {
public:
    using FloatType = floating_precision;
    using Point = gcs::point<2, FloatType>;
    using Coordinates = std::array<FloatType, 2>;

    point();

    point(Coordinates coords);
    point(Coordinates &coords);

    point(const Point &p);

    ~point();

    FloatType x() const;
    FloatType y() const;

    Coordinates get() const;

    void set_x(FloatType x);
    void set_y(FloatType y);

    void set(const Point &p);
    void set(FloatType x, FloatType y);
    void set(Coordinates coords);
    void set(Coordinates &coords);

    void reset();

    Point &operator=(const Point &p);
    FloatType &operator[](int index);

    bool operator==(const Point &p);
    bool operator!=(const Point &p);

    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    static FloatType distance(FloatType u_x, FloatType u_y, FloatType v_x,
                              FloatType v_y);
    static FloatType distance(const Point &u, const Point &v);
    static FloatType distance(Coordinates arr_u, Coordinates arr_v);
    static FloatType distance(Coordinates &arr_u, Coordinates &arr_v);

private:
    Coordinates m_coords;
};

/**
 *  @class  gcs::point<3,  floating_precision>
 *  @brief  A template specialization of gcs::point<size_t dimension, typename
 * floating_precision> for two-dimensional Cartesian coordinates (R^3)
 *
 *  @tparam floating_precision  A floating point type, i.e. float, double, long
 * double
 */
template <typename floating_precision>
class gcs::point<3, floating_precision> {
public:
    using FloatType = floating_precision;
    using Point = gcs::point<3, FloatType>;
    using Coordinates = std::array<FloatType, 3>;

    point();

    point(Coordinates coords);
    point(Coordinates &coords);

    point(const Point &p);

    ~point();

    FloatType x() const;
    FloatType y() const;
    FloatType z() const;

    Coordinates get() const;

    void set_x(FloatType x);
    void set_y(FloatType y);
    void set_z(FloatType z);

    void set(const Point &p);
    void set(FloatType x, FloatType y, FloatType z);
    void set(Coordinates coords);
    void set(Coordinates &coords);

    void reset();

    Point &operator=(const Point &p);
    FloatType &operator[](int index);

    bool operator==(const Point &p);
    bool operator!=(const Point &p);

    friend std::ostream &operator<<(std::ostream &os, const Point &p);

    static FloatType distance(FloatType u_x, FloatType u_y, FloatType u_z,
                              FloatType v_x, FloatType v_y, FloatType v_z);
    static FloatType distance(const Point &u, const Point &v);
    static FloatType distance(Coordinates arr_u, Coordinates arr_v);
    static FloatType distance(Coordinates &arr_u, Coordinates &arr_v);

private:
    Coordinates m_coords;
};

// For separation of class definition and member function definitions
#include "point_impl.tpp"

///
/// Will be deprecated soon. Use gcs::point<size_t dimension, typename
/// floating_precision> instead.
///

/**
 *  @class      gcs::point2D
 *  @brief      An abstraction for a two-dimensional Cartesian coordinate
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
    double m_x; /**< x-coordinate  */
    double m_y; /**< y-coordinate */
};

/**
 *  @class      gcs::point3D
 *  @brief      An abstraction for a three-dimensional Cartesian coordinate
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
    gcs::point2D m_2d; /**< 2D portion of a 3D point, x and y coordinates */
    double m_z;        /**< z-coordinate */
};

#endif /* POINT_HPP */
