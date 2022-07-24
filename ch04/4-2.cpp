#include<bits/stdc++.h>
using namespace std;

int n,arr[104][104];

//這一題難度接近是東區學科賽上午場前三題（現在知道東區學科賽有多水了吧X）
//簡單講，紀錄好整張表格之後，分別計算每一欄和每一列的總值
//如果某一列的總值為奇數，將其紀錄在changex中，如果changex不為零（代表有另一列亦是奇數），那很顯然這組的答案是corrupt
//用相同的方法處理每一欄，最後得到結果
//就這麼簡單：P

inline void count(){
    int row[105],col[105];
    int changex=0,changey=0;

    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            row[i]+=arr[i][j];
            col[j]+=arr[i][j];
        }
    }
    for(int i=1;i<=n;++i){
        if(row[i]%2){
            if(changex){
                cout<<"Corrupt\n";
                return;
            }
            changex=i;
        }
        if(col[i]%2){
            if(changey){
                cout<<"Corrupt\n";
                return;
            }
            changey=i;
        }
    
    }

    if(!changex && !changey)cout<<"OK\n";
    else cout<<"Change bit ("<<changex<<","<<changey<<")\n";
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    while(cin >>n && n){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cin >>arr[i][j];
            }
        }
        count();
    }
}