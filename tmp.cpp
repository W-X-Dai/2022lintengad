#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
using namespace std;

int n,inf=0x3f3f3f3f3f3f3f3f,tmp[200005];
pii arr[200005];

inline bool cmp(int a,int b){
    return arr[a].y<arr[b].y;
}

inline int dist(pii a,pii b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

inline int divi(int l,int r){
    if(l==r)return inf;
    if(r-l==1)return dist(arr[l],arr[r]);

    int mid=(l+r)>>1;
    int ans=min(divi(l,mid),divi(mid+1,r));

    int cnt=0;
    for(int i=l;i<=r;++i){
        if(arr[i].x>=arr[mid].x-ans && arr[i].x<=arr[mid].x+ans){
            tmp[++cnt]=i;
        }
    }
    
    sort(tmp+1,tmp+1+cnt,cmp);
    for(int i=1;i<=cnt;++i){
        for(int j=i+1;j<=cnt;++j){
            if(arr[tmp[j]].y>arr[tmp[i]].y+ans)break;
            ans=min(ans,dist(arr[tmp[j]],arr[tmp[i]]));
        }
    }

    return ans;
}

inline void sol(){

    for(int i=0;i<n;++i)cin >>arr[i].x>>arr[i].y;
    sort(arr,arr+n,[](pii a,pii b){
        return a.x<b.x;
    });
    cout<<divi(0,n-1)<<'\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    cin >>n;sol();
    return 0;
}