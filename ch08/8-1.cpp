#include<bits/stdc++.h>
using namespace std;

int tree[500005],D,I;

//the ball is at k-th point
inline void drop(int id,int k){
    if(k>=(1<<D)){
        if(id==I)cout<<k/2<<'\n';
        return;
    }
    !tree[k]?drop(id,k<<1):drop(id,k<<1|1);
    tree[k]=~tree[k];
}

inline void sol(){
    cin >>D>>I;
    memset(tree,0,1<<D+1);

    for(int i=1;i<=I;++i){
        drop(i,1);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >>t;
    while(t--)sol();
    return 0;
}