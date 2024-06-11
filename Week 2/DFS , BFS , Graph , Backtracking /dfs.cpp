// #include <iostream>
// #include <vector>
// #include <stack>
// using namespace std;

 
// void dfs(vector<bool>& visited,vector<vector<int>>& adj,int node){
//     visited[node]=true;

//     for(int neighbor:adj[node]){
//         if(!visited[neighbor]){
//             dfs(visited,adj,neighbor);
//         }
//     }
// }

// void dfs_iterative(vector<bool>& visited,vector<vector<int>>& adj,int start){
//     stack<int> s;

//     s.push(start);

//     while(!s.empty()){
//         int node=s.top();
//         s.pop();

//         if(!visited[node]){
//             visited[node]=true;


//             for(int n:adj[node]){
//                 if(!visited[node]){
//                     s.push(n);
//                 }
//             }

//         }
//     }
// }

// int main(){
//     int n=5;
//     vector<vector<int>> adj(n);
//     adj[0] = {1, 2};
//     adj[1] = {0, 3, 4};
//     adj[2] = {0};
//     adj[3] = {1};
//     adj[4] = {1};

//     vector<bool> visited(n,false);
    
//     dfs(visited,adj,0);

//     for(bool v:visited){
//         if(v==false) cout<<"Hy Found out "<<endl;
//     }

//     return 0;
// }



// Problem 1
// Problem Description: Path in a Grid

// Problem:
// Given a 2D grid of size n x m with the following cells:

//     0 represents an empty cell.
//     1 represents a wall or obstacle.

// You need to determine if there's a path from the top-left corner (0, 0) to the bottom-right corner (n-1, m-1) using DFS.

// #include <iostream>
// #include <vector>

// using namespace std;

// bool isValid(int x, int y, int n, int m) {
//     return x >= 0 && y >= 0 && x < n && y < m;
// }

// bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
//     int n = grid.size();
//     int m = grid[0].size();

//     if (x == n - 1 && y == m - 1) {
//         return true;
//     }

//     static int dx[] = {0, 1, 0, -1};
//     static int dy[] = {1, 0, -1, 0};

//     visited[x][y] = true;

//     for (int i = 0; i < 4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if (isValid(nx, ny, n, m) && grid[nx][ny] == 0 && !visited[nx][ny]) {
//             if (dfs(grid, visited, nx, ny)) {
//                 return true;
//             }
//         }
//     }

//     return false;
// }

// bool isPathExists(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<bool>> visited(n, vector<bool>(m, false));

//     return dfs(grid, visited, 0, 0);
// }

// void runTestCases() {
//     struct TestCase {
//         vector<vector<int>> grid;
//         bool expectedOutput;
//     };

//     vector<TestCase> testCases = {
//         {{{0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}}, true},
//         {{{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}, {1, 1, 0, 0}}, false},
//         {{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, true},
//     };

//     for (const auto& test : testCases) {
//         bool result = isPathExists(test.grid);
//         cout << "Input Grid:\n";
//         for (const auto& row : test.grid) {
//             for (int cell : row) {
//                 cout << cell << " ";
//             }
//             cout << endl;
//         }
//         cout << "Expected Output: " << boolalpha << test.expectedOutput << "\n";
//         cout << "Your Output: " << boolalpha << result << "\n";
//         cout << (result == test.expectedOutput ? "Pass" : "Fail") << "\n\n";
//     }
// }

// int main() {
//     runTestCases();
//     return 0;
// }




// Problem #2 
// Determine the number of Islands 


// #include <vector>
// #include <iostream>

// using namespace std;

// void dfs(vector<vector<char>>& grid, int x, int y) {
//     int n = grid.size();
//     int m = grid[0].size();

//     if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0') {
//         return;
//     }

//     grid[x][y] = '0'; // Mark as visited

//     int dx[] = {0, 1, 0, -1};
//     int dy[] = {1, 0, -1, 0};

//     for (int i = 0; i < 4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         dfs(grid, nx, ny);
//     }
// }

// int numIslands(vector<vector<char>>& grid) {
//     if (grid.empty()) {
//         return 0;
//     }

//     int n = grid.size();
//     int m = grid[0].size();
//     int islandCount =0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             if (grid[i][j] == '1') {
//                 ++islandCount;
//                 dfs(grid, i, j);
//             }
//         }
//     }

