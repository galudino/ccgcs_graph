/**
 *  @file       position.hpp
 *  @brief      Header file for a position ADT
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

#ifndef POSITION_HPP
#define POSITION_HPP

#include <ostream>
#include <array>

namespace gcs {
struct position2D;
struct position3D;
const double epsilon = 0.0001f;
bool double_approx_eq(double a, double b);
}

/**
 *  @struct     gcs::position2D
 *  @brief      An abstraction for a two-dimensional Cartesian coordinate
 */
struct gcs::position2D {
public:
    position2D();
    position2D(double x, double y);
    position2D(const position2D& p);
    ~position2D();

    double x() const;
    double y() const;

    std::array<double, 2> get() const;

    void set_x(double x);
    void set_y(double y);

    void set(double x, double y);
    void set(std::array<double, 2> arr);

    double distance(position2D& p) const;
    void reset();

    double& operator[](int index) const;

    bool operator==(const position2D& p) const;

    position2D operator+(const position2D& p) const;
    position2D operator-(const position2D& p) const;
    position2D operator*(const position2D& p) const;
    position2D operator/(const position2D& p) const;

    friend std::ostream& operator<<(std::ostream& os, const position2D& p);
private:
    double m_x;
    double m_y;
};

/**
 *  @struct     gcs::position3D
 *  @brief      An abstraction for a three-dimensional Cartesian coordinate
 */
struct gcs::position3D {
public:
    position3D();
    position3D(double x, double y, double z);
    position3D(const position3D& p);
    position3D(const position2D& p);
    ~position3D();

    double x() const;
    double y() const;
    double z() const;

    std::array<double, 3> get() const;

    void set_x(double x);
    void set_y(double y);
    void set_z(double z);

    void set(double x, double y, double z);
    void set(std::array<double, 3> arr);

    double distance(position3D& p) const;
    void reset();

    double& operator[](int index) const;

    bool operator==(const position3D& p) const;

    position3D operator+(const position3D& p) const;
    position3D operator-(const position3D& p) const;
    position3D operator*(const position3D& p) const;
    position3D operator/(const position3D& p) const;

    friend std::ostream& operator<<(std::ostream& os, const position3D& p);
private:
    gcs::position2D m_2d;
    double m_z;
};

#endif /* POSITION_HPP */
