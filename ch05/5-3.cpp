#include<bits/stdc++.h>
using namespace std;

string s;

inline void num(double a,double b){
    b*=100;
    cout<<round(b/a)<<"%"<<'\n';
}

inline void sol(){
    string hash[8]={"","001","010","011","100","101","110","111"};

    for(auto i:s)if(i!='0' && i!='1'){
        cout<<"-1"<<'\n';
        return;
    }
    int cnt=1,blocks=1;
    for(int j=1;j<s.size();++j){
    //    slow();
        if(s[j]==s[j-1] && cnt<7)++cnt;
        else {
        //    cout<<j<<" "<<cnt<<'\n';
            ++blocks;
            cout<<s[j-1]<<hash[cnt]<<" ";
            cnt=1;
        }
    }
    cout<<*s.rbegin()<<hash[cnt]<<" ";
    num(s.size(),blocks*4);
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    string hash[8]={"","001","010","011","100","101","110","111"};
    
    cin >>n;cin.ignore();
    for(int k=0;k<n;++k){
         getline(cin,s);
         sol();s.clear();
    }
}
