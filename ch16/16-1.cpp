#include<bits/stdc++.h>
#define pii pair<int,int>
#define s first
#define e second

using namespace std;

int n;
pii arr[10005];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i].s>>arr[i].e;
    sort(arr,arr+n,[](pii a,pii b){
        if(a.s==b.s)return a.e<b.e;
        return a.s<b.s;
    });

    int a=arr[0].s,b=arr[0].e,ans=0;
    for(int i=1;i<n;++i){
        if(arr[i].s<b)b=max(arr[i].e,b);
        else ans+=b-a,a=arr[i].s,b=arr[i].e;
    }
    ans+=b-a;
    cout<<ans<<'\n';
}