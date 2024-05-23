#include <iostream>
#include <vector>
using namespace std;

// Recursive Soltions
// int LCS(string text1,string text2,int a, int b){
//     if(a==0 || b==0) return 0;
     

//      if(text1[a-1]==text2[b-1]) {
//         return 1+LCS(text1,text2,a-1,b-1);
//      }else{
//         return max(LCS(text1,text2,a-1,b),LCS(text1,text2,a,b-1));
//      }    
// }


// int LCS(string X, string Y, int m, int n, vector<vector<int>>& dp) {
//     if (m == 0 || n == 0) {
//         return 0;
//     }
//     if (dp[m][n] != -1) {
//         return dp[m][n];
//     }
//     if (X[m - 1] == Y[n - 1]) {
//         dp[m][n] = 1 + LCS(X, Y, m - 1, n - 1, dp);
//     } else {
//         dp[m][n] = max(LCS(X, Y, m, n - 1, dp), LCS(X, Y, m - 1, n, dp));
//     }
//     return dp[m][n];
// }


// Bottom up Appracoh 
int LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout<<"M "<<m<<endl;
    cout<<"N "<<n<<endl;

    return dp[m][n];
}

int main()
{   

    string X,Y;
    cin>>X;
    cin>>Y;
    int m = X.size();
    int n = Y.size();

    // cout<<LCS(X,Y,m,n);  Recursive Case

    // Memoization
    // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    // cout << LCS(X, Y, m, n, dp) << endl;

    // Bottom Up Apprach 
       cout << LCS(X, Y) << endl;
    return 0;
}
