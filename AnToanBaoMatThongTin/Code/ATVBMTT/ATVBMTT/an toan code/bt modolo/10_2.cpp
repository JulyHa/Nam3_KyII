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
	int a,b,x,y,n;
	cout<<"Nhap a,b: ";	cin>>a>>b;
	cout<<"Nhap x,y: "; cin>>x>>y;
	cout<<"Nhap n: ";	cin>>n;
	
	int s1 = binhphuong(a,x,n);
	int s2 = binhphuong(b,y,n);
	int kq = (s1-s2)%n;
	cout<<nghichdao(abs(kq),n);
}

