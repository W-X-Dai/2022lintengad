#include<bits/stdc++.h>
#define eb emplace_back
#define int long long

using namespace std;

vector<int> v;

inline void init(){
    int x=1;
    for(int i=1;i<=30;++i)v.eb(x*2),x*=2;

    x=1;
    for(int i=1;i<=20;++i)v.eb(x*3),x*=3;

    x=1;
    for(int i=1;i<15;++i)v.eb(x*5),x*=5;
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int n;

    init();
    sort(v.begin(),v.end());
    cin >>n;
    cout<<v[n-1];
}