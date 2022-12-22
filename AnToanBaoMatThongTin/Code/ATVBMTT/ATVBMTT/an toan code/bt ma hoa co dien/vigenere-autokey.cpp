#include<bits/stdc++.h>
using namespace std;
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string arr[30][30];
int main(){
	string m,k;
	cout<<"Nhap input: "; cin>>m;
	cout<<"Nhap key: "; cin>>k;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			arr[i][j] = s[(j+i)%26];	
		}
	}
	int x=0;
	while(k.size() < m.size())
	{
		k+=m[x];
		x++;
	}
	string result = "";
	for(int i=0;i<m.size();i++)
	{
		result += arr[k[i]-'A'][m[i]-'A'];
	}
	cout<<k<<'\n';
	cout<<"Ket qua cua vignere-key: "<<result;

	
// input : MONEYMAKESTHE
// key : YOUREON
}


