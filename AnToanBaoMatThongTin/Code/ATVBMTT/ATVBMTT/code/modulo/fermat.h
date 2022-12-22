#include<bits/stdc++.h>
#include "habacluythua.h"
#include "kiemtranguyento.h"
using namespace std;


#ifndef fm
#define fm

int fermat(int a,int m,int n){
	if(kiem_tra_nguyen_to(n) && m > n){
		int _m = m;
		if(__gcd(a,n) == 1){ // dang 1
			while(_m > n) _m = _m-(n-1);
			return habacluythua(a,_m,n);
		}else{ // dang 2
			while(_m > n) _m = _m - n;
			return habacluythua(a,_m,n);
		}
	}
	return habacluythua(a,m,n);
	
}

#endif
