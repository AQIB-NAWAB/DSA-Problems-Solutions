#include <iostream>
using namespace  std;
#include<vector>
#include <unordered_set>
void CMZ(vector<vector<int>>& matrix){
    int row=matrix.size();
    int col=matrix[0].size();

    unordered_set<int> cols,rows;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                rows.insert(i);
                cols.insert(j);
            }
        }
    }


    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(rows.count(i) || cols.count(j)){
                matrix[i][j]=0;
            }
        }
    }
}


int main(){
    int m;
    int n;

    cin>>m;
    cin>>n;

    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }

    CMZ(matrix);

       for(int i=0;i<m;i++){
        cout<<"[";
        for(int j=0;j<n;j++){
            cout<<matrix[i][j];
        }
        cout<<"],";
        cout<<endl;
    }


    return 0;
}