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
int main(){
	// su dung ct euler(n) = n*(1-1/u1)*(1-1/u2)*...
	long n;
	cout<<"Nhap N:"; cin>>n;
	if(kt(n)){
		cout<<n-1;
		return 0;
	}
	euler(n);
	double kq=n;
	for(auto i: v)
	{
		kq*=(1-(double)1/i);
	}
	cout<<kq;
	
}

