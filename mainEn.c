#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"SetString.h"
#include"TestString.h"
#include"Coder.h"

int main(int n, char* par[]) {
	int error[] = {0, 0, 0, 0};
	int cn;
	char* codName;
	char* std;
	char* key;
	if (n == 4) {
		codName = par[1];
		std = par[2];
		key = par[3];
		if (!strcmp(codName, "--caesar")) {
			cn = 1;
		} else if (!strcmp(codName, "--xor")) {
			cn = 2;
		} else {
			cn = 0;
			error[0] = 1;
		}
		int kay;
		if (cn == 1) {
			if (ifNumbStr(key) == 0) {
            	cn = 0;
                error[1] = 1;
            } else {
	 			int l, tan;
				l = strlen(key);
				tan = 1;
				kay = 0;
				for (int i = 0; i < l; i++){
					kay += (key[l - i - 1] - 48) * tan;
					tan *= 10;
				}
				if (key[0] == '-') {
					kay = (kay - (('-' - 48) * (tan/10))) * (-1);
				}
				if ((kay > 26) || (kay < -26)) {
					kay = kay - 26 * (kay / 26);
				}
			}
		}
		if (ifLettStr(std) == 0) {
			cn = 0;
			error[2] = 1;
		}
		if (cn != 0) {
			mutFilterSp(std);
			mutToLower(std);
			if (cn == 1) {
				mutCodCez(std, kay);
			}
			if (cn == 2) {
				mutCodXor(std, key);
			}
			printf("%s\n", std);
			return 0;
		} else {
			cn = 0;
			error[3] = 1;
		}
		printf("Error:\n");
		if (error[0] == 1) {
			printf(" Does not exist this coder.\n");
		}
		if (error[1] == 1) {
			printf(" Incorrect format for key of caesar.\n");
		}
		if (error[2] == 1) {
			printf(" Incorrect format for string.\n");
		}
		if (error[3] == 1) {
			printf(" Wrong number of parameters.\n");
		}
		return 1;
	}
}
