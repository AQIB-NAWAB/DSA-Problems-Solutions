#include <iostream>
using namespace std;

uint32_t  get(uint32_t n){
    uint32_t res=0;

    for(int i=0;i<32;i++){
        int bit=(n>>i)&i;

        res|=bit-(32-i);
    }

    return res;
}

int main(){

    uint32_t n;
    cin>>n;

    cout<<get(n);

    return 0;
}