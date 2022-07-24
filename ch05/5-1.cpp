#include<bits/stdc++.h>
using namespace std;

/*
為什麼以前的APCS都那麼簡單喇...
這一題直接讀進字串，利用強制型態別轉換的技巧將字串中的元素轉成整數，
最後利用絕對值函數abs()輸出祕密差
*/

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    string s;cin >>s;
    int ans=0;
    for(int i=0;i<s.size();++i){
        if(i%2)ans+=(s[i]-'0');
        else ans-=(s[i]-'0');
    }
    cout<<abs(ans)<<'\n';
}