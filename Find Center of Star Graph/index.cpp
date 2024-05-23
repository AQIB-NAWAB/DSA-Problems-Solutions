#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>


int FCOG(vector<vector<int>>& nums){
    unordered_set<int>  mySet;

    for(auto num:nums){
        
        if(mySet.count(num[0])) return num[0];

        mySet.insert(num[0]);

        if(mySet.count(num[1])) return num[1];

        mySet.insert(num[1]);
    }
    return -1;
}

int main(){

    int row, col;
    cin >> row >> col;

    // Use a vector of vectors to store the input matrix
    vector<vector<int>> nums(row, vector<int>(col));

    // Input the elements of the matrix
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> nums[i][j];
        }
    }

    cout<<FCOG(nums);

    return 0;

}