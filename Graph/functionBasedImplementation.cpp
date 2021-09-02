#include <iostream>
#include <vector>
using namespace std;

// Add an edge between a and b
void add_edge(vector<int> adj[], int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

// Utility function: print
void print(vector<int> adj[], int S) {
    for(int i = 0; i < S; i++) {
        cout << "Adjacency list of vertex " << i << " : ";
        for(auto it: adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    int S = 5;
    vector<int> adj[S];
    add_edge(adj, 1, 2);
    add_edge(adj, 2, 3);
    add_edge(adj, 3, 1);

    //    1
    //   / \
    // 2 -- 3

    print(adj, S);
    return 0;
}