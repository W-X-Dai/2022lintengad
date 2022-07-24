#include<bits/stdc++.h>
using namespace std;

/*
觀察數字範圍，會發現只有求到十位數。此時，也不需要想太多，直接枚舉平方根即可。粗略估算枚舉平方根最多只需要到10^6，
完全在可接受的範圍內。但是要擔心詢問次數過多，如果每次都重新計算有概率TLE(事實證明我多慮了...)
因此，建一個表格ans，其中ans[i]代表i位數時的答案，事後依據詢問進行查表即可
*/

int ans[11];

inline int len(int x){
    //將整數轉成字串可直接判斷位數
    string s=to_string(x);
    return s.size();
}

inline bool even(int x){
    string s=to_string(x);
    //此為迭代器(iterator)之寫法，等同於for(int i=0;i<s.size();++i)
    for(auto i:s){
        //裡面的i代表字串s之某個字元
        if((i-'0') & 1)return 0;
    }
    return 1;
}

inline void init(){
    for(int i=1;i<=400000;++i){
        if(!ans[len(i*i)] && even(i*i)){
            ans[len(i*i)]=i*i;
        }
    }
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    init();

    int n;
    cin >>n;
    while(n--){
        int k;
        cin >>k;
        cout<<ans[k]<<'\n';
    }
}
