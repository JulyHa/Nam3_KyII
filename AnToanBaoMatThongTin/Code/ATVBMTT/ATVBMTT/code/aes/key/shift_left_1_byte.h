#include <string>
#ifndef shiftLeftBytes
#define shiftLeftBytes

std::string shift_left_1_byte(std::string input){
	std::string output = "";
	output+= input.substr(2,6) + input.substr(0,2);
	return output;
}

#endif
