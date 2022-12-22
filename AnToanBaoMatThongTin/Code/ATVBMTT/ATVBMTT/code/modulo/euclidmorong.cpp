#include<bits/stdc++.h>
using namespace std;

/*
	x = a^-1 mod n
	
	a = 1125
	n = 3739
*/

int main(){
	int a;cout<<"\nNhap so ngich dao : ";cin>>a;
	int n;cout<<"\nNhap n : ";cin>>n;
	cout<<"\n"<<a<<"^-1 mod "<<n<<endl;
	int Q,A1,A2,A3,B1,B2,B3;
	A1 = 1 , A2 = 0 , A3 = n , B1 = 0 , B2 = 1 , B3 = a;
	while(B3 != 0 && B3 != 1){
		Q = A3/B3;
		
		int B1_cp = B1,B2_cp = B2,B3_cp = B3;
		
		B1=A1 - B1*Q;
		B2=A2 - B2*Q;
		B3=A3 - B3*Q;
		
		A1 = B1_cp;A2=B2_cp;A3=B3_cp;
		
//		cout<<Q<<" "<<A1<<" "<<A2<<" "<<A3<<" "<<B1<<" "<<B2<<" "<<B3<<endl;
	}
	if(B3 == 1){
		cout<<"\nSo nghich dao cua "<<a<<" la : "<<B2<<endl;
		cout<<"Ket qua a^-1 mod n = "<<(B2+n)%n;
	}else cout<<"\nKhong tim thay so nghich dao";



return 0;
}

