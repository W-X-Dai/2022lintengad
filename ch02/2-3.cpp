#include<bits/stdc++.h>
using namespace std;

int arr[6][6],mp[6][6];
int x,ans,acnt;


/*
這一題呢，概念很簡單，但是有非常多的細節要處理。我先用二維陣列arr儲存每個座標的值，
再開另一個二維陣列mp配合Find()函式紀錄座標是否有被選過。接下來直接歷遍整個二維陣列，
如果該點沒有被選擇過，那就用det()檢查「在該點被選擇的狀況下之分數」。acnt紀錄的是當前答案的分數，
ans紀錄當前的答案。由於有可能一條線都連不出來，因此acnt最開始應設定為-1，讓答案最小化。
至於判斷方面，因為每個被檢查的座標都是沒有被選擇過的，因此只要檢查與該點相同x,y座標
之mp總值即可。如果可以連線，總值必為4
*/
inline void Find(int x){
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(arr[i][j]==x){
                mp[i][j]=1;
                return;    
            }
        }
    }
}

inline int det(int x,int y){
    int cnt=0,tmp=0;
    for(int i=1;i<=5;++i){
        tmp+=mp[i][y];
    }
    if(tmp==4)++cnt;

    tmp=0;
    for(int i=1;i<=5;++i){
        tmp+=mp[x][i];
    }
    if(tmp==4)++cnt;

    if(x==y){
        tmp=0;
        for(int i=1;i<=5;++i)tmp+=mp[i][i];
        if(tmp==4)++cnt;
    }
    if(x==6-y){
        tmp=0;
        for(int i=5;i>=1;--i)tmp+=mp[i][6-i];
        if(tmp==4)++cnt;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    ans=1,acnt=-1;
    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            cin >>arr[i][j];
        }
    }

    while(cin >>x){
        if(x==-1)break;
        Find(x);
    }

    for(int i=1;i<=5;++i){
        for(int j=1;j<=5;++j){
            if(mp[i][j])continue;
        //    cout<<i<<" "<<j<<" "<<det(i,j)<<'\n';
            if(det(i,j)==acnt)ans=min(ans,arr[i][j]);
            if(det(i,j)>acnt)ans=arr[i][j],acnt=det(i,j);
        }
    }
    cout<<ans<<'\n';
}