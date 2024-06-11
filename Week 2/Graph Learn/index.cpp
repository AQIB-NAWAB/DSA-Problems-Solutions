#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Class representing an undirected graph using adjacency list representation
class Graph {
public:
    int numVertices; // Number of vertices in the graph
    vector<list<int>> adjList; // Adjacency list to store the graph

    // Constructor to initialize the graph with a given number of vertices
    Graph(int numVertices) {
        this->numVertices = numVertices; // Set the number of vertices
        adjList = vector<list<int>>(numVertices); // Initialize the adjacency list with empty lists for each vertex
    }

    // Function to add an undirected edge between vertices u and v
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to the adjacency list of u
        adjList[v].push_back(u); // Add u to the adjacency list of v (since the graph is undirected)
    }

    // Function to print the adjacency list of the graph
    void printGraph() {
        for (int i = 0; i < numVertices; i++) { // Iterate through each vertex
            cout << "Vertex " << i << ":"; // Print the vertex number
            for (int v : adjList[i]) { // Iterate through the adjacency list of the current vertex
                cout << " " << v; // Print each connected vertex
            }
            cout << endl; // New line for the next vertex
        }
    }
};

int main() {
    int n, m;
    // Input the number of vertices and edges
    cin >> n >> m;
    Graph g(n); // Create a graph with n vertices

    // Input each edge and add it to the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; // Input the vertices of the edge
        g.addEdge(u, v); // Add the edge to the graph
    }

    g.printGraph(); // Print the adjacency list of the graph

    return 0;
}
