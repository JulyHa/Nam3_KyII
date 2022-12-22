#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
int arr[100000];
int len= 0;

void chuyenSangNhi(int n){
	while(n > 0){
		arr[len++] = n%2;
		n /= 2;
	}
}
int sol(int a, int n){
	chuyenSangNhi(n);
	ll sum=1;
	for(int i=0; i<len; i++){
		if(arr[i] == 1){
			sum *= pow(a, pow(2,i));
			
		}	
	}
	return sum;
}
int main()
{
	int a, n;
	cout<<"------------- a^n = ? -------------"<<endl;
	cout<<"Nhap a: "; cin>>a;
	cout<<"Nhap n: "; cin>>n;
	cout<<a<<"^"<<n<<" = "<<sol(a, n);

}


