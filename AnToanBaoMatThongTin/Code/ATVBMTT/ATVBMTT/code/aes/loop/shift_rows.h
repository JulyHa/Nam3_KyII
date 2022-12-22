#include <string>
#ifndef shiftRows
#define shiftRows

std::string** shift_rows(std::string** in){
	
	std::string** output_matrix = new std::string*[4];
	for(int i = 0 ; i < 4 ; i++) output_matrix[i] = new std::string[4];
	
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			output_matrix[i][j] = in[i][(j%4+i)%4];
		}
	}
//	std::string output = "";
//	std::string w0 = input.substr(0,32);
//	std::string w1 = input.substr(32,32);
//	std::string w2 = input.substr(64,32);
//	std::string w3 = input.substr(96,32);
//	
//	output+= w0;
//	output+= w1.substr(8,24)  + w1.substr(0,8);
//	output+= w2.substr(16,16) + w2.substr(0,16);
//	output+= w3.substr(24,8)  + w3.substr(0,24);
	
	return output_matrix;
}

#endif
