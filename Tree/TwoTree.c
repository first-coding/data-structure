#include "TwoTree.h"

int main() {
	BinartTree T = BinaryInit();
	T->root = TreeNewNode();
	T->root->element = 1;
	btlink L1 = TreeNewNode();
	L1->element = 2;
	btlink R1 = TreeNewNode();
	R1->element = 3;
	T->root->left = L1;
	T->root->right = R1;
	btlink L2 = TreeNewNode();
	btlink R2 = TreeNewNode();
	L2->element = 4;
	L2->left = L2->right = 0;
	R2->element = 5;
	R2->left = R2->right = 0;
	L1->left = L2;
	L1->right = R2;
	R1->left = R1->right = 0;
	PreOut(T);
	printf("\n");
	InOut(T);
	printf("\n");
	PostOut(T);
	return 0;
}