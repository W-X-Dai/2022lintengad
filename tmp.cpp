#include<bits/stdc++.h>
using namespace std;

int n,m;

inline void sol(){
    int a[105],b[105],dp[105][105]={0};
    
    for(int i=0;i<n;++i)cin >>a[i];
    for(int i=0;i<m;++i)cin >>b[i];

    for(int i=1;i<n;++i){
        for(int j=1;j<m;++j){
            if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n-1][m-1]<<'\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>n>>m && n && m)sol();
    return 0;
}