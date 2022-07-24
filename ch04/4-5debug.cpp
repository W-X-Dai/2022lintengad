#include <bits/stdc++.h>
using namespace std;
string A[5]={
    "abcde",
    "fghij",
    "klmno",
    "prstu",
    "vwxyz"
};

string B[5]={
    "EXAMP",
    "LBCDF",
    "GHIJK",
    "NORST",
    "UVWYZ"
};

void encode(string s){
  int a,b,c,d;
  for(int l=0;l<s.size();l+=2){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(A[i][j]==s[l]){
          a=i;b=j;
        }
        if(A[i][j]==s[l+1]){
          c=i;d=j;
        }
      }
    }
    cout<<B[a][d]<<B[c][b];
  }
}

void decode(string s){

  int a,b,c,d;
  for(int l=0;l<s.size();l+=2){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        if(B[i][j]==s[l])
          a=i,b=j;
        if(B[i][j]==s[l+1])
          c=i,d=j;
      }
    }
    cout<<A[c][b]<<A[a][d];
  }
}

int main(){
  string str;int x;
  cin>>x>>str;
  reverse(str.begin(),str.end());
  if(islower(str[0]))
    encode(str);
  else
    decode(str);
  
}