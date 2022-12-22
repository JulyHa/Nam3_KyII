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
	int n;cin>>n;
	cout<<"O("<<n<<") = "<<cal_phi_n(n);


return 0;
}

