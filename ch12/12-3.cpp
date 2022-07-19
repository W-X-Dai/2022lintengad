#include<bits/stdc++.h>
using namespace std;

int n;

inline bool det(int a,int b){
    string s1=to_string(a),s2=to_string(b);

    if(s1.size()>5 || s2.size()>5)return 0;

    int arr[10]={0};

    if(s1.size()<5)arr[0]+=5-s1.size();
    if(s2.size()<5)arr[0]+=5-s2.size();

    for(auto i:s1)++arr[i-'0'];
    for(auto i:s2)++arr[i-'0'];
    
    for(auto i:arr)if(i!=1)return 0;
    return 1;
}

inline void sol(){
    int num=0;

//    for(int i=1;i<100000;++i){
        int i=1283;
        int j=n*i;
        if(det(i,j)){
            cout<<setw(5)<<setfill('0')<<j<<" / "<<i<<" = ";
            cout<<n<<'\n';
            ++num;
        }
//    }

    if(!num)cout<<"There are no solutions for "<<n<<".\n";
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>n && n)sol();
    return 0;
}