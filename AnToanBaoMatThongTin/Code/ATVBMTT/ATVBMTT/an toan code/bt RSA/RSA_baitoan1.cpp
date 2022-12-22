#include<bits/stdc++.h>
using namespace std;
int nghichdao(int a,int n)
{
	for(int i=2;i<=a+n;i++)
	{
		if((a*i)%n==1) return i;
	}
}
int binhphuong(int a,int m,int n)
{
	int res =1,nho=a;
	long kq;
	while(1)
	{
		int mu = m/2;
		if(mu==0) break;
		
		if(m%2)
		{
			res = (res*a)%n;
//			res = (res*nho)%n;
		} 
		kq = a*a % n;
		m/=2;
				
		a = kq;

	}

	return (a*res)%n;
}
int main(){
	int p,q,e,M;
	cout<<"Nhap p: "; cin>>p;
	cout<<"Nhap q: "; cin>>q;
	cout<<"Nhap e: "; cin>>e;
	cout<<"Nhap M: "; cin>>M;
	
	int n = p*q;
	int euler_n = (p-1)*(q-1);
	
	int d = nghichdao(e,euler_n);

	int C = binhphuong(M,d,n);
	int g = binhphuong(C,e,n);
	
	cout<<"PU = {"<<e<<","<<n<<"}\n";
	cout<<"PR = {"<<d<<","<<n<<"}\n";
	cout<<"C = "<<C<<'\n';
	cout<<"M = "<<M;
}

