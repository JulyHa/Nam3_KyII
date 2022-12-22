#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

/*
	Input : BETTERSAFETH
	KEY :  ITSASM
*/

int main(){
	string key,plain_text;
	cout<<"Nhap chuoi muon ma hoa : ";cin>>plain_text;
	cout<<"\nNhap key : ";cin>>key;
	
	
	int psize = plain_text.size();
	int ksize = key.size();

	while(psize > ksize){
		key+=plain_text;
		ksize+=psize;
	};
	
	key = key.substr(0,psize);
	
	
	std::transform(key.begin(), key.end(),key.begin(), ::toupper);
	std::transform(plain_text.begin(), plain_text.end(),plain_text.begin(), ::toupper);

	
	string output = "";
	
	for(int i=0;i<plain_text.size();i++){
		if(plain_text[i] >= 'A' && plain_text[i] <= 'Z'){
			output+= ((plain_text[i] - 'A') + (key[i] - 'A'))%26 + 'A';
		}
	}
	
	cout<<"\nCipher text:"<<output;
	



return 0;
}

