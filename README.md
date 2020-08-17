gcs_graph
--------------------------------------------------------------------------------
<h2>A graph ADT, written in C++</h2>

The goal of this repository is to further my understanding of graphs,<br>
and to practice C++ in general.<br>
(in particular, using <b>templates</b> and <b>smart pointers</b>)

The following abstractions are planned:<br><br>
<code>point</code>
- <code>class gcs::point</code> takes two <code>template</code> parameters: <code>size_t N</code> and <code>typename F</code>.
- <code>size_t N</code> is the <b>dimension size</b>, i.e. <code>N = 2</code> is <b>2D space</b>.
- <code>typename F</code> is the <b>floating-point</b> precision; <code>double</code> is the default.
- Will be used to store the position of a <code>node</code>.

<code>vec</code>
- <code> class gcs::vec</code> takes two <code>template</code> parameters: <code>size_t N</code> and <code>typename F</code>.
- <code>size_t N</code> is the <b>dimension size</b>, i.e. <code>N = 2</code> is <b>2D space</b>.
- <code>typename F</code> is the <b>floating-point</b> precision; <code>double</code> is the default.
- Will be used to determine the trajectory of <code>edges</code>.

<code>edge<edge_type></code>
- stores a weight/cost (a floating point value) 
- stores an <code>edge_type</code>, a type parameter defined by the user
- stores a <code>parent_id</code> (ID of node u) and <code>child_id</code> (ID of node v)

<code>node<node_type, edge_type></code>
- stores a <code>position</code>
- stores a <code>node_type</code>, a type parameter defined by the user
- stores a container of <code>edge<edge_type></code>
- stores an id

<code>graph<node_type, edge_type></code>
- will store nodes as a dictionary of <code>[id : node]</code>
- subject to change, as I learn more

<b>What I want the most for this graph: parameterized types</b>
- <code>edge</code> and <code>node</code> can store their own data types
- <code>graph</code>, by extension, has an <code>edge_type</code> and <code>node_type</code>
- Depth-first search
- Dijkstra's Shortest Path Algorithm

I do not plan to use any outside libraries --<br>
I will only use the C++ Standard Library<br>
and the C++ Standard Template Library.

<h2>How to use</h2>
At this time, this guide/source code is being written/tested on macOS 10.15.5.<br><br>

I cannot guarantee compatibility with other platforms,<br>
but since I am only using the C++ Standard Library and the C++ STL,<br>

I do not anticipate any issues with other platforms, like Windows or the various flavors of Linux.<br>

A <code>CMakeLists.txt</code> file is provided for use with the <b>CMake</b> build system.<br>

You can use <b>CMake</b> to produce Microsoft Visual Studio <code>.sln</code> files,<br>or Unix <code>Makefiles</code> for macOS or Linux.

<h3>Creating a .tar.gz archive (tarball)</h3>
You can make an archive (tarball) of your local copy of this repository<br>
by typing <code>./maketarball your_chosen_name.tar.gz</code>,<br> 
where 'your_chosen_name' is...a name of your choice.<br><br>

Don't forget the <code>.tar.gz</code> extension.

Example:<br>
<code>./maketarball gcs_graph.tar.gz</code>

<h2> Current state </h2>
- <code>gcs::point</code> (<b>point abstraction</b>) and <code>gcs::vec</code> (<b>vector abstraction</b>) completed.<br>
- <code>point.hpp</code>, <code>vec.hpp</code>, <code>vec_impl.hpp</code>, and <code>gcs_utils.hpp</code> may be taken out of this codebase and used for other projects. It's possible that <b><code>gcs_graph</code></b> may just be one of many modules I write for the entire <code><b>gcs</b></code> library.<br>

<h3> Still TODO: </h3>
- <code>node.hpp</code>, <code>edge.hpp</code>, <code>graph.hpp</code>, possibly another abstraction for paths<br>
- Exhaustive unit tests<br>
- Test on macOS, Windows 10, and Linux (Ubuntu)<br>
