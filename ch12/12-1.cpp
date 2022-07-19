#include<bits/stdc++.h>
#define int long long
#define inf 2147483647
using namespace std;

int t,id;

inline void sol(){
    int arr[100],mx=-0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<t;++i)cin >>arr[i];
    
    for(int i=0;i<t;++i){
        int tmp=1;
        for(int j=i;j<t;++j){
            int tmp=1;
            for(int k=i;k<=j;++k){
                tmp*=arr[k];
            }
            mx=max(mx,tmp);
        }
    }
    if(mx<0)mx=0;
    cout<<"Case #"<<id<<": The maximum product is "<<mx<<".\n";

}

signed main(){
     ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>t)++id,sol();
    return 0;
}