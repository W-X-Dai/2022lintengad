#include<bits/stdc++.h>
using namespace std;

string s,x;
stringstream ss,sss;
int w[1005],v[1005],dp[1000005];
int n,m;


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    getline(cin,s);
    ss<<s;
    while(ss>>x){
        w[n]=stoi(x);
        ++n;
    }

    getline(cin,s);
    sss<<s;

    n=0;
    while(sss>>x){
        v[n]=stoi(x);
        n++;
    }
    cin >>m;

    for(int i=0;i<=n;++i){
        for(int j=m;j>=w[i];--j){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[m]<<'\n';

}