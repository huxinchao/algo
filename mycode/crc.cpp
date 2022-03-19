#include <iostream>
#include <bitset>
#include <cstring>
	
using namespace std;

int main(int argN, const char* argS[]) {
	if(argN < 3) {
		cout << "[-]arg error";
		return 1;
	}
	const char *crc = argS[2];
	const char *source_data = argS[1];


	int crc_exp = strlen(crc);
	int sd_len  = strlen(source_data);

	char* new_data = new char [sd_len + crc_exp + 1];

	
	new_data[sd_len + crc_exp] = 0;
	
	memcpy(new_data, source_data, sd_len);
	for(int i = 0; i < crc_exp - 1; i++) {
		new_data[sd_len + i] = '0';
	}

	int begin = 0;
	int rbegin = 0;
	
	int end   = sd_len + crc_exp;

	for(; begin <= sd_len - 1; begin++) {
		if('1' == new_data[begin]) {
			for(int i = 0; i < crc_exp; i++) {
				new_data[begin + i] = ((crc[i] - 48) ^ (new_data[begin + i] - 48)) + 48;
			}
		}
	}

	for(int i = sd_len; i < sd_len + crc_exp; i++) {
		cout << new_data[i];
	}

	return 0;
}
