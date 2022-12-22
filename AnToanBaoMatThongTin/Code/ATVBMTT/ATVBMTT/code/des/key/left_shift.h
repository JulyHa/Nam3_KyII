#include <string>
#ifndef left_shift
#define left_shift

std::string shift_left(std::string k,int shift){
	std::string s = "";
	for(int i=0;i<shift;i++){
		for(int j=1;j<28;j++){
			s+= k[j];
		}
		s+=k[0];
		k=s;
		s="";
	}
	return k;
}

#endif
	
