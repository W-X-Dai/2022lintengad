#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
int field[105][105];
int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};

inline void bfs(int x,int y){
    field[x][y]=-1;
    for(int i=0;i<8;++i){
        int dx=dir[i][0],dy=dir[i][1];
        if(field[x+dx][y+dy]==2)bfs(x+dx,y+dy);
    }
}

inline void sol(){
    cnt=0;
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            char x;cin >>x;
            field[i][j]=1+(bool)(x=='@');
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(field[i][j]==2){
                ++cnt;
                bfs(i,j);
            }
        }
    }
    cout<<cnt<<'\n';
    
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0); 
    while(cin >>m>>n && m && n)sol();
    return 0;
}