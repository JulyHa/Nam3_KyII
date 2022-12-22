#include<bits/stdc++.h>
using namespace std;

#ifndef ktnt
#define ktnt

bool kiem_tra_nguyen_to(int n){
	int count = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count != 0) return false;
    return true;
}

#endif
