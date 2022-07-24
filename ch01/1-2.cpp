#include<bits/stdc++.h>
using namespace std;

int n,score[105],x;

//計數排序法：因為分數的值僅在0~100之間，因此開一個大小略大於101的陣列，score[i]的值代表有幾個分數為i
//接下來由小到大歷遍陣列即可
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    
    cin >>n;
    for(int i=0;i<n;++i){
        cin >>x;
        score[x]++;
    }
    int mi=101,mx=-1;
    for(int i=60;i<=100;++i){
        if(score[i]){
            mi=i;
            break;
        }
    }
    for(int i=59;i>=0;--i){
        if(score[i]){
            mx=i;
            break;
        }
    }
    for(int i=0;i<=100;++i){
        while(score[i]--)cout<<i<<" ";
    }
    cout<<'\n';
    
    if(mx==-1)cout<<"best case\n";
    else cout<<mx<<'\n';

    if(mi==101)cout<<"worst case\n";
    else cout<<mi<<'\n';
}