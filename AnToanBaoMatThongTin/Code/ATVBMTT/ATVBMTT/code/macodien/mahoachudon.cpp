#include<bits/stdc++.h>
using namespace std;


string encoder(string key)
{
    string encoded = "";
	
	// danh dau
    bool arr[26] = {0};
 
    for (int i=0; i<key.size(); i++)
    {
        if(key[i] >= 'A' && key[i] <= 'Z')
        {
            if (arr[key[i]-65] == 0)
            {
                encoded += key[i];
                arr[key[i]-65] = 1;
            }
        }
    }
 
    // This loop inserts the remaining
    // characters in the encoded string.
    for (int i=0; i<26; i++)
    {
        if(arr[i] == 0)
        {
            arr[i]=1;
            encoded += char(i + 65);
        }
    }
    
    return encoded;
}

// Function that generates encodes(cipher) the message
string cipheredIt(string plain_text, string key_encode)
{
    string output="";
 
    // This loop outputed the message.
    // Spaces, special characters and numbers remain same.
    for (int i=0; i<plain_text.size(); i++)
    {
        if (plain_text[i] >='A' && plain_text[i] <='Z')
        {
            int pos = plain_text[i] - 65;
            output += key_encode[pos];
        }
        else
        {
            output += plain_text[i];
        }
    }
    return output;
}

/*
	Input = ONESWALLOWDOESNT
	Key :  WBXGIHOVSYMFUAKZJNCPQLTRED

*/

int main(){
	string key,plain_text;
	cout<<"Nhap chuoi muon ma hoa : ";cin>>plain_text;
	cout<<"\nNhap key : ";cin>>key;
	
	
	// conver to upper
	std::transform(key.begin(), key.end(),key.begin(), ::toupper);
	std::transform(plain_text.begin(), plain_text.end(),plain_text.begin(), ::toupper);
	
	string keyEncoded = encoder(key);
	
	string cipher_text = cipheredIt(plain_text,keyEncoded);
	
	cout<<"Key encoded : "<<keyEncoded<<endl;
	cout<<"Cipher text : "<<cipher_text;



return 0;
}

