using gcs::edge;

template <typename edge_type>
edge<edge_type>::edge() : m_val(edge_type()),  m_parent_id(-999), m_child_id(-999) {

}

template <typename edge_type>
edge<edge_type>::edge(int parent_id, int child_id) : m_val(edge_type()), m_parent_id(parent_id), m_child_id(child_id) {

}

template <typename edge_type>
edge<edge_type>::edge(int parent_id, int child_id, edge_type val) : m_val(val), m_parent_id(parent_id), m_child_id(child_id) {

}

template <typename edge_type>
edge<edge_type>::edge(const edge& e) : m_val(e.m_val), m_parent_id(e.m_parent_id), m_child_id(e.m_child_id) {

}

template <typename edge_type>
edge<edge_type>::~edge() {

}

template <typename edge_type>
int edge<edge_type>::parent_id() const {
    return m_parent_id;
}

template <typename edge_type>
int edge<edge_type>::child_id() const {
    return m_child_id;
}

template <typename edge_type>
edge_type edge<edge_type>::value() const {
    return m_val;
}

template <typename edge_type>
void edge<edge_type>::set_parent_id(int parent_id) {
    m_parent_id = parent_id;
}

template <typename edge_type>
void edge<edge_type>::set_child_id(int child_id) {
    m_child_id = child_id;
}

template <typename edge_type>
void edge<edge_type>::set_value(const edge_type& val) {
    m_val = val;
}

template <typename edge_type>
std::ostream& gcs::operator<<(std::ostream& os, const gcs::edge<edge_type>& e) {
    os << "(" << e.parent_id() << ")->(" << e.child_id() << ")" << "\t" << e.value();
    return os;
}

