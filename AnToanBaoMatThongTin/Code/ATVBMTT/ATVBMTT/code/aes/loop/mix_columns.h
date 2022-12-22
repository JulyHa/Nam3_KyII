#include <string>
#include <iostream>
#include <C:\Users\Admin\OneDrive\Máy tính\ATVBMTT\ATVBMTT\code\aes\hex_bin.h>
#include <C:\Users\Admin\OneDrive\Máy tính\ATVBMTT\ATVBMTT\code\aes\XOR.h>
#ifndef mixColumns
#define mixColumns

std::string mix_table[][4] = {
								 {"02","03","01","01"},
								 {"01","02","03","01"},
								 {"01","01","02","03"},
								 {"03","01","01","02"}
							 };
						



std::string multiply_with_02(std::string s){
	s = hex_two_bin(s);
	std::string v = "";
	for(int i=1;i<s.size();i++){
		v+=s[i];
	} 
	v+="0";
	if(s[0] == '1'){
		v = XOR(v,"00011011");
	}
	return v;
}

void mix_each_row(std::string** in,std::string** out,int row,int col){ 
	std::string output = "00000000";
	
	for(int i=0;i<4;i++){
		if(mix_table[row][i] == "02"){
			output = XOR(multiply_with_02(in[i][col]),output);
		}else if(mix_table[row][i] == "03"){
			output = XOR(XOR(multiply_with_02(in[i][col]),hex_two_bin(in[i][col])),output); 	
		}else{
			output = XOR(hex_two_bin(in[i][col]),output);
		}
	}
	out[row][col] = bin_two_hex(output);
}


std::string** mix_columns(std::string** input){
	std::string** output_matrix = new std::string*[4];
	for(int i = 0 ; i < 4 ; i++){
		output_matrix[i] = new std::string[4];
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			mix_each_row(input,output_matrix,i,j);
		}
	}
	return output_matrix;
}



#endif
