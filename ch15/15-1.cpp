#include<bits/stdc++.h>
using namespace std;

int a,b,id;
int arr1[105],arr2[105],dp[105][105];

inline void sol(){
    
    for(int i=1;i<=a;++i)cin >>arr1[i];
    for(int i=1;i<=b;++i)cin >>arr2[i];

    for(int i=1;i<=a;++i){
        for(int j=1;j<=b;++j){
            if(arr1[i]==arr2[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    cout<<"Twin Towers #"<<++id<<'\n';
    cout<<"Number of Tiles : "<<dp[a][b]<<"\n\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>a>>b && a&& b)sol();
    return 0;
}