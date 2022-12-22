#include<bits/stdc++.h>

#include "key/shift_left_1_byte.h"

#include "loop/shift_rows.h"
#include "loop/mix_columns.h"

#include "hex_bin.h"
#include "XOR.h"
#include "sub_byte.h"
using namespace std;


/*
	Plain text : 0123456789ABCDEFFEDCBA9876543210
	Key: 0F1571C947D9E8590CB7ADD6AF7F6798
	Cipher text: FF0B844A0853BF7C6934AB4364148FB9
*/

string RCj[] = {"01","02","04","08","10","20","40","80","1B","36"}; // 10 vong lap


// tim khoa mo rong
/*
	Cong thuc:
	input:W4[(i-1)],W[4(i-1)+1],W[4(i-1)+2],W[4(i-1)+3]
	output : W(4i),W(4i+1),W(4i+2),W(4i+3)
	Vd:
		input:w0,w1,w2,w3
		output:w4,w5,w6,w7
*/

int main(){
	string plain_text = "BC3034B5D3677672E290C28DC16922FB"; // 128 bit
	string key = "AADE12F39F579A5A49845A7797FE9146"; //128 bit
	

	string** text_array = new string*[4];
	for(int i = 0 ; i < 4 ; i++) text_array[i] = new string[4];
	
	
//	add round key lan dau
	string add_round_key = bin_two_hex(XOR(hex_two_bin(plain_text),hex_two_bin(key)));
	
	//	loop
	string k0 = key.substr(0,8);
	string k1 = key.substr(8,8);
	string k2 = key.substr(16,8);
	string k3 = key.substr(24,8);
	
	for(int i=0;i<10;i++){
		string AfterSubtituteBytes = sub_byte(add_round_key);

		//  push AfterSubtituteBytes string to matrix
		string w0 = AfterSubtituteBytes.substr(0,8);
		string w1 = AfterSubtituteBytes.substr(8,8);
		string w2 = AfterSubtituteBytes.substr(16,8);
		string w3 = AfterSubtituteBytes.substr(24,8);
	
		for(int i = 0 ; i < 4 ; i++) text_array[i][0] = w0.substr(i*2,2);
		for(int i = 0 ; i < 4 ; i++) text_array[i][1] = w1.substr(i*2,2);
		for(int i = 0 ; i < 4 ; i++) text_array[i][2] = w2.substr(i*2,2);
		for(int i = 0 ; i < 4 ; i++) text_array[i][3] = w3.substr(i*2,2);
		
		
		string** AfterShiftRows = shift_rows(text_array);
		
		string** AfterMixColums = mix_columns(AfterShiftRows);
		
		// find key vong lap i
		string AfterRotWord = shift_left_1_byte(k3);

		string AfterSubWord = sub_byte(AfterRotWord);

		string AfterXorWithRcon = XOR(hex_two_bin(AfterSubWord),hex_two_bin(RCj[i]+"000000"));

		string word1 = XOR(AfterXorWithRcon,hex_two_bin(k0));
		
		string word2 = XOR(word1,hex_two_bin(k1));
		string word3 = XOR(word2,hex_two_bin(k2));
		string word4 = XOR(word3,hex_two_bin(k3));
		
		// gan lai gia tri
		k0 = bin_two_hex(word1);
		k1 = bin_two_hex(word2);
		k2 = bin_two_hex(word3);
		k3 = bin_two_hex(word4);
	
		// end find key
		
		// change matrix to string
		string after_sr_or_mc = "";
		if(i!=9){
			for(int i = 0 ; i < 4 ; i++){
				for(int j = 0 ; j < 4 ; j++){
					after_sr_or_mc += AfterMixColums[j][i];
				}
			}
		}else{
			for(int i = 0 ; i < 4 ; i++){
				for(int j = 0 ; j < 4 ; j++){
					after_sr_or_mc += AfterShiftRows[j][i];
				}
			}
		}
	
		add_round_key = bin_two_hex(XOR(hex_two_bin(after_sr_or_mc),hex_two_bin(k0+k1+k2+k3)));
	}
	// result
	string cipher_text = add_round_key;
	
	cout<<cipher_text;
	



	
	


	


return 0;
}

