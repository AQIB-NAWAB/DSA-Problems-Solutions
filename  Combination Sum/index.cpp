#include <iostream>
using namespace std;


vector<vector<int>> helper(vector<int>& nums, int target){

    int left=0;
    int right=nums.size()-1;


    int sum=0;
    while(left<=right){
        sum=nums[left]+nums[right];

        if(sum>target && sum+nums[start]>target){
            right--;
        }else if(sum>target && sum+nums[start]<target)sum+=nums[left];
        


        if(sum<target && sum+nums[right]<target){
            sum+=right;
        }else if(sum>target && sum+nums[start]<target)sum+=nums[left];
        
    }

}

int main(){

        int n;
        cin>>n;

        vector<int> nums(n);

        for(int i=0;i<n;i++){
            int temp;+
            cin>>temp;
            nums.push_back(temp);
        }

        int target;
        cin>>target;

        vector<vector<int>> ans=helper(nums,target);



    return 0;
}