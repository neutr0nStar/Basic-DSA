#include <iostream>
#include "graph.hpp"

int main() {
    Graph g(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 4);

    g.bfs(0);

    g.dfs(0);

    return 0;
}