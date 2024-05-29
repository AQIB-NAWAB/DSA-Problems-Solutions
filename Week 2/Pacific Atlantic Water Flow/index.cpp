#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int r, int c, int prev, unordered_set<int>& visit, int ROWS, int COLS, vector<vector<int>>& heights) {
    int coord = r * COLS + c;
    // Check if out of bounds, if the current height is less than the previous height, or if already visited
    if (r < 0 || c < 0 || r >= ROWS || c >= COLS || heights[r][c] < prev || visit.count(coord)) {
        return;
    }
    visit.insert(coord); // Mark the cell as visited
    // Explore all four directions
    dfs(r + 1, c, heights[r][c], visit, ROWS, COLS, heights);
    dfs(r - 1, c, heights[r][c], visit, ROWS, COLS, heights);
    dfs(r, c + 1, heights[r][c], visit, ROWS, COLS, heights);
    dfs(r, c - 1, heights[r][c], visit, ROWS, COLS, heights);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    unordered_set<int> pac;
    unordered_set<int> atl;
    int ROWS = heights.size();
    int COLS = heights[0].size();

    for (int i = 0; i < COLS; i++) {
        dfs(0, i, heights[0][i], pac, ROWS, COLS, heights);
        dfs(ROWS - 1, i, heights[ROWS - 1][i], atl, ROWS, COLS, heights);
    }

    for (int i = 0; i < ROWS; i++) {
        dfs(i, 0, heights[i][0], pac, ROWS, COLS, heights);
        dfs(i, COLS - 1, heights[i][COLS - 1], atl, ROWS, COLS, heights);
    }

    vector<vector<int>> res;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int coord = i * COLS + j;
            if (pac.count(coord) && atl.count(coord)) {
                res.push_back({i, j});
            }
        }
    }

    return res;
}

int main() {
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

    vector<vector<int>> ans = pacificAtlantic(heights);
    cout << ans.size() << endl;
    for (const auto& pair : ans) {
        cout << "(" << pair[0] << ", " << pair[1] << ")\n";
    }
    return 0;
}
