#include <iostream>
#include <vector>

using namespace std;


void dfs(int i,vector<bool>&  visit,vector<vector<int>>&  rooms){
    if(visit[i]){
        return ;
    }

    visit[i]=true;

    for(int j=0;j<rooms[i].size();j++){
         dfs(rooms[i][j],visit,rooms);
    }
}

bool KAR(vector<vector<int>>& rooms){
    int n=rooms.size();

    vector<bool> visit(n,false);

    dfs(0,visit,rooms);

    for(auto n:visit) if(n==false) return false;

    return true;
}

int main(){

    vector<vector<int>> rooms = {{1,3},{3,0,1},{2},{0}};
    if(KAR(rooms))
    cout<<"true";
    else 
    cout <<"False";
    return 0;
}