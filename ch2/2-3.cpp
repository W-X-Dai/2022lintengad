#include<bits/stdc++.h>
using namespace std;

int arr[6][6],mp[6][6];
int x,ans,acnt;

//還沒AC 90% qq
inline void Find(int x){
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(arr[i][j]==x){
                mp[i][j]=1;
                return;    
            }
        }
    }
}

inline int det(int x,int y){
    int cnt=0,tmp=0;
    for(int i=1;i<=5;++i){
        tmp+=mp[i][y];
    }
    if(tmp==4)++cnt;

    tmp=0;
    for(int i=1;i<=5;++i){
        tmp+=mp[x][i];
    }
    if(tmp==4)++cnt;

    if(x==y){
        tmp=0;
        for(int i=1;i<=5;++i)tmp+=mp[i][i];
        if(tmp==4)++cnt;
    }
    if(x==6-y){
        tmp=0;
        for(int i=5;i>=1;--i)tmp+=mp[i][6-i];
        if(tmp==4)++cnt;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    ans=1;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            cin >>arr[i][j];
        }
    }

    while(cin >>x){
        if(x==-1)break;
        Find(x);
    }

    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(mp[i][j])continue;
        //    cout<<i<<" "<<j<<" "<<det(i,j)<<'\n';
            if(det(i,j)==acnt)ans=min(ans,arr[i][j]);
            if(det(i,j)>acnt)ans=arr[i][j],acnt=det(i,j);
        }
    }
    cout<<ans<<'\n';
}