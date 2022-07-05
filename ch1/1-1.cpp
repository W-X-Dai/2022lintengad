#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	
	int h1,m1,s1;
	int h2,m2,s2;
	int inf=24*3600,ans;
	char x;
	
	cin >>h1>>x>>m1>>x>>s1;
	cin >>h2>>x>>m2>>x>>s2;
	
	s1+=m1*60+h1*3600;
	s2+=m2*60+h2*3600;
	
	int t;
	if(s1>s2)t=inf-s1+s2;
	else t=s2-s1;
	
	ans=t/3600;
	if(ans<10)cout<<0<<ans<<":";
	else cout<<ans<<":";
	t-=(t/3600)*3600;
	
	ans=t/60;
	if(ans<10)cout<<0<<ans<<":";
	else cout<<ans<<":";
	t-=(t/60)*60;
	
    ans=t;
	if(ans<10)cout<<0<<ans<<'\n';
	else cout<<ans<<'\n';
}

