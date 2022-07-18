#include <iostream>
#include <cmath>
using namespace std;
int a[100],k,b;
int f(){
	b=0;
	long long t=a[k-1];
	for(int i=k-2;i>=0;i--) t=10*t+a[i];
	long long x=sqrt(t);
	if(x*x==t) b=1;
	return b;
}
void g(){
	for(int i=0;i<k;i++){
		if(a[i]>8){
			a[i+1]+=2*(a[i]/10);
			a[i]=0;
		} 
	}
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		k=0;
		cin>>k;
		for(int i=0;i<100;i++) a[i]=0;
		a[k-1]=2;
		f();
		while(b!=1){
			a[0]+=2;
			g();
			f();
		} 
		for(int i=k-1;i>=0;i--){
			cout<<a[i];
		}
		cout<<'\n';
	}
	return 0;
}