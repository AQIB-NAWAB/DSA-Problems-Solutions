#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long maximumImportance(int n,vector<vector<int>>& roads){
    vector<int> degree(n,0);

    for(auto road:roads){
        degree[road[1]]++;
        degree[road[0]]++;

    }

    sort(degree.begin(),degree.end());

    long long importance=0;

    for(int i=0;i<n;i++){
        importance+=(long long)(i+1)*degree[i];
    }

    return importance;
}


int main(){
    int n = 5;
    vector<vector<int>>  roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};



    cout<<maximumImportance(n,roads)<<endl;

    return 0;
}