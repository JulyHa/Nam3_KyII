#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string CaesarEncyption(string input, int key){
    int length=input.length();
    for(int i=0;i<length;i++)
       if(input[i] >= 'Z') input[i] = input[i]-26+key;
       else input[i]+=key;
    return input; 
}

string CaesarDecryption(string output, int key){
	int length=output.length();
    for(int i=0;i<length;i++)
       if(output[i] < 'A' + key) output[i] = output[i]+26-key;
       else output[i]-=key;
    return output; 
}
int main()
{
	int key,length;
	string input; 
	freopen("matma.txt", "r", stdin); //cout<<"Input: ";cout<<"Key: "; 
    cin>>input; 
    cin>>key;  key%=26;
    string output = CaesarEncyption(input, key);
    cout<<"input: "<<input<<"\nkey: "<<key<<endl;
    cout<<"Caesar Cipher: "<<output<<endl; 
    cout<<"Caesar Cipher Decryption: "<<CaesarDecryption(output, key);
}
