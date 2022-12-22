#include<bits/stdc++.h>
using namespace std;
int binhphuong(int a,int m,int n){
	int res =1,nho=a;
	long kq;
	while(1)
	{
		int mu = m/2;
		if(mu==0) break;
		
		if(m%2)
		{
			res = (res*a)%n;
		} 
		kq = a*a % n;
		m/=2;
				
		a = kq;

	}
	return (a*res)%n;
}
int nghichdao(int a,int n)
{
	for(int i=2;i<=a+n;i++)
	{
		if((a*i)%n==1) return i;
	}
}
int main(){
	int b,y,n;
	cout<<"Nhap b: ";	cin>>b;
	cout<<"Nhap y: "; cin>>y;
	cout<<"Nhap n: ";	cin>>n;
	
	int s2 = binhphuong(b,y,n);
	cout<<nghichdao(s2,n);
}

