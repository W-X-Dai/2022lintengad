#include<bits/stdc++.h>
using namespace std;

int mp[25][5][5],arr[16],n,suc;
char id[25];

inline bool det(int k,int x,int y){
    int tmp=0;
    for(int i=1;i<=4;++i){
        tmp=0;
        for(int j=1;j<=4;++j){
            tmp+=mp[k][i][j];
        }
        if(!tmp){
            cout<<id[k]<<" ";
            return 1;
        }
    }
    for(int i=1;i<=4;++i){
        tmp=0;
        for(int j=1;j<=4;++j){
            tmp+=mp[k][j][i];
        }
        if(!tmp){
            cout<<id[k]<<" ";
            return 1;
        }
    }
    if(x==y){
        tmp=0;
        for(int i=1;i<=4;++i){
            tmp+=mp[k][i][i];
        }
        if(!tmp){
            cout<<id[k]<<" ";
            return 1;
        }        
    }
    if(x+y==5){
        tmp=0;
        for(int i=1;i<=4;++i){
            tmp+=mp[k][i][5-i];
        }
        if(!tmp){
            cout<<id[k]<<" ";
            return 1;
        }  
    }
    return 0;
}

inline void Find(int k,int x){
    for(int i=1;i<=4;++i){
        for(int j=1;j<=4;++j){
            if(mp[k][i][j]==x){
                mp[k][i][j]=0;
                if(det(k,i,j)){
                    suc=1;
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>id[0]>>n;
    for(int k=1;k<=n;++k){
        cin >>id[k];
        for(int i=1;i<=4;++i){
            for(int j=1;j<=4;++j){
                cin >>mp[k][i][j];
            }
        }
    }
    cin >>id[0];

    for(int i=0;i<16;++i)cin >>arr[i];
    for(int i=0;i<16;++i){
        cout<<arr[i]<<" ";
        for(int k=1;k<=n;++k)Find(k,arr[i]);
        if(suc)return 0;
    }
}