//     return islandCount;
// }

// int main() {
//     vector<vector<char>> grid = {
//         {'1', '1', '0', '0', '0'},
//         {'1', '1', '0', '0', '0'},
//         {'0', '0', '1', '0', '0'},
//         {'0', '0', '0', '1', '1'}
//     };

//     cout << "Number of islands: " << numIslands(grid) << endl;
//     return 0;
// }



// Porblem #3
// Problem 1: Counting Connected Components in a Graph
// Problem Description

// Given an undirected graph represented as an adjacency matrix, count the number of connected components using DFS.

// Input:

//     An integer n representing the number of nodes.
//     An n x n adjacency matrix where matrix[i][j] is 1 if there is an edge between node i and node j, and 0 otherwise.

// Output:

//     An integer representing the number of connected components.


// #include <iostream>
// #include <vector>

// using namespace std;

// void dfs(const vector<vector<int>>& matrix, vector<bool>& visited, int node) {
//     visited[node] = true;
//     for (int i = 0; i < matrix.size(); ++i) {
//         if (matrix[node][i] == 1 && !visited[i]) {
//             dfs(matrix, visited, i);
//         }
//     }
// }

// int countConnectedComponents(int n, vector<vector<int>>& matrix) {
//     vector<bool> visited(n, false);
//     int componentCount = 0;

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             ++componentCount;
//             dfs(matrix, visited, i);
//         }
//     }

//     return componentCount;
// }

// void runTestCases() {
//     struct TestCase {
//         int n;
//         vector<vector<int>> matrix;
//         int expectedOutput;
//     };

//     vector<TestCase> testCases = {
//         {4, {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}}, 2},
//         {3, {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3},
//         {5, {{1, 1, 0, 0, 0}, {1, 1, 1, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}}, 2}
//     };

//     for (const auto& test : testCases) {
//         int result = countConnectedComponents(test.n, test.matrix);
//         cout << "Input:\n";
//         cout << "n = " << test.n << "\n";
//         cout << "Matrix:\n";
//         for (const auto& row : test.matrix) {
//             for (int cell : row) {
//                 cout << cell << " ";
//             }
//             cout << endl;
//         }
//         cout << "Expected Output: " << test.expectedOutput << "\n";
//         cout << "Your Output: " << result << "\n";
//         cout << (result == test.expectedOutput ? "Pass" : "Fail") << "\n\n";
//     }
// }

// int main() {
//     runTestCases();
//     return 0;
// }



// Problem 4: Finding Cycles in a Graph
// Problem Description

// Given a directed graph represented as an adjacency list, determine if there is a cycle in the graph using DFS. 



#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& adj, vector<int>& visited, int v) {
    if (visited[v] == 1) return true; // Cycle detected
    if (visited[v] == 2) return false;

    visited[v] = 1; // Mark current node as visiting

    for (int neighbor : adj[v]) {
        if (dfs(adj, visited, neighbor)) {
            return true;
        }
    }

    visited[v] = 2; // Mark current node as visited
    return false;
}

bool hasCycle(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    
    for (const auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    vector<int> visited(n, 0); // 0 = unvisited, 1 = visiting, 2 = visited

    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            if (dfs(adj, visited, i)) {
                return true;
            }
        }
    }

    return false;
}

void runTestCases() {
    struct TestCase {
        int n;
        int m;
        vector<pair<int, int>> edges;
        bool expectedOutput;
    };

    vector<TestCase> testCases = {
        {4, 4, {{0, 1}, {1, 2}, {2, 0}, {3, 0}}, true},
        {3, 2, {{0, 1}, {1, 2}}, false},
        {5, 5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 2}}, true}
    };

    for (const auto& test : testCases) {
        bool result = hasCycle(test.n, test.edges);
        cout << "Input:\n";
        cout << "n = " << test.n << "\n";
        cout << "m = " << test.m << "\n";
        cout << "Edges:\n";
        for (const auto& edge : test.edges) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << "\nExpected Output: " << boolalpha << test.expectedOutput << "\n";
        cout << "Your Output: " << boolalpha << result << "\n";
        cout << (result == test.expectedOutput ? "Pass" : "Fail") << "\n\n";
    }
}

int main() {
    runTestCases();
    return 0;
}
