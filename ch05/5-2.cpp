#include<bits/stdc++.h>
using namespace std;

/*
又是另一題懶得重新寫直接拿去年的AC code來用:p（這題甚至是普通班資訊課的作業欸）
另外，去年在當基礎班助教的時候我也把這題給出出來了XD可想而知，這是個怎樣簡單的題目
少數需要注意的地方：因為他有空格有換行，所以要用getline而不是cin，不然會吃NA(實驗過確實只拿得到10%)
當初我傻傻的跑去背ASCII的表，結果發現直接用強制型態別轉換就可以了
*/

inline char otp(char x){
	if(x>=65 and x<=90){
		if((x-13)<65) return (x+13);
		return (x-13);
	}
	if(x>=97 and x<=122){
		if((x+13)>122) return (x-13);
		return x+13;
	}
	return x;
}

int main(){
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	
	string s;
	
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			cout<<otp(s[i]);
		}
		cout<<'\n';
		
	}
	
}
