#include<bits/stdc++.h>
using namespace std;
int convert_l=0;

bool check(string str){
    for(int j=0;j<str.size();j++){
            if(str[j]!='0' && str[j]!='1')
                return false;
    }
    return true;
}

void output(int cnt){
    for(int l=2;l>=0;l--){
        int a=cnt/pow(2,l);
        cout<<a;
        cnt-=pow(2,l)*a;
    }
    cout<<" ";
    convert_l++;
}   

int main(){
    ios::sync_with_stdio(0),cin.tie(0);

    int n;
    cin>>n;cin.ignore();
    while(n--){
        convert_l=0;
        string str;
        getline(cin,str);
        if(check(str)==false)
            cout<<"-1\n";
        else{
            int cnt=1;
            for(int j=1;j<str.size();j++){
                
                if(str[j]==str[j-1] && cnt<7)
                    cnt++;
                    
                else{
                    cout<<str[j-1];
                    output(cnt);
                    cnt=1;
                }

                if(j==str.size()-1){
                    cout<<str[str.size()-1];
                    if(cnt==1){
                        cout<<"001 ";
                        convert_l++;
                        }
                    else
                        output(cnt);
                }
                
            }
            double rate=(double)convert_l/(double)str.size()*400;
            cout<<llround(rate)<<"%\n";        //這會有floating point exception的問題，但是我不清楚為甚麼？？
        }
    }

    return 0;
}