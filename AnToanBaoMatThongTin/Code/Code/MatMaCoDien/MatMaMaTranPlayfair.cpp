#include<bits/stdc++.h>
#define ll long long
#define MAX 1e9+7
#define MIN -1e9+7
#define f first
#define s second
using namespace std;
string Arrkey = "";
map<char, int>M;
string CreateArrKey(string key){
	int x=0, y=0;
	for(auto i:key){
		if(!M[i]){
			Arrkey+=i;
			if(i=='J' || i == 'I') M['I'] = M['J'] = 1; 
			M[i] = 1;
		}
	}
	for(char i = 'A'; i<='Z'; i++){
		if(!M[i]){
			Arrkey+=i;
			if(i=='J' || i == 'I') M['I'] = M['J'] = 1; 
			M[i] = 1;
		}
	}
	for(int i=0; i<Arrkey.length(); i++)
		M[Arrkey[i]] = i;
		return Arrkey;
}
string SplitLetters(string input){
	string s= "";
	s+= input[0]; 
	for(int i=1; i<input.length(); i++){
		if(input[i] == input[i-1]) {
			s+='X';
		}
		s+=input[i];
	}
	if(input.length()%2) s+='X';
	return s;
}

string PlayFairEncyption(string input, string key){
	string output="";
	for(int i=0; i<input.length(); i+=2){
		int p1 = M[input[i]], p2 = M[input[i+1]];
		int row1 = p1/5, col1 = p1%5;
		int row2 = p2/5, col2 = p2%5;
		if(row1 == row2){
			col1 = ++col1%5;
			col2 = ++col2%5;
			output+= Arrkey[row1*5+col1];
			output+= Arrkey[row2*5+col2];
		}
		else if(col1 == col2){
			row1 = ++row1%5;
			row2 = ++row2%5;
			output+= Arrkey[row1*5+col1];
			output+= Arrkey[row2*5+col2];
		}
		else {
			output+=  Arrkey[row1*5+col2];
			output+= Arrkey[row2*5+col1];
		}
		
	}
	return output;
}
string PlayFairDecyption(string input, string key){
	string output="";
	for(int i=0; i<input.length(); i+=2){
		int p1 = M[input[i]], p2 = M[input[i+1]];
		int row1 = p1/5, col1 = p1%5;
		int row2 = p2/5, col2 = p2%5;
		if(row1 == row2){
			col1 = ++col1%5;
			col2 = ++col2%5;
			output+= Arrkey[row1*5+col1];
			output+= Arrkey[row2*5+col2];
		}
		else if(col1 == col2){
			row1 = ++row1%5;
			row2 = ++row2%5;
			output+= Arrkey[row1*5+col1];
			output+= Arrkey[row2*5+col2];
		}
		else {
			output+=  Arrkey[row1*5+col2];
			output+= Arrkey[row2*5+col1];
		}
		
	}
	return output;
}
int main()
{
	string input, key;
	//cout<<"Input: ";	cout<<"Key: "; 
	
	freopen("playfair.txt", "r", stdin);
	cin>>input; 
	cin>>key;
	cout<<"input: "<<input<<"\nkey: "<<key<<endl;
	key = CreateArrKey(key); 
	cout<<"\nCreate ArrKey: "<<key<<endl; 
	input = SplitLetters(input);
	input = PlayFairEncyption(input,key);
	cout<<"\nPlayFair Encyption: "<<input<<"\n";
	cout<<"\nPlayFair Decyption: "<<PlayFairDecyption(input, key); 
	 
}


