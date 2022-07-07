#include<bits/stdc++.h>
using namespace std;

int cnt;
//基本參考：https://hackmd.io/@apcsd3d4/r1JtpJFiI#/
//basic hanio tower:http://infor.ylsh.ilc.edu.tw/problem/76
inline void hanio(int n,char from,char to,char mid){
//    ++cnt;
    if(n<=0)return;
    hanio(n-1,from,mid,to);
    ++cnt;
    cout<<"ring "<<n<<" : "<<from<<" => "<<to<<'\n';
    hanio(n-1,mid,to,from);
}

void distribute(int n,char from,char to,char mid){
    if(n<=0)return;
    
    hanio(n-1,from,mid,to);
    cout<<"ring "<<n<<" : "<<from<<" => "<<to<<'\n';
    ++cnt;
    distribute(n-2,mid,from,to);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;

    cin >>n;
    // for(int i=0;i<n;i+=3){
    //     hanio(n-i-1,'A','B','C');cout<<'\n';
    //     ++cnt;
    //     cout<<"ring "<<n-i<<" : A => C"<<'\n';
    //     hanio(n-2-i,'B','A','C');cout<<'\n';
    // }    
    distribute(n,'A','C','B');


    cout<<"共需"<<cnt<<"個移動"<<'\n';
}