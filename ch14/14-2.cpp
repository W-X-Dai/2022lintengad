#include<bits/stdc++.h>
using namespace std;

int mp[9][9],ans;

inline void init(){
    for(int i=1;i<=8;++i){
        for(int j=1;j<=8;++j){
            cin >>mp[i][j];
        }
    }
}

inline void dfs(int n,int arr[]){
    if(n==9)return;
    int NOTok[9]={0};
    for(int i=1;i<=n;++i){
        int x=arr[i];
        NOTok[x]=1;
        NOTok[x]=1;
    }
}

inline void sol(){
    init();
    int tmp[9]={0};

    for(int i=1;i<=8;++i){
        tmp[1]=i;
        dfs(1,tmp);
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >>t;
    while(t--)sol();
    return 0;
}