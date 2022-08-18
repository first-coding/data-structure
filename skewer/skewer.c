#include"skewer.h"

int main() {
	//String S,T;
	//S.ch[0] = 'a';
	//S.ch[1] = 'b';
	//S.ch[2] = 'c';
	//S.ch[3] = 'd';
	//S.length = 4;
	//T.ch[0] = 'b';
	//T.ch[1] = 'c';
	//T.ch[2] = 'd';
	//T.length = 3;
	//int flag = Index_BF(S, T, 0);
	//return 0;
	int i = KMP("abadcabcacabadb", "abcac");
	printf("%d", i);
	return 0;
}