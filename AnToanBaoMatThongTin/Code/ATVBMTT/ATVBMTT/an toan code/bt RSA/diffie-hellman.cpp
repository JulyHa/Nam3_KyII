#include<bits/stdc++.h>
using namespace std;
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
	int q,a;
	cout<<"Nhap q: "; cin>>q;
	cout<<"Nhap a: "; cin>>a;
	
	int xa,xb,ya,yb,ka,kb;
	cout<<"Nhap XA: "; cin>>xa;
	cout<<"Nhap XB: "; cin>>xb;
	
	ya = binhphuong(a,xa,q);
	yb = binhphuong(a,xb,q);
	
	ka = binhphuong(yb,xa,q);
	kb = binhphuong(ya,xb,q);
	
	cout<<"Gia tri YA: "<<ya<<'\n';
	cout<<"Gia tri YB: "<<yb<<'\n';
	cout<<"Gia tri KA: "<<ka<<'\n';
	cout<<"Gia tri KB: "<<kb<<'\n';
}

