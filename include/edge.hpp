/*!
    \file       edge.hpp
    \brief      Header file for an edge ADT

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

#ifndef EDGE_HPP
#define EDGE_HPP

#include "gcs_utils.hpp"

namespace gcs {
struct edge_val_selector {
    OSTREAM_SELECTOR_BLANK(edge_val_selector);
};

template <size_t N, typename F>
class point;

template <size_t N, typename F>
class vec;

/*!
   default argument:
       edge_val = edge_val_selector
       if no type is supplied for edge_val, it will be assigned to edge_val_selector,
       which is just an empty struct.
       Any member functions using the edge_val type effectively become unusable.
       This will allow for situations for when a edge value type isn't needed by the user.
       (They may only want to store just the child node and the edge weight..)
*/
template <size_t N, typename edge_val = edge_val_selector, typename F = double>
class edge;
}

template <size_t N, typename edge_val, typename F>
class gcs::edge {
public:
    using point = gcs::point<N, F>;
    
    edge()
    : m_child(nullptr), m_val(), m_weight(), m_id(edge_id_counter++) {
        
    }
    
    edge(point *parent, point *child)
    : m_child(child), m_val(), m_weight(parent->distance(*m_child)), m_id(edge_id_counter++) {
        // in the future, for weight values other than distance --
        // have some logic usingthe parent and child to determine weight
        // in a different fashion.
    }
    
    edge(point *parent, point *child, const F weight)
    : m_child(child), m_weight(weight), m_id(edge_id_counter++) {
        
    }

    edge(point *parent, point *child, const edge_val &val)
    : m_child(child), m_val(val), m_weight(parent->distance(*m_child)), m_id(edge_id_counter++) {
        
    }
    
    edge(point *parent, point *child, const F weight, const edge_val &val)
    : m_child(child), m_val(val), m_weight(weight), m_id(edge_id_counter++) {
        
    }
    
    ~edge() {
        
    }
    
    size_t id() const {
        return m_id;
    }
    
    edge_val val() const {
        return m_val;
    }
    
    F weight() const {
        return m_weight;
    }
        
    point *child() const {
        return m_child;
    }
    
    void set_val(const edge_val &val) {
        m_val = val;
    }
    
    void set_val(const edge_val &&val) {
        m_val = val;
    }
        
    void set_child(point *child) {
        m_child = child;
    }
    
    void set_weight(const F weight) {
        m_weight = weight;
    }

    void set(point *child, const F weight) {
        m_child = child;
        m_weight = weight;
    }
    
    void set(const edge_val &val, point *child, const F weight) {
        m_val = val;
        m_child = child;
        m_weight = weight;
    }

    edge& operator=(const edge_val &val) {
        m_val = val;
        return *this;
    }
    
    edge& operator=(const edge_val &&val) {
        m_val = val;
        return *this;
    }
    
    edge& operator=(const edge &e) {
        m_val = e.val;
        m_child = e.child;
        m_weight = e.weight;
        return *this;
    }
    
    edge& operator=(const edge &&e) {
        m_val = e.m_val;
        m_child = e.m_child;
        m_weight = e.m_weight;
        
        return *this;
    }
    
    friend std::ostream &operator<<(std::ostream &os, const edge &e) {
        os << "Edge ID " << e.m_id << " -> weight (" << e.m_weight
        << ") with value (" << e.m_val << ") and child node " << *e.m_child;
        return os;
    }
    
    static inline size_t edge_id_counter = 0;
    
private:
    point *m_child;     ///< Address of a node, stored as address of base class point.
                        ///< Stored as (point *) so this template won't have to depend on
                        ///< the node_val template parameter for gcs::node.
    
    edge_val m_val;     ///< Value type field for an edge
    
    F m_weight;         ///< Weight of edge, based on distance between parent and child
    size_t m_id;        ///< Edge identifier. Assigned upon instantiation and should not be changed.
};


#endif /* EDGE_HPP */
