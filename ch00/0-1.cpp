#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,d,ma,mi,x,ave,sum=0,cnt=0;

    cin >>n>>d;
    for(int i=0;i<n;++i){
        ma=-1,mi=101,ave=0;
        for(int j=0;j<3;++j){
            cin >>x;ave+=x;
            mi=min(mi,x),ma=max(ma,x);
        }
        ave/=3;
        if(ma-mi>=d){
            ++cnt;
            sum+=ave;
        }
    }
    cout<<cnt<<" "<<sum<<'\n';
}