#pragma once
#include<stdio.h>
#include<stdlib.h>

#define MAX	255
typedef struct string {
	char ch[MAX + 1];
	int length;
}String;

int Index_BF(String S, String T, int pos) {
	int i = pos;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] = T.ch[j]) { ++i; ++j; }
		else { i = i - j + 2; j = 1; }
	}
	if (j > T.length) return i - T.length;
	else return 0;
}

