#include <iostream>
#include <unordered_set>
using namespace std;



int main(){

    string s;
    cin>>s;

    int n=s.size();
    int left=0;
    
    unordered_set<char> set;
    int ans=0;


    for(int i=0;i<n;i++){
        while(set.count(s[i])){
            set.erase(s[left]);
            left++;
        }
        set.insert(s[i]);
        ans=max(ans,i-left+1);
    }

    cout<<ans<<endl;

    return  0;
}


