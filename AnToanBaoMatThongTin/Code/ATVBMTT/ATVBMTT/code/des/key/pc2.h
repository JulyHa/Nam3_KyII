#include <string>
#ifndef pc2
#define pc2

int PC2[48] = {14,17,11,24,1,5,3,28,
			15,6,21,10,23,19,12,4,
			26,8,16,7,27,20,13,2,
			41,52,31,37,47,55,30,40,
			51,45,33,48,44,49,39,56,
			34,53,46,42,50,36,29,32
			};

std::string permuted_choice_2(std::string input){
	std::string output = "";
	for(int i=0;i<48;i++){
		output+= input[PC2[i]-1];
	}
	return output;
}

#endif
	
