/*
 *  @file       header.h
 *  @brief      Header file
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

#ifndef HEADER_HPP
#define HEADER_HPP

// clean up unused includes later
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono>

#include "position.hpp"

/*
namespace gcs {
template <typename edge_type> class edge;
template <typename edge_type> std::ostream& operator<<(std::ostream& os, const gcs::edge<edge_type>& e);
}

template <typename edge_type>
class gcs::edge {
public:
    edge();
    edge(int parent_id, int child_id);
    edge(int parent_id, int child_id, edge_type& val);
    edge(const edge& e);
    ~edge();

    edge_type value() const;

    int parent_id() const;
    int child_id() const;

    double weight() const;
    
    void set_value(const edge_type& val);

    void set_parent_id(int parent_id);
    void set_child_id(int child_id);

    void set_weight(double weight);

private:
    edge_type m_val;

    int m_parent_id;
    int m_child_id;

    double m_weight;
};

#include "edge_impl.hpp"

namespace gcs {
template <typename node_type> class node;
template <typename node_type> std::ostream& operator<<(std::ostream& os, const gcs::node<node_type>& n);
}

template <typename node_type, typename edge_type>
class gcs::node {
public:
    using EdgeVector = std::vector<edge<edge_type>>;

    node();
    node(node_type& val, position& pos);
    node(node_type& val, int id, position& pos);
    node(node_type& val);
    node(position& pos);
    node(const node& n);
    ~node();

    node_type value() const;
    EdgeVector edges();
    int id() const;
    position pos();

    void set_value(const node_type& val);
    bool set_id(int id);
    bool set_position(const position& pos);

    bool connect_to(const node& n, bool directed = false);
    bool connect_to(const node& n, edge_type& edge_val, bool directed = false);
private:
    node_type m_val;
    EdgeVector m_edges;

    int m_id;
    position m_pos;
};

Node n1("this node", 0, position(1, 2, 3));
Node n2("that node", 1, position(4, 5, 6)));

// an edge object is created, it's parent id is n1
// it's child id is n2.
// since this edge is directed, only n1 gets
// the edge object pushed to its EdgeVector,
// but n2 will not get this edge object.

// so if we have access to n1,
// we get to n2 by seeing n1's EdgeVector.
// we see that n1 connects to n2
// via parent and child fields, so we get the child id
// and use that to find n2, via a node lookup by id.`n1.connect_to(n2, "EDGE DATA", true);



namespace gcs {

}
// Node is node<node_type>
template <typename node_type>
struct node {
    node_type m_val;
    int m_id;
    position m_pos;
};

// Edge is edge<edge_type>
template <typename node_type, typename edge_type>
struct edge {
    node<node_type>* m_parent;
    node<node_type>* m_child;

    edge_type m_val;
    double m_cost;
};

template <typename node_type, typename edge_type>
struct graph {
    using Node = node<node_type>;
    using Edge = edge<edge_type>;

    using EdgeList = std::vector<Edge>;

    std::map<Node, EdgeList> G;
};

g.add_edge("Node U", "Node V", "Edge UV", edge_cost);
g.add_edge(node_u, node_v, edge_val, edge_cost);
*/
#endif /* HEADER_HPP */
