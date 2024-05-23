#include <iostream>
#include <vector>
using namespace std;

void allPaths(vector<vector<int>>& graph,vector<vector<int>>& paths,vector<int>& path,int start,int destination){
     path.push_back(start);
        // Base condtion if start == destination.
        if(start == destination){
            paths.push_back(path);
            return;
        }
         // traversal in dfs (adjacency list is already given)
        for(auto x:graph[start]){
            allPaths(graph,paths,path,x,destination);
        }
}

int main(){

    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    vector<vector<int>> paths;
    vector<int> path;
    
    int nodes=graph.size();


    allPaths(graph,paths,path,0,nodes-1);
    cout<<paths.size();
    return 0;
}