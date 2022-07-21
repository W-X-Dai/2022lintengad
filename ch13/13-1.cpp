#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
/*
TMD卡我long long...
*/

inline void sol(){
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;++i){
        int x;cin >>x;
        pq.push(x);
    }
    for(int i=1;i<n;++i){
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        cnt+=a+b;pq.push(a+b);
    }
    cout<<cnt<<'\n';
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>n && n)sol();
    return 0;
}