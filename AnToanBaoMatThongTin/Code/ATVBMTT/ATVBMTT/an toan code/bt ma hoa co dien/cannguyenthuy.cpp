#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n+k;i++)
	{
		long long res = pow(n,i);
		if(res%k==1) cout<<i<<' ';
	}
}

