#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> mymap;
        queue<Node*> q;
        Node* copy = new Node(node->val);
        mymap[node] = copy;
        q.push(node);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            for (Node* neighbor : current->neighbors) {
                if (!mymap.count(neighbor)) {
                    mymap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mymap[current]->neighbors.push_back(mymap[neighbor]);
            }
        }
        
        return copy;
    }
};

int main() {
    // Reading input
    // Assuming input format:
    // N (number of nodes)
    // Then for each node, its value and its neighbors
    int N;
    cin >> N;
    vector<Node*> nodes(N + 1); // nodes are 1-indexed
    for (int i = 1; i <= N; ++i) {
        int val, numNeighbors;
        cin >> val >> numNeighbors;
        nodes[i] = new Node(val);
        for (int j = 0; j < numNeighbors; ++j) {
            int neighborIdx;
            cin >> neighborIdx;
            nodes[i]->neighbors.push_back(nodes[neighborIdx]);
        }
    }

    // Cloning the graph
    Solution sol;
    Node* clonedGraph = sol.cloneGraph(nodes[1]); // Assuming the first node is the starting node

    // Output the cloned graph if needed
    // For competitive programming, output requirements depend on the problem statement
    // If the problem requires printing the cloned graph, you can do it here

    return 0;
}
