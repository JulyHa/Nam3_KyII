#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
	INPUT: ITSASMALLWORLDIT
	
*/

int main(){
	int key;
	string plain_text;
	cout<<"Nhap chuoi muon ma hoa : ";cin>>plain_text;
	cout<<"\nNhap key : ";cin>>key;
	
	// conver to upper
	std::transform(plain_text.begin(), plain_text.end(),plain_text.begin(), ::toupper);

	
	string output = "";

	for(int i=0;i<plain_text.size();i++){
		if(plain_text[i]>='A' && plain_text[i] <= 'Z'){
			output+= (plain_text[i] - 'A' + key)%26 + 'A';
		}			
	}
	
	cout<<"\nCipher text:"<<output;

return 0;
}

