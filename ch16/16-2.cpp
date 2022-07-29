#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define w first
#define f second
using namespace std;

int n;
pii arr[100005];

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i].w;
    for(int i=0;i<n;++i)cin >>arr[i].f;

    sort(arr,arr+n,[](pii a,pii b){
        return a.w*b.f<a.f*b.w;
    });

    int weight=0,ans=0;
    for(int i=0;i<n-1;i++){
        weight+=arr[i].w;
        ans+=weight*arr[i+1].f;
    }
    cout<<ans<<'\n';
}