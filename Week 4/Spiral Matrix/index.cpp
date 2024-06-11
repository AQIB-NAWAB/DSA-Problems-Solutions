#include <iostream>
#include <vector>
using namespace std;




int main() {
    int n;
    cin >> n;
    int arr[n][n];

    // inesert values from user 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           cin>> arr[i][j];
        }
    }


    int num = 1;
    int row = 0;
    int col = 0;
    int rowEnd = n - 1;
    int colEnd = n - 1;

    vector<int> ans;
    
    while (row <= rowEnd && col <= colEnd) {
        for (int i = col; i <= colEnd; i++) {
            ans.push_back(arr[row][i]);
            
        }
        row++;
        for (int i = row; i <= rowEnd; i++) {
            ans.push_back(arr[i][colEnd]);            
        }
        colEnd--;
        for (int i = colEnd; i >= col; i--) {
            ans.push_back(arr[rowEnd][i]);
        }
        rowEnd--;
        for (int i = rowEnd; i >= row; i--) {
            ans.push_back(arr[i][col]);
        }
        col++;
    }
    

    for(auto num:ans){
        cout<<num<<" ";
    }
    return 0;
}