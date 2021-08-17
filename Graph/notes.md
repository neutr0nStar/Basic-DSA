# Graph notes

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/undirectedgraph.png" width="300px">

**Graph is a non-linear data structure consisting of nodes and edges**

Mathematically: **G = (V, E)**

### Props
* Tree is a type of graph.
* Nodes are also called vertices.
* No. of vertices: **|V|**
* No. of edges: **|E|**
* Min no of edges: **0**
* Max no of edges:
  * **n(n-1)**: if directed
  * **n(n-1)/2**: if undirected
* A graph with no edges is also valid.
* Directed (aka digraph) or undirected
* Weighted or unweighted
* **Path**: A sequence of vertices where each adjacent pair is connected by an edge.
* **Closed Path(Cycle)**: Starts and ends at same vertex, length > 0.
* **Strongly connected graph**: There exists a path from any vertex to any other vertex. (undirected: *connected*, directed: *strongly connected*)
* Self loop is a edge having only one vertex.
* Parallel paths are 2 edges between 2 nodes.

## Graph representation

### Edge list
We will store vertices and edges in two different lists.

| Vertices |
|---|
| A |
| B |
| C |
|...|

| Edge list |
|----------|
| A, B, 12 |
| B, C, 11 |
| C, A, 20 |



```
    struce Edge{
        // we can use inex of the vertex in vertex list, 
        // or pointer to vertex in vertex list also
        string start_vertex; 
        string end_vertex;
        int weight;
    }
```

Space complexity of this is ok O(v), but time complexity is O(v^2) which is bad. (v = |V|).

Useful for sparse graph. (less edges)

### Adjacency Matrix
Vertex list same as above

**Adjacency matrix**

|       | 0 | 1 | 2 |
|-------|---|---|---|
| **0** | 0 | 1 | 1 |
| **1** | 1 | 0 | 1 |
| **2** | 1 | 1 | 0 |

Here, 0,1,2.. represent indexes in vertex list.
To find index for a vertice quickly, we can use a hash table.

Here, 0 and 1 in the matrix represent false and true respectively. 
For a weighted graph, we can store the weight instead of 0 and one, for no adjacency, we will sore _+/-inf_

Row index: _start point_, Column index: _end point_

Symmetric about leading diagonal.

We have improved time compexity here O(v), but space complexity has increased O(v^2).

Useful for dense graph (more edges).

### Adjacencey List:
Vertex list remains same.

Adjacencey matrix takes up a lot of space, and a lot of it is wasted in storing 0 (no edge).

Instead, we can store adjacent vertices (or their indices) in an array or list or BST.

**Array**:
``` int *A[|V|]```
with the help of pointers, we can dynamically assign sizes using ```A[0] = new int[3]```.

Useful for sparse graph (better than adj mat).