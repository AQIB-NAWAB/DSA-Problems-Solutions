#include <iostream>
using namespace std;
#include <vector>

vector<int> concat(vector<int>& nums){
    int n=nums.size();
    vector<int> temp(n*2);

    for(int i=0;i<n;i++){
        temp[i]=nums[i];
        temp[i+n]=nums[i];
    }

    return temp;

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

    vector<int> ans= concat(nums);

    cout<<endl<<"Answer ";

    for(auto n:ans){
        cout<<n<<" ";
    }

    return 0;
}