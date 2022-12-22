#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
	// dinh li fermat a^p mod p = a mod p khi gcd(a,p)==1
	long a,m,n;
	cout<<"Nhap so a:"; cin>>a;
	cout<<"Nhap so m:"; cin>>m;
	cout<<"Nhap so n:"; cin>>n;
	
	if(__gcd(a,m)==1 && (m==n))
	{
		cout<<a%m;
	}
}

