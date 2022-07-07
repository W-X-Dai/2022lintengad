#include<bits/stdc++.h>
using namespace std;

int tower(int n,char from,char to,char mid){
    if(n==1){
        cout<<"ring 1 : "<<from<<" => "<<to<<'\n';
        return;
    }
    if(n%3==0){
        tower(n-1,from,mid,to);
        cout<<"ring "<<n<<" : "<<from<<" => "<<to<<'\n';
        tower(n-1,mid,to,from);
    }
}

int main(){

}