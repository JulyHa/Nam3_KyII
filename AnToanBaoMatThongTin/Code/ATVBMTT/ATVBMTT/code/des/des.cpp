#include<bits/stdc++.h>

#include "key/pc1.h"
#include "key/left_shift.h"
#include "key/pc2.h"

#include "loop/IP.h"
#include "loop/E.h"
#include "loop/P.h"
#include "loop/Sbox.h"     

#include "hex_bin.h"
#include "XOR.h"
#include "IP-1.h"
using namespace std;

/*
	Plain text : 02468ACEECA86420
	Key: 0F1571C947D9E859
	Cipher text: DA02CE3A89ECAC3B
*/
int schedule_of_left_shift[] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1}; // 16 vong lap

int main(){
	string key = "0F1571C947D9E859"; // 64 bit
	string plain_text = "02468ACEECA86420"; //64 bit

	////////////////////////////////////////////////////////

	// convert to binary
	key = hex_two_bin(key); // 64 bit

	// PC 1
	key = permuted_choice_1(key); // 56 bit
	
	////////////////////////////////////////////////////////
	// convert to binary
	plain_text = hex_two_bin(plain_text); // 64 bit
	
	// Initial Permutation (IP)
	plain_text = initial_permutation(plain_text); // 64 bit
	
	// loop 	
	string Ci = key.substr(0,28); // 28 bit
	string Di = key.substr(28,28); // 28 bit
	
	string Li = plain_text.substr(0,32); // 32 bit
	string Ri = plain_text.substr(32,32); // 32 bit
	
	for(int i=0;i<sizeof(schedule_of_left_shift)/sizeof(int);i++){
		string Ci_after_shift_left = shift_left(Ci,schedule_of_left_shift[i]);
		string Di_after_shift_left = shift_left(Di,schedule_of_left_shift[i]);
		
		// PC 2
		string Ki = permuted_choice_2(Ci_after_shift_left + Di_after_shift_left); // key - 48 bit
		
		// Expoutpution (E)
		string after_E = expansion(Ri); // 48 bit
		
		// E XOR K
		string e_xor_k = XOR(after_E,Ki); // 48 bit
		
		// S box
		string after_sbox = Sbox(e_xor_k); // 32 bit
		
		// Permutation (P)
		string after_P = permutation(after_sbox); // 32 bit
		
		// Li xor P
		string Li_xor_P = XOR(Li,after_P); // 32 bit
		
		// gan lai ket qua
		Li = Ri;
		Ri = Li_xor_P;
				
		
		Ci = Ci_after_shift_left;
		Di = Di_after_shift_left;
	}
	
	// 32 bit swap
	string tmp = Li;
	Li = Ri;
	Ri = tmp;
	
	// inverse initial permutation (IP^-1)
	string cipher_text = inverse_initial_permutation(Li+Ri);
	
	
	// result
	cout<<bin_two_hex(cipher_text);
	


	
	



return 0;
}

