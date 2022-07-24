#include<bits/stdc++.h>
using namespace std;

int n,p,dir;

/*
本題在東區的題目中算是比較沒那麼噁心的一類了，只花了大概十來分鐘。
較為複雜的點有兩個（我猜啦）第一個就是整數混和字元的輸入，第二個是如何分散紀錄每個人的狀況
以下分別敘述：
1.關於輸入
就...直接開個四格的字串陣列，用來除存
每次判斷當前的字串是否為特殊字元等等，如果是整數就用stoi函數來將之轉換
2.關於分散紀錄
開個struct，分開紀錄每個人的牌和用到第幾張牌
*/

struct st{
    string c[15];
    int id;
}arr[4];

inline void next(){
    p+=dir;
    if(p>3)p=0;
    if(p<0)p=3;
}

inline void func(string x){
//    cout<<p<<" "<<x<<'\n';
    if(x=="A")n=0;
    else if(x=="10")(n>89 ? n-=10 : n+=10);
    else if(x=="Q")(n>79 ? n-=20 : n+=20);
    else if(x=="K")n=99;
    else if(x=="4")dir=-dir;
    else if(x=="5" || x=="J");
    else{
        n+=stoi(x);
    }
}

int main(){
//    ios::sync_with_stdio(0),cin.tie(0);
    
    for(int i=0;i<4;++i){
        arr[i].id=1;
        for(int j=0;j<14;++j){
            cin >>arr[i].c[j];
        }
    }
    dir=1,p=0;
    while(1){
        int id=arr[p].id;
        func(arr[p].c[id]);
        ++arr[p].id;
        if(n>99){
            cout<<(char)('A'+p)<<'\n'<<13-id<<'\n';
            return 0;
        }
        if(arr[p].id>13){
            cout<<(char)('A'+p)<<'\n'<<n<<'\n';
            return 0;
        }
        next();
    }

}