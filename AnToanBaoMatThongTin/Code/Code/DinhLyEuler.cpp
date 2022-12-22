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

bool kiem_tra_nguyen_to(int n){
	int count = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
		return false;
        }
    }
    return true;
}
int haBac(int a,int m,int n){
	if(m == 1) return a%n;
	int c = m/2;
	int d = m%2;
	int v = int(pow(haBac(a,c,n),2) * int(pow(a,d))) % n;
	return v;
}
unsigned int cal_phi_n(int n){
	unsigned int result = 0;
	for (int i = 0; i < n; i++)
        if (__gcd(i, n) == 1)
            result++;
    return result;
}
int main(){
	int a = 135,m = 126,n = 64;
	cout<<"-----------------------b = a^m mod n--------------------\nNhap lan luot a m n :";
	cin>>a>>m>>n;
	int phi_n = cal_phi_n(n);
	
	if(!kiem_tra_nguyen_to(n)){
		int _m = m;
		if(__gcd(a,n) == 1){ // dang 1
			while(_m > n)_m = _m - phi_n;
			cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<haBac(a,_m,n);
		}else{ // dang 2
			while(_m > n)_m = _m - (phi_n + 1);
			cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<haBac(a,_m,n);
		}
	}else{
		cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<haBac(a,m,n);
	}

	return 0;
}


