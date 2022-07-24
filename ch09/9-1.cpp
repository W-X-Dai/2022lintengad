#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

int n,m,a,b,vis[808];
vector<int> v[808];

inline void dfs(int center){
    vis[center]=1;
    for(int i:v[center]){
        if(!vis[i])dfs(i);
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    cin >>n>>m;
    for(int i=0;i<m;++i){
        cin >>a>>b;
        v[a].eb(b),v[b].eb(a);
    }
    cin >>a>>b;
    dfs(a);
    cout<<(vis[b]?"Yes":"No")<<'\n';

}