#include "TwoTree2.h"

int main() {
	rootaddr T = TreeInit();	
	rootaddr L = TreeInit();
	rootaddr R = TreeInit();
	T = MakeTree(1, T, L, R);

	rootaddr L2 = TreeInit();
	rootaddr R2 = TreeInit();
	L = MakeTree(2, L, L2, R2);
	T->root->left = L->root;

	rootaddr L3 = TreeInit();
	rootaddr R3 = TreeInit();
	R = MakeTree(3, R, L3, R3);
	T->root->right = R->root;

	L2 = MakeTree(4, L2, 0, 0);
	L->root->left = L2->root;

	R2 = MakeTree(5, R2, 0, 0);
	L->root->right = R2->root;

	L3 = MakeTree(6, L3, 0, 0);
	R->root->left = L3->root;

	R3 = MakeTree(7, R3, 0, 0);
	R->root->right = R3->root;

	FirstOut(T);
	//PreOut(T);
	//printf("\n");
	//InOut(T);
	//printf("\n");
	//PostOut(T);
 }


