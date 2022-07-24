#include <bits/stdc++.h>
using namespace std;

struct number{
    int num;
    int t;
};

int main(){
    int n;
    while(cin>>n && n!=0){
        int sol=0;
        vector<int> repeat;
        for(int i=1234;i<=98765;i++){
            repeat.clear();
            bool s1=true;
            int ii=i;
            int m=0;
            while(ii>0){
                int b=ii%10;
                ii/=10;
                for(int j=0;j<repeat.size();j++){
                    if(repeat[j]==b){
                        s1=false;
                        break;
                    }
                }
                if(s1) repeat.push_back(b);
                else break;
                m++;
            }
            long long res=n*i;
            long long result=res;
            if(res<100000){
                if(i<10000) repeat.push_back(0);
                vector<int> v;
                int x=0;
                bool s2=true;
                while(res>0){
                    int a=res%10;
                    res/=10;
                    for(int j=0;j<repeat.size();j++){
                        if(repeat[j]==a){
                            s2=false;
                            break;
                        }
                    }
                    if (s2) repeat.push_back(a);
                    else break;
                    x++;
                }
                if(s1 && s2){
                    sol+=1;
                    cout<<result<<" / "<<setw(5)<<setfill('0')<<i<<" = "<<n<<endl;
                }
            }
        }
        if(sol==0) cout<<"There are no solutions for "<<n<<"."<<endl;
    }
}