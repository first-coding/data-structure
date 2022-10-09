#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct string* Pstring;
typedef struct string {
	char* ch;
	int length;
}String;

Pstring StringInit(int size) {
	Pstring S = (Pstring)malloc(sizeof(String));
	if (S) {
		S->ch = (char*)malloc(sizeof(char) * size);
		S->length = 0;
	}
	return S;
}


void LengthString(Pstring S){
	int i=0;
	while (S->ch[i] != '\0') {
		S->length++;
		i++;
	}
}

int Index_BF(Pstring S1, Pstring S2, int pos) {
	int i = pos, j = 0;
	while (i < S1->length && j < S2->length) {
		if (S1->ch[i] == S2->ch[j]) {
			++i;
			++j;
			if (j == S2->length) {
				break;
			}
		}
		if(S1->ch[i]!=S2->ch[j]){
			i = i - j + 1;
			j = 0;
		}
	}
	if (++j > S2->length) return i - S2->length;
	else return -1;
}


