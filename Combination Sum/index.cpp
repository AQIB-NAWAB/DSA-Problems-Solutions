#include <iostream>
#include <vector>
using namespace std;

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

void backtrack(vector<int>& nums, int target, int start, vector<int>& current, vector<vector<int>>& result) {
  if(target==0) {
    result.push_back(current);
    return ;
  }


  for(int i=start;i<nums.size();i++){
      if (nums[i] > target) continue;

    current.push_back(nums[i]);
    backtrack(nums,target-nums[i],i,current,result);
    current.pop_back();
  }

}

vector<vector<int>> helper(vector<int>& nums, int target){

  vector<vector<int>> result;
  vector<int> current;



  backtrack(nums,target,0,current,result);
  return result;
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

        int target;
        cin>>target;

        vector<vector<int>> ans=helper(nums,target);

        cout<<"Answer "<<ans.size();

    return 0;
}