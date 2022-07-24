#include<bits/stdc++.h>
using namespace std;

int n,arr[90];

/*
過於邪惡的大數運算：參加了幾十場比賽就沒有看過這東西，真不懂為何考出來...(python秒殺欸)
觀察題目會發現本題需要計算(4^n-1)/3的值，n<=120
我們可以做以下的估算：(4^n-1)/3 > (4^n-1)/4約等於4^(n-1)=2^(2n-2)
而c++中整數型態別最多可除存到2^63-1(long long)，因此直接使用long long或int必定會overflow

由於大數運算較為複雜，因此將其寫成函式。inline代表「函式內展開」，可省一點點空間和時間
*/
inline void show(){
	int i=80;
	for(i=80;i>0;--i){
		if(arr[i])break;
	}
	for(;i>0;--i)cout<<arr[i];
	cout<<'\n';
}

inline void power(int x){
	arr[1]=1;
	while(x--){
		for(int i=1;i<=75;++i){
			arr[i]*=4;
		}
		for(int i=1;i<=75;++i){
			arr[i+1]+=arr[i]/10;
			arr[i]%=10;
		}
	}
	--arr[1];
}

inline void divid(){
	for(int i=75;i>0;--i){
		if(!arr[i]%3)arr[i]/=3;
		else {
			arr[i-1]+=10*(arr[i]%3);
			arr[i]/=3;
		}
	}
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cin >>n;
	power(n);
	divid();
	show();
}