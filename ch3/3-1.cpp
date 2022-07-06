#include<bits/stdc++.h>
using namespace std;

int f[30];

/*
簡簡單單的遞迴基本題。不過我這邊用了一個動態規劃的技巧，將已經求過值的項次記錄下來，
下次在詢問時直接回傳之前的結果即可。(有開io加速時while(cin >>x)會到結束的時候才
進行optput，按下ctrl+c可以結束，如果是vscode要測試執行記得把io加速關掉，因為他)
*/

inline int fib(int x){
    if(x==0)return 0;
    if(x==1)return 1;
    if(f[x])return f[x];
    f[x]=fib(x-1)+fib(x-2);
    return f[x];
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int x;
    while(cin >>x)
        cout<<fib(x)<<'\n';

}