#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


 
// Function to make the plain text length to be even
string prepare(string s)
{
    string o = "";
    int i = 0;	
    
	while(i <= s.size()){
		string v = s.substr(i,2);
		if(v.size() == 2 && v[0] == v[1]){
			o+= v[0];
			o+= 'X';
			i++;
		}
		else{
			o+=v;
			i+=2;
		}
	}
	if(o.size() %2 != 0) o+='Z';
	
    return o;
}
 
void generateKeyTable(string key, char keyT[][5])
{
    int *dicty;
 
    dicty = new int[26]{0};
    
    // danh dau cac key character
    for (int i = 0; i < key.size(); i++) {
        if (key[i] != 'J')
            dicty[key[i] - 65] = 2;
    }
 	
 	// bo ki tu J 
	//1 la danh dau roi , 2 la chua danh dau , 0 la chua co gi
    dicty['J' - 65] = 1;
 
    int i = 0,j = 0;
 	
    for (int k = 0; k < key.size(); k++) {
        if (dicty[key[k] - 65] == 2) {
            dicty[key[k] - 65] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
 	
 	// ghi cac chu cai con lai
    for (int k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyT[i][j] = (char)(k + 65);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}
 
// Function to search for the characters of a digraph
// in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
 
    if (a == 'J') a = 'I';
    else if (b == 'J') b = 'I';
 
    for (int i = 0; i < 5; i++) {
 
        for (int j = 0; j < 5; j++) {
 
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

 
// Function for performing the encryption
string encrypt(char keyT[5][5], string plain_text)
{
	string output = "";
    int a[4];
 
    for (int i = 0; i < plain_text.size(); i += 2) {
 
        search(keyT, plain_text[i], plain_text[i + 1], a);
 
        if (a[0] == a[2]) { // cung hang
            output += keyT[a[0]][(a[1] % 5) + 1];
            output += keyT[a[0]][(a[3] % 5) + 1];
        }
        else if (a[1] == a[3]) { // cung cot
            output += keyT[(a[0] % 5) + 1][a[1]];
            output += keyT[(a[2] % 5) + 1][a[1]];
        }
        else { // khac hang khac cot
            output += keyT[a[0]][a[3]];
            output += keyT[a[2]][a[1]];
        }
    }
    
    return output;
}
 

/*
	input : ACLEANFASTISB
	key : EASTO
*/

int main(){
	string key,plain_text;
	cout<<"Nhap chuoi muon ma hoa : ";cin>>plain_text;
	cout<<"\nNhap key : ";cin>>key;
	
	// conver to upper
	std::transform(key.begin(), key.end(),key.begin(), ::toupper);
	std::transform(plain_text.begin(), plain_text.end(),plain_text.begin(), ::toupper);
	
	// make plain text even
	plain_text = prepare(plain_text);
	
	// generate table
	char keyT[5][5];

	generateKeyTable(key,keyT);
	
	// encrip
	string cipher_text = encrypt(keyT,plain_text);
	
	cout<<"\nCipher text : "<<cipher_text;	


	
	


return 0;
}

