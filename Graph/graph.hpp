#include <iostream>
#include "../LinkedList/linkedList.hpp"
#include "../Queue/linkedListQueue.hpp"
#include "../Stack/linkedListStack.hpp"

#ifndef GRAPH_H
#define GRAPH_H

// REFER notes.md

/**
 * Adjacency list implementation of digraph (directed graph)
 */

class Graph {
    private:
    const size_t nVertices; // no of vertices
    LinkedList<int> *adj; // adj list of each node

    public:
    // Constructor
    Graph(size_t n): nVertices(n), adj(new LinkedList<int>[nVertices]) {}

    // Add new edge
    // @param from: from vertex
    // @param to: to vertex
    void add_edge(int from, int to) {
        adj[from].insert_end(to);
        if (from != to)
            adj[to].insert_end(from);
    }

    // Breadth first search in graph
    void bfs(int from) {
        bool is_visited[nVertices];
        for(int i = 0; i < nVertices; i++) is_visited[i] = false;

        LinkedListQueue<int> queue;
        is_visited[from] = true;
        queue.enqueue(from);
        int n;

        while(!queue.is_empty()) {
            n = queue.peek();
            std::cout << n << " ";
            queue.dequeue();

            for(int i = 0; i < adj[n].get_size(); i++) {
                if(!is_visited[adj[n][i]]) {
                    is_visited[adj[n][i]] = true;
                    queue.enqueue(adj[n][i]);
                }
            }
        }
        std::cout << std::endl;
    }

    void dfs(int from) {
        bool is_visited[nVertices] = {false};

        LinkedListStack<int> stack;
        is_visited[from] = true;
        stack.push(from);
        int n;

        while(!stack.is_empty()) {
            n = stack.get_top();
            std::cout << n << " ";
            stack.pop();

            for(int i = 0; i < adj[n].get_size(); i++) {
                if(!is_visited[adj[n][i]]) {
                    is_visited[adj[n][i]] = true;
                    stack.push(adj[n][i]);
                }
            }
        }

        std::cout << std::endl;
    }
};

#endif