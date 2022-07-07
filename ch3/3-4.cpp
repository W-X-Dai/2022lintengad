#include<bits/stdc++.h>
using namespace std;

int k,target,ok;
int pre[65537],num[5];

inline void init(){
    for(int i=1;i<=65536;++i)pre[i]=i*i;
}

inline void pick(int id,int rest){
    if(id==3){
        int tmp=sqrt(rest);
        if(pre[tmp]==rest){
            for(int i=1;i<=4;++i){
                ok=1;
                cout<<num[i]<<" \n"[i==4];
                return;
            }
        }
        return;
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >>k;target=1<<k;
    pick(1,target);
    if(!ok)cout<<0<<'\n';    
}