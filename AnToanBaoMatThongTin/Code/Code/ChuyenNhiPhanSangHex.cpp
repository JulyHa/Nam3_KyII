#include <bits/stdc++.h>
using namespace std;
map<string, string> D={{"0000","0"},{"0001","1"},{"0010","2"},{"0011","3"},{"0100","4"},{"0101","5"},{"0110","6"},{"0111","7"},{"1000","8"},{"1001","9"},{"1010","A"},{"1011","B"},{"1100","C"},{"1101","D"},{"1110","E"},{"1111","F"}};

int main()
{
	string s, a = "";
	cout<<"Nhap so nhi phan: ";
	cin >> s;
	cout<<"He thap luc phan cua "<< s << " la: ";
	if(s.length() % 4 == 1) s = "000" + s;
	if(s.length() % 4 == 2) s = "00" + s;
	if(s.length() % 4 == 3) s = "0" + s;
	for(int i = 0; i <= s.length(); i++){
		if((i+1) % 4 == 0){
			a+=s[i];
			cout << D[a];
			a = "";
		}
		else a += s[i]; 
	}
}
