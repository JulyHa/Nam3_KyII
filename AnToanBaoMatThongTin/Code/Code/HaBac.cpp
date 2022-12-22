#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;

/*
	b = a^m mod n
*/

int haBac(int a,int m,int n){
	if(m == 1) return a%n;
	int c = m/2;
	int d = m%2;
	int v = int(pow(haBac(a,c,n),2) * int(pow(a,d))) % n;
	return v;
}

int main(){
	int a,m,n;
	cout<<"----------------------b = a^m mod n----------------------"<<endl;
	cout<<"Nhap lan luot a,m,n :";cin>>a>>m>>n;
	a = a % n;
	cout<<"\n=> "<<a<<"^"<<m<<" mod "<<n<<" = "<<haBac(a,m,n);
	


return 0;
}

