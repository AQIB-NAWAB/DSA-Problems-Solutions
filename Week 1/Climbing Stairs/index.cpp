#include <iostream>
using namespace std;

// int steps(int n){
//     if(n==0 || n==1) return 1;


//     return steps(n-1)+steps(n-2);
// }


// linear apprach
int steps(int n){
       if(n==1 || n==0) return 1;
    int current=1;
    int prev=1;

    for(int i=2;i<=n;i++){
        int temp=current;
        current=temp+prev;
        prev=temp;
    }
    return current;
}
int main(){

    int n;
    cin>>n;

    cout<<steps(n);


    return 0;
}