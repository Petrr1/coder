#include<string.h>
#include<stdlib.h>
#include"SetString.h"

//immutable
char* toShifter(const char* std, int n) {
	int l;
	l = strlen(std);
	char* std2;
	std2 = malloc(l * sizeof(char));
	for (int i = 0; i < l; i++) {
		if ((std[i] > 96 - (n + 1) * 16) && (std[i] < 123- (n + 1) * 16)) {
			std2[i] = (char)(std[i] + n * 32);
		} else {
			std2[i] = (char) std[i];
		}
	}
	return std2;
}
char* imutToUpper(const char* std) {
        return toShifter(std, -1);
}
char* imutToLower(const char* std) {
       return toShifter(std, 1);
}

char* imutFilter(const char* std) {
	int l;
	l = strlen(std);
	char* std2;
	std2 = malloc(l * sizeof(char));
	int j = 0;
	for(int i = 0; i < l; i++){
		if(
((47 < std[i]) && (std[i] < 57)) || ((64 < std[i]) && (std[i] < 91)) || ((96 < std[i]) && (std[i] < 122)) || (std[i] == ' ')
		){
			std2[j] = std[i];
   			j += 1;
		}
	}
	std2 = realloc(std2, (1 + j) * sizeof(char));
        std2[j] ='\0';
	return std2;
}

char* imutFilterSp(const char* std) {
	int l;
	l = strlen(std);
	char* std2;
	std2 = malloc(l * sizeof(char));
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (std[i] != ' ') {
			std2[j] = std[i];
			j += 1;
		}
	}
	std2 = realloc(std2, (2 + j) * sizeof(char));
	std2[j+1] = '\0';
	return std2;
}

char* imutDelSp(const char* std) {
	int l;
	l = strlen(std);
	int frontSp, tailSp;
	{
		int i = 0;
		while (std[i] == ' ') {
			i += 1;
		}
		frontSp = i;
	}
	{
		int i = l - 1;
		while (std[i] == ' ') {
			i += 1;
		}
		tailSp = i;
	}
	char* std2;
	std2 = malloc((tailSp - frontSp + 2) * sizeof(char));
	int j = 0;
	for (int i = frontSp; i < tailSp + 1; i++) {
		std2[j] = std[i];
		j += 1;
	}
	std2[j+1] = '\0';
	return std2;
}

//mutable
void mutToUpper(char* std) {
        char* std2;
        std2 = imutToUpper(std);
        while (*std) {
                *std = *std2;
                *std++;
                *std2++;
        }
}
void mutToLower(char* std) {
        char* std2;
        std2 = imutToLower(std);
        while (*std) {
                *std = *std2;
                *std++;
                *std2++;
        }
}
void mutFilter(char* std) {
        char* std2;
        std2 = imutFilter(std);
	std = realloc(std2, strlen(std2) * sizeof(char));
}
void mutFilterSp(char* std) {
        char* std2;
        std2 = imutFilterSp(std);
        while (*std) {
                *std = *std2;
                *std++;
                *std2++;
        }
}
void mutDelSp(char* std) {
        char* std2;
        std2 = imutDelSp(std);
        while (*std) {
                *std = *std2;
                *std++;
                *std2++;
        }
}