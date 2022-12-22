#include<bits/stdc++.h>

using namespace std;

unsigned int cal_phi_n(int n){
	unsigned int result = 0;
	for (int i = 0; i < n; i++)
        if (__gcd(i, n) == 1)
            result++;
    return result;
}

int main(){
	int n;cout<<"\nNhap n:";cin>>n;
	int a;cout<<"\nNhap a:";cin>>a;
	int b;cout<<"\nNhap b:";cin>>b;
	
	if(__gcd(n,a) == 1){
		int phi_n = cal_phi_n(n);
		bool flag = false;
		if(int(pow(a,phi_n)) % n  == 1) flag = true;
		
		for(int i=1;i<phi_n;i++){
			if(int(pow(a,i)) % n == 1){
				flag = false;
				break;
			}
		}
		
		if(flag == true){
			cout<<a<<" la can nguyen thuy cua "<<n<<" => ton tai dlog(a,b) (mod n) = ";
			for(int i=1;i<phi_n;i++){
				if(int(pow(a,i)) % n == b){
					cout<<i<<", vi "<<a<<"^"<<i<<" mod"<<n<<" = "<<b;	
					break;
				}

			}
		}
		else cout<<a<<" khong la can nguyen thuy cua "<<n;
	}
	else cout<<a<<" khong la can nguyen thuy cua "<<n;


return 0;
}

