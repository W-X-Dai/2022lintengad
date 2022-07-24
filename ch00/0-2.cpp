#include <bits/stdc++.h>
#define inf 2147483647
using namespace std;

int S[51][51],A[51][51];
int n,m,k;

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n>>m>>k;
    for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
            cin >>S[i][j];
        }
    }

    int ans=inf;
    for(int ii=0;ii<k;++ii){
        memset(A,0,sizeof(A));

        for(int i=0;i<n;++i){
            int p;
            cin >>p;
            for(int j=0;j<m;++j)A[p][j]+=S[i][j];
        }

        int sum=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<m;++j) {
                if(i==j)sum+=A[i][j];
                else if(A[i][j]<=1000)sum+=A[i][j]*3;
                else sum+= A[i][j]*2+1000;
            }
        }
        ans=min(ans,sum);
    }
    cout<<ans<<'\n';
}