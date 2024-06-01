#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


int NOI(vector<vector<int>>& intervals){
    sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
        return a[1] < b[1];
    });
    int end=intervals[0][1];
    int count=0;
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<end) count++;
        else{
            end=intervals[i][0];
        }
    }

    return count;
}

int main(){

    int n;

    cin>>n;

    vector<vector<int>> temp(n,vector<int>(2));

    for(int i=0;i<n;i++){
        cin>>temp[i][0];
        cin>>temp[i][1];
    }

     cout<<NOI(temp);   

    return 0;
}