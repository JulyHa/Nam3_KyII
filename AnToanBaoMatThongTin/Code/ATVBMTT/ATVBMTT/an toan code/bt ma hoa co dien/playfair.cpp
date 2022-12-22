#include<bits/stdc++.h>
using namespace std;
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int a[26]={0};
char arr[10][10];
string split(string input)
{
	string result = "";
	int i=0;
	while(i<input.size())
	{
		if(input[i]==input[i+1])
		{
			result += input[i];
			result += 'X';
			i++;
		}
		else{
			result += input[i];
			if(i+1 < input.size()) result += input[i+1];
			i+=2;
		}
	}
	if(result.size()%2) result+='X';
	return result;
}
void vt(char x,int &row,int &col)
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(arr[i][j]==x){
				row = i;
				col = j;
				return ;
			} 
		}
	}
}

int main(){
	string m,k;
	cout<<"Nhap input: "; cin>>m;
	cout<<"Nhap key: "; cin>>k;
	map<char,int> mp;
	string knew="";
	for(auto i:k){
		mp[i]++;
		if(mp[i]==1)
		{
			knew += i;
			a[i-'A']=1;
		}
	}
	
	if(a[8]==1) a[9]=1;
	if(a[9]==1) a[8]=1;
	
	int l=0,h=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(l < knew.size())
			{
				arr[i][j] = knew[l];
				l++;
			}
			else{
				while(h<26)
				{
					if(a[h]==0) break;
					h++;
				} 
				arr[i][j] = s[h];
				h++;
			}
		}
	}

	string mNew = split(m);
	string kq="";
	
	for(int i=0;i<mNew.size()-1;i+=2)
	{
		int x1,y1,x2,y2;
		vt(mNew[i],x1,y1);
		vt(mNew[i+1],x2,y2);
		if(x1==x2){
			kq+=arr[x1][(y1+1)%5];
			kq+=arr[x1][(y2+1)%5];
		}
		else if(y1==y2)
		{
			kq+=arr[(x1+1)%5][y1];
			kq+=arr[(x2+1)%5][y1];
		}
		else{
			kq+=arr[x1][y2];
			kq+=arr[x2][y1];
		}
	}
	cout<<mNew<<'\n';
	cout<<kq;
	
}

