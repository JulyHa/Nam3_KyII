#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,n;
	cin>>a>>n;
	for(int i=2;i<a+n;i++)
	{
		if((a*i)%n==1)
		{
			cout<<i<<' ';
		}
	}
}

