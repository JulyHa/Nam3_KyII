#include<bits/stdc++.h>
using namespace std;

#ifndef ptnt
#define ptnt

vector<pair<int,int>> nguyen_to(int n){
	vector<pair<int,int>> v;
	
	int dem;
    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
           v.push_back(make_pair(i,dem));
        }
    }
    
    return v;
}

#endif
