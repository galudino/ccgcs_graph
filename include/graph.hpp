/*!
    \file       graph.hpp
    \brief      Header file for an graph ADT

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

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <unordered_map>

#include "point.hpp"
#include "node.hpp"
#include "edge.hpp"

namespace gcs {
template <size_t N, typename F>
class point;

template <size_t N, typename F>
class vec;

template <size_t N, typename node_val, typename F>
class node;

template <size_t N, typename edge_val, typename F>
class edge;

template <size_t N, typename node_val = node_val_selector, typename edge_val = edge_val_selector, typename F = double>
class graph;
}

template <size_t N, typename node_val, typename edge_val, typename F>
class gcs::graph {
public:
    using point = gcs::point<N, F>;
    using node = gcs::node<N, node_val, F>;
    using edge = gcs::edge<N, edge_val, F>;
    
    using node_list = std::vector<node>;
    using edge_list = std::vector<edge>;
    using all_edge_list = std::vector<edge_list>;
    
    using iterator = typename edge_list::iterator;
    using const_iterator = typename edge_list::const_iterator;
    using const_reverse_iterator = typename edge_list::const_reverse_iterator;
    
    using graph_impl = std::unordered_map<node *, edge_list *>;
    
    graph() : m_impl(), m_nodes(), m_alledgelist() {
        
    }
    
    ~graph() {
        
    }
    
    graph_impl get() const {
        return m_impl;
    }
    
    node_list nodes() const {
        return nodes;
    }
    
    all_edge_list all_edge_lists() const {
        return m_alledgelist;
    }
    
    edge_list edgelist(const int node_id) const {
        return m_alledgelist[node_id];
    }
    
    edge_list edgelist(const node &n) const {
        return adjlist(n.id());
    }
    
private:
    graph_impl m_impl; ///< key: addrs of node from m_nodes, value: addrs of adj_list from m_adjlist
    
    node_list m_nodes;              ///< All instances of node are stored here.
    all_edge_list m_alledgelist;    ///< All instances of edge_list are stored here
    
    // each node has an edge_list - represents all connections for that node.
    // All of the edge_lists are stored in m_alledgelist.
};

/*
    Graph operations:
    -----------
    test adjacency, given two nodes
    get all adjacent nodes, given a node
    add a node
    remove a node
    add an edge
    remove an edge
    get a path traversal given start and end nodes
    get an edgelist (container of "complete" edges)
 
    a "headless" edge contains only the child node, edge value, and weight.
    a "complete" edge has parent and child node, edge value, and weight.
    
    The unordered_map will have buckets of
        nodes : [container of headless edges]
 
    A "complete" edge is a
        std::pair<node, headless edge>.
 
    gcs::edge is a "headless" edge.
 
    iterators:
        -iterate over all nodes in graph
        -iterate from a starting node, to an ending node, via shortest path
    
    Getting node values/setting node values,
    and getting edge values/setting edge values
    should be the responsibilty of gcs::node and gcs::edge respectively.
    gcs::graph will give you a node, gcs::node will have the functionality
    to do the rest. Same with edge.
    -----------------
    // are two nodes (within this graph) adjacent?
    bool graph::is_adjacent(const node& x, const node &y);
    bool graph::is_adjacent(const int x, const int y);
    
    // Retrieve the nodes that form edges with a given node
    vector<node> graph::neighbors(const node &x);
    vector<int> graph::neighbors(const int x);
    
    // Add a node to this graph (no connection/edge)
    void graph::add_node(const node &x);
    void graph::add_node(const int x);
 
    // Remove an existing node from this graph
    void graph::remove_node(const node &x);
    void graph::remove_node(const int x);
    
    // Add an edge to this graph
    void graph::add_edge(const node &x, const node &y);
    void graph::add_edge(const node &x, const node &y, const edge_val &val);
    void graph::add_edge(const int x, const int y);
    void graph::add_edge(const int x, const int y, const edge_val &val);
    void graph::add_edge(const edge &e);
    
    // Remove an edge from this graph (if found)
    void graph::remove_edge(const node &x, const node &y);
    void graph::remove_edge(const node &x, const node &y, const edge_val &val);
    void graph::remove_edge(const int x, const int y);
    void graph::remove_edge(const int x, const int y, const edge_val &val);
    void graph::remove_edge(const edge &e);
 
    // Retrieve the value type for a given node
        // Is this necessary? We have the node, therefore, we have the value...
        // Unless the caller only has access to class point, and not class node?
    node_val graph::get_node_value(const node &x);
    node_val graph::get_node_value(const int x);
    
    // Set the value type for a node
        // We can already do this for the node type,
        // unless we restrict access to the node type and only allow
        // the caller to use class point
    void graph::set_node_value(const node& x, const node_val &val);
    void graph::set_node_value(const int x, const node_val &val);
    
    // Set the value type for an edge
        // We can already do this for the edge type.
    void graph::set_edge_value(const node &x, const node &y, const edge_val &val);
    void graph::set_edge_value(const int x, const int y, const edge_val &val);
    void graph::set_edge_value(const edge &e, const edge_val &val);
    
    // Get the value type for an edge
        // We can already do this for the edge type.
    edge_val graph::get_edge_value(const node &x, const node &y);
    edge_val graph::get_edge_value(const int x, const int y);
    edge_val graph::get_edge_value(const edge &e);
 */

#endif /* GRAPH_HPP */
