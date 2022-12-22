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
int euler_modolo(int a,int m,int n)
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
			res = (res*a)%n;
//			res = (res*nho)%n;
		} 
		s = a*a % n;
		m/=2;
				
		a = s;

	}
	v.clear();
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
	long a,k,n;
	cout<<"Nhap A:"; cin>>a;
	cout<<"Nhap K:"; cin>>k;
	cout<<"Nhap N:"; cin>>n;


	// tinh mi
	euler(n);
	vector<int> m = v;
	v.clear();
	vector<int> A;
	// tinh ai
	for(auto i : m)
	{
		A.push_back(euler_modolo(a,k,i));
	}
	//tinh Mi
	vector<int> M;
	for(auto i : m)
	{
		M.push_back((int)n/i);
	}

//	// tinh ci =  Mi*(Mi^-1 mod mi)
//	
	vector<int> C;
	for(int i=0;i<M.size();i++)
	{
		C.push_back(M[i]*nghichdao(M[i],m[i]));
		cout<<nghichdao(M[i],m[i])<<"\n";
	}
//	for(auto i : C)
//	{
//		cout<<i<<"\n";
//	}
	
	
	// kq

//	long result =0;
//	for(int i=0;i<C.size();i++)
//	{
//		result += (A[i]*C[i]);
//	}
//	cout<<result % n;
	
		
}

