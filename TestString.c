#include<string.h>
#include<stdlib.h>
#include"TestString.h"

int ifNumbStr(const char* std) {
	int l;
	l = strlen(std);
	int i = 1;
	int testNS = 1;
	while (testNS && (i < l)) {
		if ((std[i] < 48) || (std[i] > 57)) {
			testNS = 0;
		}
		i += 1;
	}
	return testNS;
}

int ifLettStr(const char* std) {
	int l;
	l = strlen(std);
	int i = 0;
	int testLS = 1;
	while (testLS && (i < l)) {
		if ((std[i] < 65) || ((std[i] > 90) && (std[i] < 97)) || (std[i] > 122)) {
			testLS = 0;
		}
		i += 1;
	}
	return testLS;
}
