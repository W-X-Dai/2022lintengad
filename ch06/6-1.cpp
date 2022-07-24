#include<bits/stdc++.h>
using namespace std;

struct point{
	double x;
	double y;
};

int main(){
	point arr[100];
	int n,i;
	double area=0.00;
	
	cin >>n;
	for(i=0;i<n;++i){
		cin >>arr[i].x>>arr[i].y;
	}

    for(int i=1;i<n;++i){
		area+=arr[i-1].x*arr[i].y-  
			  arr[i-1].y*arr[i].x;
    }

	area+=arr[n-1].x*arr[0].y-
	 	  arr[0].x*arr[n-1].y;

	area=abs(area)/2.00;
	cout<<setprecision(2)<<fixed<<area<<'\n';
}