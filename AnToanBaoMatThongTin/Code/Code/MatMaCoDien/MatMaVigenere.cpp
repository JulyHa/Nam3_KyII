#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string RepeatKey(string input, string key){
	string keyNew=key; 
	int length = input.length();
	while(keyNew.length() < length){
		for(int j = 0 ; j < key.length(); j++){		
			keyNew+=key[j];
			if(keyNew.length() == length) break;
		}
	} 
	return keyNew; 
} 
int position(char c){
	if(c > 'Z') return c-'a';
	return c-'A';
} 
string VigenereEncryption(string input, string key){
	string cipher="";
	int p, k, c, m = key.length();
	for(int i=0; i<input.length(); i++){
		p =  position(input[i]);
		k = position(key[i%m]);
		c = (p+k)%26;
		cipher += alphabet[c];
	} 
	return cipher;
}
string VigenereDecryption(string input, string key){
	string cipher="";
	int p, k, c, m = key.length();
	for(int i=0; i<input.length(); i++){
		c =  position(input[i]);
		k = position(key[i%m]);
		p = (c - k + 26)%26;
		cipher += alphabet[p];
	} 
	return cipher;
}

int main()
{
	string input, k, key;
	int length;
	
	freopen("vigenere.txt", "r", stdin);	//cout<<"Nhap Input: ";	cout<<"Nhap Key: "; 
	cin>>input;
	cin>>key;
	cout<<"input: "<<input<<"\nkey: "<<key<<endl;
	key = RepeatKey(input, key);
	cout<<"Key new: "<<key<<endl;
	input = VigenereEncryption(input, key);
	cout<<"Vigenere Encryption: "<<input<<endl;
	cout<<"Vigenere Decryption: "<<VigenereDecryption(input, key);
}


