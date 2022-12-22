#include<bits/stdc++.h>
using namespace std;
int main(){
	long a,n;
	cout<<"Nhap a:"; cin>>a;
	cout<<"Nhap n:"; cin>>n;
	
	long x1 =0 ,y1=1,x2=1,y2=0,q,du=INT_MAX;
	int nho_n = n;
	while(1)
	{
		int n1,n2;
		
		q = n/a;
		du = n%a;
		
		if(du==0) break;
		
		n = a; a = du;
		
		n1 = y1 - q*y2;
		n2 = x1 - q*x2;
		
		y1 = y2; x1 = x2;
		y2 = n1; x2 = n2;
								
	}
	if(x2 < 0) x2+=nho_n;
	cout<<y2<<' '<<x2<<'\n';


}

