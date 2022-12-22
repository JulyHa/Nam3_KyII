#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
/*
	a = 3,b = 4,n = 7;
*/
int main(){
	int a,b,n;
	cout<<"-------------------------log(a,b) mod n-------------------------"<<endl;
	cout<<"Nhap a: "; cin>>a;
	cout<<"Nhap b: "; cin>>b;
	cout<<"Nhap n: "; cin>>n;
	
	bool fag = false;
	for(int i=1; i< n; i++){
		if(((int)pow(a, i) % n )== b){
			cout<<"log(" << a << "," << b << ") mod " << n << " = " <<i;
			fag = true;
		}
	}
	if(!fag)cout<<"Khong co";
}

