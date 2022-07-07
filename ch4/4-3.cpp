#include <iostream>
using namespace std;
 
int n,m,t;
int field[505][505],x1,y1,x2,y2,x,y,ans;

/*
其實這一題也沒什麼技術含量，就是模擬一下種樹就好了。開一個陣列field紀錄該座標是否有種樹，接著依據題目給的敘述去修改field陣列
比較麻煩的地方在於壓行，直接做肯定是沒問題的，不過行數會多很多，仔細觀察規律，可以儘可能減少程式碼的行數。
*/

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    
    cin >>n>>m>>t;
    while(t--){
        cin>>x1>>y1>>x2>>y2;
        if(x2>x1)x=1;
        else if(x1==x2)x=0;
        else x=-1;
        
        if(y2>y1)y=1;
        else if(y1==y2)y=0;
        else y=-1;

        for(int i=max(abs(x1-x2),abs(y1-y2));i>=0;--i){
            if (field[x1][y1]==0){
                field[x1][y1]=1;
                ++ans;
            }
            y1+=y,x1+=x;
        }
    }
    cout<<ans<<'\n';
}