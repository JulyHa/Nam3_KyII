#include<bits/stdc++.h>

#include "phiN.h"

using namespace std;

int main(){
	int n;cout<<"\nNhap n:";cin>>n;
	int a;cout<<"\nNhap a:";cin>>a;
	
	if(__gcd(n,a) == 1){
		int phi_n = cal_phi_n(n);
		bool flag = false;
		if(int(pow(a,phi_n)) % n  == 1) flag = true;
		
		for(int i=1;i<phi_n;i++){
			if( int(pow(a,i)) % n == 1){
				flag = false;
				break;
			}
		}
		
		if(flag == true) cout<<a<<" la can nguyen thuy cua "<<n;
		else cout<<a<<" khong la can nguyen thuy cua "<<n;
	}
	else cout<<a<<" khong la can nguyen thuy cua "<<n;



return 0;
}

