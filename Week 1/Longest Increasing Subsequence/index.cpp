#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int LIS(vector<int>& nums){
    vector<int> temp;
    temp.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }else {
           int ind = std::lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];

        };
    }


    return temp.size();
}

// int LIS(vector<int>& nums){
//     if(nums.empty()) return 0;
//     int n=nums.size();
//     vector<int> temp(n,1);

//     for(int i=1;i<n;i++){
//         for(int j=0;j<i;j++){
//             if(nums[i]>nums[j]){
//                 temp[i]=max(nums[i],nums[j]+1);
//             }
//         }
//     }

//     return *max_element(temp.begin(), temp.end()); 
// }



int main(){

    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<LIS(nums); 

   
    
    return 0;
}