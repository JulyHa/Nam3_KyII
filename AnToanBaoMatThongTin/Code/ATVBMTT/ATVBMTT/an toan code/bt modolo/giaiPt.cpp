#include<bits/stdc++.h>
using namespace std;
int nghichdao(int a,int n)
{
	for(int i=2;i<=a+n;i++)
	{
		if((a*i)%n==1) return i;
	}
}
int main(){
	int m1,m2,m3,a1,a2,a3;
	cout<<"Nhap m: "; cin>>m1>>m2>>m3;
	cout<<"Nhap a: "; cin>>a1>>a2>>a3;
	
	int M1 = m2*m3,M2 = m1*m3,M3 = m1*m2;
	
	int c1 = M1*nghichdao(M1,m1);
	int c2 = M2*nghichdao(M2,m2);
	int c3 = M3*nghichdao(M3,m3);
	
	int result = (a1*c1 + a2*c2 + a3*c3) % (m1*m2*m3);
	cout<<result;

}

