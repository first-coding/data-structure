#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX	255
typedef struct string {
	char ch[MAX + 1];
	int length;
}String;

int Index_BF(String S, String T, int pos) {
	int i = pos;
	int j = 0;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }
		else { i = i - j + 1;  j = 0; }
	}
	if (j > T.length) return i - T.length;
	else return 0;
}

void Next(char* T, int* next) {
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < strlen(T)) {
		if (j == 0 || T[i - 1] == T[j - 1]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

int KMP(char* S, char* T) {
	int next[10];
	Next(T, next);
	int i = 1;
	int j = 1;
	while (i <= strlen(S) && j <= strlen(T)) {
		if (j == 0 || S[i - 1] == T[j - 1]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j > strlen(T)) {
		return i - (int)strlen(T);
	}
	return -1;
}

