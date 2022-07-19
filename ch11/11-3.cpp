#include<bits/stdc++.h>
using namespace std;

int arr[1005][2];

inline void sol(){
    int n,cnt=0;

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i][0]>>arr[i][1];

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(arr[i][0]==arr[j][1] && arr[j][0]==arr[i][1]){
                if(arr[i][0]!=-1 && arr[j][0]!=-1){
                    ++cnt;
                    arr[i][0]=-1;
                    arr[j][0]=-1;
                }
            }
        }
    }
    cout<<cnt<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;cin >>t;
    while(t--)sol();
    return 0;
}