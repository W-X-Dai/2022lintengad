#include <iostream>
#include <math.h>
#define SWAP(x,y) {int t; t=x; x=y; y=t;}
using namespace std;
 
int field[500][500]={0};
int x,y;
int lines;
 
void dump_data(){
    int ans=0;
    for(int i=0;i<y;i=i+1){
        for(int j=0;j<x;j=j+1){
            if(field[i][j]==1){
                ans=ans+1;
            }
        }
    }
    cout<<ans;
}
 
void counted(int x1,int y1,int x2,int y2){
    if(y1==y2){
        if(x1>x2){
            SWAP(x1,x2);
        }
        for(int i=x1;i<=x2;i=i+1){
            field[y1][i]=1;
        }
    }
    else if(x1==x2){
        if(y1>y2){
            SWAP(y1,y2);
        }
        for(int i=y1;i<=y2;i=i+1){
            field[i][x1]=1;
        }
    }
    else if((x1-x2)/(y1-y2)==-1){
        if(y1>y2){
            SWAP(y1,y2);
            SWAP(x1,x2);
        }
        int temp=x1;
        for(int i=y1;i<=y2;i=i+1){
            field[i][temp]=1;
            temp=temp-1;
        }
    }
    else if((x1-x2)/(y1-y2)==1){
        if(y1>y2){
            SWAP(y1,y2);
            SWAP(x1,x2);
        }
        int temp=x1;
        for(int i=y1;i<=y2;i=i+1){
            field[i][temp]=1;
            temp=temp+1;
        }
    }
}
 
int main(){
    cin>>x>>y;
    cin>>lines;
    int x1,y1,x2,y2;
    for(int i=0;i<lines;i=i+1){
        cin>>x1>>y1>>x2>>y2;
        counted(x1-1,y1-1,x2-1,y2-1);
    }
    dump_data();
    return 0;
}