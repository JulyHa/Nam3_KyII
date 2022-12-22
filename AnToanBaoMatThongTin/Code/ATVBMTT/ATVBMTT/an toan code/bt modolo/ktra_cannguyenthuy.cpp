#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int kt(long n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return 0;
	}
	return 1;
}
void euler(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(n%i==0&& kt(i))
		{
			v.push_back(i);
			while(n%i==0)
			{
				n/=i;
			}
		}
	}
}
int euler_modolo(int n)
{
	double kq;
	if(kt(n)){
		kq = n-1;
	}
	else{
		euler(n);
		kq=n;
		for(auto i: v)
		{
			kq*=(1-(double)1/i);
		}
	}
	return kq;
}
int binhphuong(int a,int m,int n){
	int res =1,nho=a;
	long kq;
	while(1)
	{
		int mu = m/2;
		if(mu==0) break;
		
		if(m%2)
		{
			res = (res*nho)%n;
		} 
		kq = a*a % n;
		m/=2;
				
		a = kq;

	}
	return (a*res)%n;
}
int main(){
	int a,n;
	cout<<"Nhap a: "; cin>>a;
	cout<<"Nhap n: "; cin>>n;
	vector<int> M;
	for(int i=2;i<euler_modolo(n);i++)
	{
		if(n%i==0) M.push_back(i);
	}
	for(auto i : M)
	{
		if(binhphuong(a,i,n)==1){
			cout<<"a ko phai can nguyen thuy";
			return 0;
		}
	}
	cout<<"a la can nguyen thuy";

	
}

