#include<bits/stdc++.h>
using namespace std;

int n,x,mp[25][5][5],p[16],win[25];
char id[25];

inline void det(int k,int x,int y){
//    cout<<":"<<k<<" "<<x<<" "<<y<<'\n';
    int tmp=0;
    for(int i=1;i<=4;++i){
        tmp+=mp[k][i][y];
    }
    if(!tmp){
        win[0]=1,cout<<id[k]<<" ";
        return;
    }
    tmp=0;
    for(int i=1;i<=4;++i){
        tmp+=mp[k][x][i];
    }
    if(!tmp){
        win[0]=1,cout<<id[k]<<" ";
        return;
    }
    if(x==y){
        tmp=0;
        for(int i=1;i<=4;++i)tmp+=mp[k][i][i];
        if(!tmp){
            win[0]=1,cout<<id[k]<<" ";
            return;
        }
    }
    if(x==5-y){
        tmp=0;
        for(int i=4;i>=1;--i)tmp+=mp[k][i][5-i];
        if(!tmp){
            win[0]=1,cout<<id[k]<<" ";
            return;
        }
    }

    
}

inline void Find(int k,int x){
    for(int i=1;i<=4;++i){
        for(int j=1;j<=4;++j){
            if(mp[k][i][j]==x){
                mp[k][i][j]=0;
                det(k,i,j);
            }
        }
    }
}

int main(){
//    ios::sync_with_stdio(0),cin.tie(0);

    cin >>id[0]>>n;
    for(int k=1;k<=n;++k){
        cin >>id[k];
        for(int i=1;i<=4;++i){
            for(int j=1;j<=4;++j){
                cin >>mp[k][i][j];
            }
        }
    }cin >>id[0];
    for(int i=0;i<16;++i)cin >>p[i];
    for(int i=0;i<16;++i){
        cout<<p[i]<<" ";
        for(int k=1;k<=n;++k)Find(k,p[i]);
        if(win[0])return 0;
    }
    
}