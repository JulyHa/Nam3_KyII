#include<string>
#include<map>

#ifndef hex2bin
#define hex2bin

std::string hex_two_bin (std::string input)
{
		std::string output = "";
		
        for(int i =0;i<input.size();i++) {
        	
            switch (input[i]) {
	            case '0':
	                output+="0000";
	                break;
	            case '1':
	            	output+="0001";
	                break;
	            case '2':
	            	output+="0010";
	                break;
	            case '3':
	            	output+="0011";
	                break;
	            case '4':
	            	output+="0100";
	                break;
	            case '5':
	            	output+="0101";
	                break;
	            case '6':
	            	output+="0110";
	                break;
	            case '7':
	            	output+="0111";
	                break;
	            case '8':
	            	output+="1000";
	                break;
	            case '9':
	            	output+="1001";
	                break;
	            case 'A':
	            	output+="1010";
	                break;
	            case 'B':
	            	output+="1011";
	                break;
	            case 'C':
	            	output+="1100";
	                break;
	            case 'D':
	            	output+="1101";
	                break;
	            case 'E':
	            	output+="1110";
	                break;
	            case 'F':
	            	output+="1111";
	                break;
	            default:
	                break;
            }
        }
        return output;
} 

std::string bin_two_hex(std::string input){
	std::string output = "";
	
	std::map<std::string,std::string> dic;
	dic["0000"] = "0";
	dic["0001"] = "1";
	dic["0010"] = "2";
	dic["0011"] = "3";
	dic["0100"] = "4";
	dic["0101"] = "5";
	dic["0110"] = "6";
	dic["0111"] = "7";
	dic["1000"] = "8";
	dic["1001"] = "9";
	dic["1010"] = "A";
	dic["1011"] = "B";
	dic["1100"] = "C";
	dic["1101"] = "D";
	dic["1110"] = "E";
	dic["1111"] = "F";
	
	int i = 0;
	while(i<input.size()){
		output+=dic[input.substr(i,4)];
		i+=4;
	}

	return output;
}

#endif

