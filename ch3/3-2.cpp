#include<bits/stdc++.h>
using namespace std;

int n;

/*
沒什麼好說的，這題就這樣。喔然後他是UVa上面的題目，所以輸出格式很怪，當初我想在上面
刷題結果因為輸出格式太奇怪放棄了XD
仔細觀察數學規律會發現F91()的結果
我也懶得再開陣列用dp的技巧優化了，再怎麼快都不會有F91()直接計算來得快
*/

inline int f91(int x){
    if(x<=100)return f91(f91(x+11));
    else return x-10;
}

inline int F91(int x){
    if(x<=100)return 91;
    else return x-10;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>n && n){
        cout<<"f91("<<n<<") = "<<f91(n)<<'\n';
    }
}