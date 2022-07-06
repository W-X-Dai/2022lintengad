#include<bits/stdc++.h>
using namespace std;

int k,target;
int pre[65537];

inline void init(){
    for(int i=1;i<=65536;++i)pre[i]=i*i;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >>k;target=1<<k;
    
}