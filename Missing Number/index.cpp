#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> nums){
    int numsSum=0;
    int sumChecker=0;

    for(int i=0;i<nums.size()+1;i++){
        sumChecker+=i;
        if(i==nums.size()) break;
        numsSum+=nums[i];
    }

    return sumChecker-numsSum;
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

    cout<<missingNumber(nums);
    

    return 0;
}