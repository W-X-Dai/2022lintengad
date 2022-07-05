#include<bits/stdc++.h>
using namespace std;

int n,dis,arr[100005];
int y,m,d;

inline void day(){
    int tmp=arr[0];dis=1;
    for(int i=0;i<n;++i){
        tmp=__gcd(tmp,arr[i]);
        dis*=arr[i];
    }
    dis/=tmp;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    cin >>n;
    for(int i=0;i<n;++i)cin >>arr[i];
    day();

    char x;
    cin >>y>>x>>m>>x>>d;

    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    while(dis>0){
        if((y%4==0 && y%100!=0) || y%400==0)days[2]=29;
        
    }
    

    

}