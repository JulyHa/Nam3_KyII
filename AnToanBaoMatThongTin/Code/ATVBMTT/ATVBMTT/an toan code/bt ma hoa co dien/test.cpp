#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; cin>>n;
	int k; cin>>k;
	for(int i=1;i<n+k;i++)
	{
		if((n*i)%k==1){
			cout<<i;
			break;
		}
	}
}

