#include<bits/stdc++.h>
using namespace std;
int main(){
	string m;int k;
	cout<<"Nhap input: "; cin>>m;
	cout<<"Nhap key: "; cin>>k;
	char arr[k+5][k+5] ={'X'};
	int kt=0,r;
	for(int i=0;;i++)
	{
		for(int j=0;j<k;j++)
		{	
			if(k*i+j <= m.size()){
				arr[i][j] = m[k*i+j];
			}
			else{
				r=i;
				kt=1;
				break;
			}
		}
		if(kt) break;
	}
	r--;
	for(int j=0;j<k;j++)
	{
		for(int i=0;i<=r;i++) cout<<arr[i][j];
	}

	
}

