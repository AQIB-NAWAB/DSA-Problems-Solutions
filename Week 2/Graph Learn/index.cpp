#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    int numVertices;
    vector<list<int>> adjList;

    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjList = vector<list<int>>(numVertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ":";
            for (int v : adjList[i]) {
                cout << " " << v;
            }
            cout << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printGraph();
    return 0;
}
