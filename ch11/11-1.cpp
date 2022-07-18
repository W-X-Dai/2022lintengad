#include<bits/stdc++.h>
using namespace std;

int n,x;
int arr[100005];

inline void bs(int l,int r,int t){
    cout<<l<<" "<<r<<'\n';
    if(l>r){cout<<"not found "<<t<<'\n';return;}
    int mid=(l+r)/2;

    if(arr[mid]==x){
        cout<<mid<<" "<<t+1<<'\n';
        return;
    }

    if(arr[mid]>x)bs(l,mid-1,t+1);
    else bs(mid+1,r,t+1);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i];
    cin >>x;
    bs(0,n-1,0);
}