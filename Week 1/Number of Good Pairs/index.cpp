#include <iostream>
using namespace std;
#include <vector>


int goodPairs(vector<int>&  nums){
    int count=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]==nums[j] && i<j) count++;
        }
    }

    return count;
}


int main(){

    int n;
    cin>>n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<goodPairs(nums);

    return 0;
}