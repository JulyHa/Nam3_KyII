#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;

void sang(long long n,vector<long long> &P)
{
	vector<bool> S(n+1,true);
	for(long long i=2;i<=n;i++)
	if(S[i])
	{
		P.push_back(i);
		for(long long j=i*i;j<=n;j+=i) S[j]=false;
	}
}
int main()
{
	vector<long long> P;
	int n;
	cout<<"Nhap 1 so nguyen: "; cin>>n;
	sang(n,P);
	for(auto x:P) cout<<x<<" ";
}
