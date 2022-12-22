#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
string PermutationEncyption(string input, int key){
	string output="";
	int i = 0 , j = 0, len_out = 0, len_in = input.length();
	while(i<key){ 
		j = i; 
		while(j < len_in){
			output += input[j];
			j+=key;
		}
		i++;
	}
	return output;
}
string PermutationDecyption(string input, int key){
	string output="";
	int i = 0 , j = 0, len_out = 0, len_in = input.length();
	int col = len_in/key;
	if(len_in%key) col++;
	while(i<col){
		j = i; 
		while(j < len_in){
			output += input[j];
			j+=col;
		}
		i++;
	}
	return output;
}
int main()
{
	string input;
	int key;
	freopen("hoanvi.txt", "r", stdin);	//;cout<<"Input: ";cout<<"Key: "; 
	
	cin>>input; 
	cin>>key;
	 cout<<"input: "<<input<<"\nkey: "<<key<<endl;
	input = PermutationEncyption(input, key);
	cout<<"\nPermutation Encyption: "<<input<<endl;
	cout<<"Permutation Decyption: "<<PermutationDecyption(input, key);
}


