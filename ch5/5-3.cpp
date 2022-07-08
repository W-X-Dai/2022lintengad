#include<bits/stdc++.h>
using namespace std;

inline void trans(int n){
    string hash[8]={"","001","010","011","100","101","110","111"};
    cout<<hash[n];
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    while(n--){
        string s;
        getline(cin,s);
        for(auto i:s)if(i!='0' || i!='1'){
            cout<<-1<<'\n';
            continue;
        }
        int combo=1;
        for(int j=1;j<s.size();++j){
            
            if(s[j]==s[j-1])++combo;
            else {
                trans(combo);
                cout<<s[j-1]<<" ";
            }
        }
        cout<<'\n';
    }
}
