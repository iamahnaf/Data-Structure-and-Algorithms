#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adj; 

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); 
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (auto node : adj[i]) {
                cout << node << " ";
            }
            cout << endl;
        }
    }
};