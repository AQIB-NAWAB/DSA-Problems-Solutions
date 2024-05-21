#include <iostream>
#include <vector>
using namespace std;

int houseRob2BruteForce(vector<int>& nums,int start,int end){
    if(start>end) return 0;
    if(start==end) return nums[start];

    int robCurrent=nums[start]+houseRob2BruteForce(nums,start+2,end);
    int skipCurrent=houseRob2BruteForce(nums,start+1,end);

    return max(skipCurrent,robCurrent);
}




int houseRob2Linear(vector<int>& nums,int start,int end){

     if (start == end) return nums[start];
    
    int prev1 = 0, prev2 = 0;
    for (int i = start; i <= end; ++i) {
        int temp = prev1;
        prev1 = max(prev1, prev2 + nums[i]);
        prev2 = temp;
    }
    return prev1;
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
    
    // cout<<max(houseRob2BruteForce(nums,0,n-2) , houseRob2BruteForce(nums,1,n-1));    

    cout<<max(houseRob2Linear(nums,0,n-2) , houseRob2Linear(nums,1,n-1));    

    return 0;
}