#include<bits/stdc++.h>
using namespace std;


#ifndef hblt
#define hblt

int habacluythua(int a,int m,int n){
	if(m == 1) return a%n;
	int c = m/2;
	int d = m%2;
	int v = int(pow(habacluythua(a,c,n),2) * int(pow(a,d))) % n;
	return v;
}

#endif
