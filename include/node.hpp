/*!
    \file       node.hpp
    \brief      Header file for a node ADT

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

#ifndef NODE_HPP
#define NODE_HPP

#include "gcs_utils.hpp"

namespace gcs {
struct node_val_selector {
    OSTREAM_SELECTOR_BLANK(node_val_selector);
};

template <size_t N, typename F>
class point;

template <size_t N, typename F>
class vec;

/*!
    default argument:
        node_val = node_val_selector
        if no type is supplied for node_val, it will be assigned to node_val_selector,
        which is just an empty struct.
        Any member functions using the node_val type effectively become unusable.
        This will allow for situations for when a node value type isn't needed by the user.
        (They may only want to store just position data for the node.)
 */
template <size_t N, typename node_val = node_val_selector, typename F = double>
class node;
}

template <size_t N, typename node_val, typename F>
class gcs::node : public gcs::point<N, F> {
public:
    using point = point<N, F>;
    
    node() : point(), m_val(), m_id(node_id_counter++) {
        
    }
    
    node(const point &pos) : point(pos), m_val(), m_id(node_id_counter++) {
        
    }
    
    node(const point &&pos) : point(pos), m_val(), m_id(node_id_counter++) {
        
    }
    
    node(const point &pos, const node_val &val) : point(pos), m_val(val), m_id(node_id_counter++) {
        
    }
  
    node(const point &&pos, const node_val &&val) : point(pos), m_val(val), m_id(node_id_counter++) {
        
    }
    
    ~node() {

    }
    
    int id() const {
        return m_id;
    }
        
    node_val val() const {
        return m_val;
    }
    
    void set_val(const node_val &val) {
        m_val = val;
    }
    
    void set_val(const node_val &&val) {
        m_val = val;
    }
    
    node& operator=(const std::initializer_list<F> &coords) {
        this->set(coords);
        return *this;
    }
    
    node& operator=(const point &pos) {
        this->set(pos);
        return *this;
    }
    
    node& operator=(const point &&pos) {
        this->set(pos);
        return *this;
    }
    
    node& operator=(const node_val &val) {
        m_val = val;
        return *this;
    }
    
    node& operator=(const node_val &&val) {
        m_val = val;
        return *this;
    }
    
    node &operator=(const node &n) {
        this->set(n.m_coords);
        m_val = n.m_val;
        return *this;
    }
    
    node &operator=(const node &&n) {
        this->set(n.m_coords);
        m_val = n.m_val;
        return *this;
    }
    
    F &operator[](const int index) {
        return this->m_coords[index];
    }
    
    bool operator==(const node &n) {
        return this->m_coords == n.m_coords && m_val == n.m_val;
    }
    
    bool operator==(const node &n) const {
        return this->m_coords == n.m_coords && m_val == n.m_val;
    }
    
    bool operator!=(const node &n) {
        return !(*(this) == n);
    }
    
    bool operator!=(const node &n) const {
        return !(*(this) == n);
    }
    
    friend std::ostream &operator<<(std::ostream &os, const node &n) {
        auto point_tmp = reinterpret_cast<point *>(const_cast<node *>(&n));
        os << "Node ID " << n.m_id << " -> point " << *point_tmp
        << " with value (" << n.m_val << ")";
        
        return os;
    }
    
    static inline int node_id_counter = 0;
    
private:
    node_val m_val;     ///< Value type field for a node
    int m_id;           ///< Node identifier. Assigned upon instantiation and should not be changed.
};

#endif /* NODE_HPP */
