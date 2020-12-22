#include<string.h>
#include<stdlib.h>
#include"Coder.h"

//mutable
void mutCodCez(char* std, int key) {
	while (*std) {
		if (*std + key  > 'z') {
			*std = 'a' + *std - 'z' + key;
		} else if (*std + key < 'a') {
			*std = 'z' - 'a' + *std + key;
		} else {
			*std = *std + key;
		}
		++std;
	}
}

void mutCodXor(char* std, const char* key) {
	char* kay;
	while (*std) {
		*kay = *key;
		while (*std && *kay) {
			*std = *std ^ *kay;
			++std;
			++kay;
		}
	}
}

//immutable
char* imutCodCez(const char* std, int key){
	char* std2;
	std2 = malloc(strlen(std) * sizeof(char));
	for (int i=0; i<strlen(std); i++) {
		std2[i] = std[i];
	}
	mutCodCez(std2, key);
	return std2;
}

char* imutCodXor(const char* std, const char* key) {
	char* std2;
	std2 = malloc(strlen(std) * sizeof(char));
	for(int i=0;i<strlen(std);i++){
		std2[i] = std[i];
	}
	mutCodXor(std2, key);
	return std2;
}