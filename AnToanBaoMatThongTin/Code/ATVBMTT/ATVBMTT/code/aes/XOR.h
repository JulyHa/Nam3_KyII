#include <string>
#ifndef x_o_r
#define x_o_r


std::string XOR(std::string a,std::string b){
	std::string output = "";
	for(int i=0;i<a.size();i++){
		if (a[i] == b[i]) {
            output += "0";
        }
        else {
            output += "1";
        }
	}
	return output;
}

#endif
				


