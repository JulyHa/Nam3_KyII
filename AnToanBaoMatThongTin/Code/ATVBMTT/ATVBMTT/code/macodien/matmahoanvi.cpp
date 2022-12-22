#include<bits/stdc++.h>
using namespace std;


/*
	Input : DONTTROUBLETROUBLE
	Key : 7
*/

int main(){
	int key;
	string plain_text;
	cout<<"Nhap chuoi muon ma hoa : ";cin>>plain_text;
	cout<<"\nNhap key : ";cin>>key;
	
	int col = ceil(plain_text.size()*1.0/key);
	char keyT[key][col] = {};
	
	int pos = 0;
	for(int i=0;i<col;i++){
		for(int j=0;j<key;j++){
			if(pos < plain_text.size()){
				keyT[j][i] = plain_text[pos];
				pos++;	
			}
		}
	}
	
	cout<<"Cipher text : ";
	for(int i=0;i<key;i++){
		for(int j=0;j<col;j++){
			cout<<keyT[i][j];
		}
	}



return 0;
}

