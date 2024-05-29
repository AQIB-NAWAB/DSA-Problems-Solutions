#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


int LCS(vector<int>& nums){
     unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : numSet) {
            if (numSet.find(n - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(n + length) != numSet.end()) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
}

int main(){
    int size;
    cin>>size;

    vector<int> nums;
    for(int i=0;i<size;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    cout<<LCS(nums);
    

    return 0;
}