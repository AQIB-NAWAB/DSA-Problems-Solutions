#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v's list
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v])
                std::cout << "-> " << x;
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(5); // Create a graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
