#include<bits/stdc++.h>
using namespace std;

void output(int cnt){
  for(int l=2;l>=0;l--){
    int a=cnt/pow(2,l);
    cout<<a;
    cnt-=pow(2,l)*a;
  }
  cout<<" ";
}

int main(){
    ifstream f("text");
    string s;
    cout<<1;
    while(getline(f,s)){
        cout<<s;
    }
}