#include<bits/stdc++.h>
using namespace std;


/*
	b = a^m mod n
*/

int habacluythua(int a,int m,int n){
	if(m == 1) return a%n;
	int c = m/2;
	int d = m%2;
	int v = int(pow(habacluythua(a,c,n),2) * int(pow(a,d))) % n;
	return v;
}

int main(){
	int a,m,n;
	cout<<"Nhap lan luot a,m,n :";cin>>a>>m>>n;
	cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<habacluythua(a,m,n);
	


return 0;
}

