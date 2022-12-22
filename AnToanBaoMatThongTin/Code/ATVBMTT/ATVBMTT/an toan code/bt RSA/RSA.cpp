#include<bits/stdc++.h>
using namespace std;
int nghichdao(int a,int n){
	int Q,A1 = 1,A2 = 0,A3 = n,B1 = 0,B2 = 1,B3 = a;
	while(B3 != 0 && B3 != 1){
		Q = A3/B3;
		int B1_cp = B1,B2_cp = B2,B3_cp = B3;
		B1=A1 - B1*Q;
		B2=A2 - B2*Q;
		B3=A3 - B3*Q;
		
		A1 = B1_cp;A2=B2_cp;A3=B3_cp;
	}
	return (B2+n)%n;
}
int haBac(int a,int m,int n){
	if(m == 1) return a%n;
	int c = m/2;
	int d = m%2;
	int v = int(pow(haBac(a,c,n),2) * int(pow(a,d))) % n;
	return v;
}
int main(){
	int p = 17,q = 11,e = 7,M = 88;
	int n = p*q;
	int euler_n = (p-1)*(q-1);
	int d = nghichdao(e,euler_n); // d = e^-1 mod phi-n
	int C = haBac(M,e,n); // M^e mod n
	int g = haBac(C,d,n);
	cout<<"PU = {"<<e<<","<<n<<"}\n";
	cout<<"PR = {"<<d<<","<<n<<"}\n";
	cout<<"C = "<<C<<'\n';
	cout<<"M = "<<g;
}

