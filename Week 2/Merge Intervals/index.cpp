#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> MI(vector<vector<int>>& intervals){
    vector<vector<int>> ans;

    for(auto interval:intervals){
        if(ans.empty() || ans.back()[1]<interval[0]){
            ans.push_back(interval);
        }else{
            ans.back()[1]=max(interval[1],ans.back()[1]);
        }
    }
    return ans;
}










int main(){

    int n;
    cin>>n;

    vector<vector<int>> interavls(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>interavls[i][0];
        cin>>interavls[i][1];

    }

    vector<vector<int>> ans= MI(interavls);
    cout<<"["<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" , ";
        }
        cout<<"],"<<endl;

        cout<<endl;
    }

    cout<<"]";

    return 0;
}
