#include <iostream> 
using namespace std;
#include <vector>

int helper(int r,int c){
    vector<vector<int>> dp(r,vector<int>(c));

    for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 || j==c-1) dp[i][j]=1;
                else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }

    return dp[0][0];
        
}

int main(){
    int row,col;
    cout<<"Enter the row ";
    cin>>row;
    cout<<"Enter the column ";
    cin>>col;

    cout<<helper(row,col);





    return 0;
}