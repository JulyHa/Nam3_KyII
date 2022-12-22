#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;

bool kTra(int n){
	for(int i = 2; i*i < n; i++){
		if(n % i == 0) return 0;	
	}
	return 1;
}
	

int main()
{
	int n;
	cout<<"Nhap so can kiem tra: "; cin >> n;
	if( kTra(n)) cout<< n <<" la so nguyen to. ";
	else cout<< n << " la hop so.";

}


