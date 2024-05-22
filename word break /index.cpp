#include <iostream>
using namespace std;
#include <unordered_set>
#include <unordered_map>


bool wordBreakMemo(string s, unordered_set<string>& wordDict, unordered_map<string, bool>& memo) {
    if (s.empty()) return true;
    if (memo.count(s)) return memo[s];

    for (int i = 1; i <= s.size(); ++i) {
        if (wordDict.count(s.substr(0, i)) && wordBreakMemo(s.substr(i), wordDict, memo)) {
            return memo[s] = true;
        }
    }
    return memo[s] = false;
}
int main(){

    string targetString;
    cin>>targetString;
    int n;
    cin>>n;
    unordered_set<string> myset;

    for(int i=0;i<n;i++){
        string temp;
        cin>>temp;
        myset.insert(temp);
    }
    unordered_map<string, bool> memo;

    bool output= wordBreakMemo(targetString,myset,memo);


    if(output){
     cout<<"True";
    }else{
     cout<<"false";

    }
    return 0;
}