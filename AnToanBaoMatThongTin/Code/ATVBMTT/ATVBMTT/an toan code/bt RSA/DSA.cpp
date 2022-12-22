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
	int p,q,h,xa,k;
	int HM = 2;
	cout<<"Nhap p: "; cin>>p;
	cout<<"Nhap q: "; cin>>q;
	cout<<"Nhap h: "; cin>>h;
	cout<<"Nhap xa: "; cin>>xa;
	cout<<"Nhap k: "; cin>>k;
	
	int g = binhphuong(h,(p-1)/q,p);
	
	int y = binhphuong(g,xa,p);
	
	int r = (binhphuong(g,k,p))%p;
	
	int s = (nghichdao(k,q)*((HM+xa*r)%q))%q;
	
	int w = nghichdao(s,q);
	
	int u1 = (HM*w)%q;
	int u2 = (r*w)%q;
	
	int v = ((binhphuong(g,u1,p)*binhphuong(y,u2,p))%p)%q;
	
	cout<<"gia tri v = "<<v<<'\n';
	cout<<"gia tri r = "<<r<<'\n';
	
}

