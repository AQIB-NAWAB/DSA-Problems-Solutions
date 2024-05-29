#include <iostream>
#include <vector>

using namespace std;


void dfs(vector<vector<int>>& isConnected,int i, vector<bool>& visit) {
    visit[i] = true;

    for (int j = 0; j < isConnected.size(); j++) {
        if (!visit[j] && isConnected[i][j] == 1) {
            dfs(isConnected, j, visit);
        }
    }
}


int findCircleNum(vector<vector<int>>& isConnected) {
    vector<bool> visit(isConnected.size(),false);

    int ans=0;

    for(int i=0;i<isConnected.size();i++){
        if(visit[i]==false){
            dfs(isConnected,i,visit);
            ans++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> isConnected(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << findCircleNum(isConnected) << endl;

    return 0;
}
