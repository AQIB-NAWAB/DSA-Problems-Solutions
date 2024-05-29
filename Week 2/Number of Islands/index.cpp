#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<string>>& grid ,int i,int j,int m,int n){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=="0"){
        return ;
    }

    grid[i][j]="0";

    dfs(grid,i+1,j,m,n);
    dfs(grid,i-1,j,m,n);
    dfs(grid,i,j+1,m,n);
    dfs(grid,i,j-1,m,n);

}


int main() {

    int row;
    int col;
    cout<<"Enter the row and col "<<endl;
    cin>>row >>  col;

    vector<vector<string>> grid (row,vector<string>(col));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>grid[i][j];
        }
    }

cout<<"Here is how grid looks like"<<endl;
    cout<<"   ["<<endl;
    for(int i =0;i<row;i++){
        cout<<"[";
        for(int j=0;j<col;j++){
            cout<<grid[i][j]<<",";
        }
        cout<<"],"<<endl;
    }
    cout<<"   ]"<<endl;


    int m=grid.size();
    int n=grid[0].size();
    int count=0;
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=="1"){
                    dfs(grid,i,j,m,n);
                    count++;
            }
        }
    }

    cout<<"Here is the cout of the grid " <<count<<endl;
    return 0;
}
