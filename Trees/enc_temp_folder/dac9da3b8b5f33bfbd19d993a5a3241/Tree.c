#include"Tree.h"

int main() {
	Hpoint t = InitTree();
	Tpoint p = t->root;
		CreateTree(p, 1, 2);
		Tpoint q = p;
		p = Newroot(0, p);
		q = Newroot(1, q);
	return 0;
}