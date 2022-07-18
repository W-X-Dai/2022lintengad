#include<bits/stdc++.h>
using namespace std;

int n,cnt;
int arr[1000005],v[1000005];

inline void vis(int ori,int id){
    if(ori==id)return;
    v[id]=1;
    vis(ori,arr[id]);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i];
    for(int i=0;i<n;++i){
        if(!v[i]){
            ++cnt;
            vis(i,arr[i]);
        }
    }
    cout<<cnt<<'\n';
}