#include<bits/stdc++.h>
using namespace std;
int main(){
	long a,m,n;
	cout<<"Nhap a:"; cin>>a;
	cout<<"Nhap m:"; cin>>m;
	cout<<"Nhap n:"; cin>>n;
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

	cout<<(a*res)%n;
}

