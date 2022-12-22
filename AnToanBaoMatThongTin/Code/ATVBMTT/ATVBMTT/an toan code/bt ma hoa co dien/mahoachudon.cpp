#include<bits/stdc++.h>
using namespace std;
string arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string chuDon(string s,string k)
{
	string res = "";
	for(auto i:s)
	{
		res+=k[(i-'A')];
	}
	return res;
}
int vt(char x,string k)
{
	for(int i=0;i<k.size();i++)
	{
		if(x==k[i]) return i;
	}
	
}
string deChuDon(string s,string k)
{
	string res="";
	for(auto i:s)
	{
		res += arr[vt(i,k)];
	}
	return res;
}
int main(){
	string s,k;
	
	cout<<"Nhap input: ";cin>>s;
	cout<<"Nhap Key: "; cin>>k;
	string nho = chuDon(s,k);
	cout<<"Ket qua ma hoa chu don: "<<nho<<'\n';
	cout<<"Ket qua cua tham ma chu don :"<<deChuDon(nho,k);
	
}

