#include<bits/stdc++.h>
using namespace std;

string s1[5]={"abcde","fghij","klmno","prstu","vwxyz"};
string s2[5]={"EXAMP","LBCDF","GHIJK","NORST","UVWYZ"};
string s;

inline void Find1(char a,char b){
    int x1,y1,x2,y2;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(s1[i][j]==a)x1=i,y1=j;
            if(s1[i][j]==b)x2=i,y2=j;
        }
    }
    cout<<s2[x1][y2]<<s2[x2][y1];
}

inline void Find2(char a,char b){
    int x1,y1,x2,y2;
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            if(s2[i][j]==a)x1=i,y1=j;
            if(s2[i][j]==b)x2=i,y2=j;
        }
    }
    cout<<s1[x1][y2]<<s1[x2][y1];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin >>n>>s;

    reverse(s.begin(),s.end());
    if(s[0]>'Z'){
        for(int i=0;i<n;i+=2){
            Find1(s[i],s[i+1]);
        }
    }
    else{
        for(int i=0;i<n;i+=2){
            Find2(s[i],s[i+1]);
        }
    }
    cout<<'\n';
}