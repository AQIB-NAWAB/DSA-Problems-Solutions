#include<iostream>
#include <vector>
using namespace std;



bool dfs(int c,vector<vector<int>> myMap,vector<bool>  visitings){
    if(visitings[c]){
        return false;
    }

    if(myMap[c].empty()){
        return true;
    }

    visitings[c]=true;

    for(int pre:myMap[c]){
        if(!dfs(pre,myMap,visitings)){
            return false;
        }
    }

    visitings[c]=false;

    return true;
}

bool CS(int numCourses,vector<vector<int>>& prereq){
    vector<vector<int>> myMap(numCourses);

    for(auto pair:prereq){
        myMap[pair[0]].push_back(pair[1]);

    }


    vector<bool> vistings(numCourses,false);

    for(int c=0;c<numCourses;c++){
        if(!dfs(c,myMap,vistings)){
            return false;
        }
    }

    return true;
}


int main(){

    int numCourses = 2;
    vector<vector<int>>  prerequisites = {{1,0},{0,1}};

    if(CS(numCourses,prerequisites)){

    cout<<"Yes we can Finshed all courses "<<endl;
    }else{
        cout<<"No we can't"<<endl;
    }
    return 0;
}



