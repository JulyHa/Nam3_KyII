#include<bits/stdc++.h>
#include "kiemtranguyento.h"
#include "habacluythua.h"
using namespace std;


/*
	b = a^m mod n
*/

int main(){
	int a,m,n;
	cout<<"Nhap lan luot a,m,n :";cin>>a>>m>>n;
	if(kiem_tra_nguyen_to(n) && m > n){
		int _m = m;
		if(__gcd(a,n) == 1){ // dang 1
			while(_m > n) _m = _m-(n-1);
			cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<habacluythua(a,_m,n);
			cout<<"\nDang 1";
		}else{ // dang 2
			while(_m > n) _m = _m - n;
			cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<habacluythua(a,_m,n);
			cout<<"\nDang 2";
		}
	}else{
		cout<<"\n"<<a<<"^"<<m<<" mod "<<n<<" = "<<habacluythua(a,m,n);
	}
	



return 0;
}

