gcs_graph
--------------------------------------------------------------------------------
<h2>A graph ADT, written in C++</h2>

The goal of this repository is to further my understanding of graphs,<br>
and to practice C++ in general (in particular, using templates and smart pointers)

I want to have the following abstractions:<br><br>
<code>position</code>
- stores euclidean coordinates x, y, z

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
I will only use the C++ Standard Library and the C++ Standard Template Library.

<h2>How to use</h2>
At this time, this guide/source code is being written/tested on macOS 10.15.5.<br>

I cannot guarantee compatibility with other platforms,<br>
but since I am only using the C++ Standard Library and the C++ STL,<br>
I do not anticipate any issues with other platforms, like Windows or the various flavors of Linux.<br>

Clone the <b>gcs_graph</b> repository onto your machine.<br>
Navigate to the local copy of <b>gcs_graph</b> on your system,<br>
then type <code>make</code>. (a <b>Makefile</b> is provided with the repository)

You have now built the sources for <b>gcs_graph</b>.<br>

Type <code>./main</code> to run the code in <code>client/main.cpp</code>,<br>
or type <code>./test</code> to run the code in <code>tests/test.cpp</code>.

<h2>Creating a .tar.gz archive (tarball)</h2>
You can make an archive (tarball) of your local copy of this repository<br>
by typing <code>./maketarball your_chosen_name.tar.gz</code>,<br> 
where 'your_chosen_name' is...a name of your choice.<br>

Don't forget the <code>.tar.gz</code> extension.

Example:<br>
<code>./maketarball gcs_graph.tar.gz</code>
