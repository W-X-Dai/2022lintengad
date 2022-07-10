#include<bits/stdc++.h>
using namespace std;
int arr[4][80];
char ppl[20],ans[20],aaa=0;

void mark(int m,int n){
    for(int i=0;i<4;i++){
        for(int j=0;j<n*4;j++){
            if(arr[i][j]==m)
                arr[i][j]=0;
        }
    }
}

void clear(int l){
    for(int i=0;i<4;i++){
        for(int j=l*4;j<4*(l+1);j++){
            arr[i][j]=-1;
        }
    }
}

bool hor(int n){
    bool sol=0;
    for(int l=0;l<n;l++){
        for(int i=0;i<4;i++){
            int temp=0;
            for(int j=4*l;j<4*(l+1);j++){
                if(arr[i][j]==0)
                    temp++;
            }
            if(temp==4){
                ans[aaa]=ppl[l];aaa++;
                sol=1;
                clear(l);
            }
        }
    }
    return sol;
}

bool ver(int n){
    bool sol=0;
    for(int l=0;l<n;l++){
        for(int j=4*l;j<4*(l+1);j++){
            int temp=0;
            for(int i=0;i<4;i++){
                if(arr[i][j]==0)
                    temp++;
            }
            if(temp==4){
                ans[aaa]=ppl[l];aaa++;
                sol=1;
                clear(l);
            }
        }
    }
    return sol;
}

bool dia_1(int n){
    bool sol=0;
    for(int l=0;l<n;l++){
        int i=0,j=l*4,temp=0;
        while(i<=4 && j<4*(l+1)){
            if(arr[i][j]==0)
                temp++;
            i++;j++;
        }
        if(temp==4){
            ans[aaa]=ppl[l];aaa++;
            sol=1;
            clear(l);
        }
    }
    return sol;
}

bool dia_2(int n){
    bool sol=0;
    for(int l=0;l<n;l++){
        int i=0,j=4*(l+1)-1,temp=0;
        while(i<=4 && j>=4*l){
            if(arr[i][j]==0)
                temp++;
            i++;j--;
        }
        if(temp==4){
            ans[aaa]=ppl[l];aaa++;
            sol=1;
            clear(l);
        }
    }
    return sol;
}

int main(){
    char x;
    int n,p[16];
    cin>>x>>n;
    for(int l=0;l<n;l++){
        cin>>ppl[l];
        for(int i=0;i<4;i++){
            for(int j=l*4;j<4*(l+1);j++){
                cin>>arr[i][j];
            }
        }
    }
    cin>>x;
    for(int i=0;i<16;i++){
        cin>>p[i];
    }
    for(int i=0;i<16;i++){
        mark(p[i],n);
        cout<<p[i]<<" ";
        if(ver(n)==0 && hor(n)==0 && dia_1(n)==0 && dia_2(n)==0)
            continue;
        else{
         for(int j=0;j<n;j++){
             for(int l=0;l<aaa;l++){
                 if(ppl[j]==ans[l])
                     cout<<ppl[j]<<" ";
             }
         }
	 break; 
        }
	}
    return 0;
}