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
	long a,m,n;
	cout<<"Nhap A:"; cin>>a;
	cout<<"Nhap M:"; cin>>m; 
	cout<<"Nhap N:"; cin>>n;
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
	m = m%(int)kq;
	// binh phuong lien tiep 
	int res =1,nho=a;
	long s;
	while(1)
	{
		int mu = m/2;
		if(mu==0) break;
		
		if(m%2)
		{
			res = (res*nho)%n;
		} 
		s = a*a % n;
		m/=2;
				
		a = s;

	}
	cout<<(a*res)%n;

}

