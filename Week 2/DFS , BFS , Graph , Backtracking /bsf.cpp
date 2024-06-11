// #include <iostream>
// #include <vector>
// #include <queue>

// // using namespace std;

// // void bfs(int startNode, const vector<vector<int>>& adj, vector<bool>& visited) {
// //     queue<int> q;
// //     q.push(startNode);
// //     visited[startNode] = true;

// //     while (!q.empty()) {
// //         int currentNode = q.front();
// //         q.pop();
// //         cout << currentNode << " ";

// //         for (int neighbor : adj[currentNode]) {
// //             if (!visited[neighbor]) {
// //                 visited[neighbor] = true;
// //                 q.push(neighbor);
// //             }
// //         }
// //     }
// // }

// // int main() {
// //     int n = 6; // Number of nodes
// //     vector<vector<int>> adj(n);
    
// //     // Edges of the graph
// //     adj[0] = {1, 2};
// //     adj[1] = {0, 3, 4};
// //     adj[2] = {0, 4};
// //     adj[3] = {1, 4, 5};
// //     adj[4] = {1, 2, 3};
// //     adj[5] = {3};
    
// //     vector<bool> visited(n, false);
    
// //     cout << "BFS Traversal starting from node 0: ";
// //     bfs(0, adj, visited);
    
// //     return 0;
// // }


// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty()) return 0;
        
//         int row = grid.size();
//         int col = grid[0].size();
//         int count = 0;
        
//         vector<vector<bool>> visited(row, vector<bool>(col, false));
        
//         for (int i = 0; i < row; ++i) {
//             for (int j = 0; j < col; ++j) {
//                 if (grid[i][j] == '1' && !visited[i][j]) {
//                     bfs(i, j, row, col, visited, grid);
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
    
//     void bfs(int x, int y, int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         visited[x][y] = true;
        
//         int dx[] = {0, 1, 0, -1};
//         int dy[] = {1, 0, -1, 0};
        
//         while (!q.empty()) {
//             auto [i, j] = q.front();
//             q.pop();
            
//             for (int k = 0; k < 4; ++k) {
//                 int ni = i + dx[k];
//                 int nj = j + dy[k];
                
//                 if (ni >= 0 && nj >= 0 && ni < row && nj < col && grid[ni][nj] == '1' && !visited[ni][nj]) {
//                     visited[ni][nj] = true;
//                     q.push({ni, nj});
//                 }
//             }
//         }
//     }
// };


// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// // Function to find the shortest path using BFS
// int shortestPath(int n, const vector<pair<int, int>>& edges, int start, int target) {
//     vector<vector<int>> adj(n);
//     for (const auto& edge : edges) {
//         adj[edge.first].push_back(edge.second);
//         adj[edge.second].push_back(edge.first); // Since the graph is undirected
//     }

//     vector<bool> visited(n, false);
//     queue<pair<int, int>> q; // Pair of (current node, current distance)
    
//     q.push({start, 0});
//     visited[start] = true;

//     while (!q.empty()) {
//         int node = q.front().first;
//         int dist = q.front().second;
//         q.pop();

//         if (node == target) {
//             return dist;
//         }

//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor]) {
//                 visited[neighbor] = true;
//                 q.push({neighbor, dist + 1});
//             }
//         }
//     }

//     return -1; // No path found
// }

// // Function to run test cases
// void runTestCases() {
//     struct TestCase {
//         int n;
//         vector<pair<int, int>> edges;
//         int start;
//         int target;
//         int expectedOutput;
//     };

//     vector<TestCase> testCases = {
//         {5, {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}}, 0, 4, 3},
//         {3, {{0, 1}, {1, 2}}, 0, 2, 2},
//         {4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, 3},
//         {4, {{0, 1}, {1, 2}}, 0, 3, -1}
//     };

//     for (const auto& test : testCases) {
//         int result = shortestPath(test.n, test.edges, test.start, test.target);
//         cout << "Input:\n";
//         cout << "n = " << test.n << "\n";
//         cout << "Edges:\n";
//         for (const auto& edge : test.edges) {
//             cout << "(" << edge.first << ", " << edge.second << ") ";
//         }
//         cout << "\nStart: " << test.start << "\n";
//         cout << "Target: " << test.target << "\n";
//         cout << "Expected Output: " << test.expectedOutput << "\n";
//         cout << "Your Output: " << result << "\n";
//         cout << (result == test.expectedOutput ? "Pass" : "Fail") << "\n\n";
//     }
// }

// int main() {
//     runTestCases();
//     return 0;
// }


// Problem 2: Number of Connected Components in an Undirected Graph
// Problem Description

// Given an undirected graph represented as an adjacency list, find the number of connected components using BFS.

// Input:

//     An integer n representing the number of nodes.
//     A list of pairs where each pair (u, v) represents an edge between node u and node v.

// Output:

//     An integer representing the number of connected components in the graph.

// Example:

//     Input:

//     makefile

// n = 5
// edges = [(0, 1), (1, 2), (3, 4)]

// Output:

//     2


// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;

// // Function to find the number of connected components using BFS
// int countConnectedComponents(int n, const vector<pair<int, int>>& edges) {
//     vector<vector<int>> adj(n);
//     for (const auto& edge : edges) {
//         adj[edge.first].push_back(edge.second);
//         adj[edge.second].push_back(edge.first);
//     }

//     vector<bool> visited(n, false);
//     int componentCount = 0;

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             componentCount++;
//             queue<int> q;
//             q.push(i);
//             visited[i] = true;

//             while (!q.empty()) {
//                 int node = q.front();
//                 q.pop();

//                 for (int neighbor : adj[node]) {
//                     if (!visited[neighbor]) {
//                         visited[neighbor] = true;
//                         q.push(neighbor);
//                     }
//                 }
//             }
//         }
//     }

//     return componentCount;
// }

// // Function to run test cases
// void runTestCases() {
//     struct TestCase {
//         int n;
//         vector<pair<int, int>> edges;
//         int expectedOutput;
//     };

//     vector<TestCase> testCases = {
//         {5, {{0, 1}, {1, 2}, {3, 4}}, 2},
//         {5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, 1},
//         {4, {{0, 1}, {2, 3}}, 2},
//         {6, {{0, 1}, {1, 2}, {3, 4}, {4, 5}}, 2}
//     };

//     for (const auto& test : testCases) {
//         int result = countConnectedComponents(test.n, test.edges);
//         cout << "Input:\n";
//         cout << "n = " << test.n << "\n";
//         cout << "Edges:\n";
//         for (const auto& edge : test.edges) {
//             cout << "(" << edge.first << ", " << edge.second << ") ";
//         }
//         cout << "\nExpected Output: " << test.expectedOutput << "\n";
//         cout << "Your Output: " << result << "\n";
//         cout << (result == test.expectedOutput ? "Pass" : "Fail") << "\n\n";
//     }
// }

// int main() {
//     runTestCases();
//     return 0;
// }
