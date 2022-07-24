#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> ope;
	string s;
	int i,l,a,b;
	char x;
	
	while(cin >>s){
		l=s.size();
		for(i=0;i<l;i++){
			x=s[i];
			if(x>=48 and x<=57)ope.push(x-48);
			if(x=='/'){
				b=ope.top(),ope.pop();
				a=ope.top(),ope.pop();
				ope.push(a/b);
			}
			if(x=='*'){
				b=ope.top(),ope.pop();
				a=ope.top(),ope.pop();
				ope.push(a*b);
			}
			if(x=='+'){
				b=ope.top(),ope.pop();
				a=ope.top(),ope.pop();
				ope.push(a+b);
			}
			if(x=='-'){
				b=ope.top(),ope.pop();
				a=ope.top(),ope.pop();
				ope.push(a-b);
			}
			if(x=='%'){
				b=ope.top(),ope.pop();
				a=ope.top(),ope.pop();
				ope.push(a%b);
			}									
		}
		cout<<ope.top()<<'\n';
		ope.pop();
		s.clear();
	}
	
}
