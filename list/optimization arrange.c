#include<List.h>
List ListInit(int size) {
	List L = (List)malloc(sizeof * L);
	L->table = (ListItem*)malloc(sizeof(ListItem));
	L->maxsize = 1;
	L->n = 0;
	return L;
}

List resize(List L) {
	if (L->n > L->maxsize) return;
	ListItem* tmp = (ListItem*)malloc(L->maxsize * sizeof(ListItem));
	for (int i = 0; i < L->n; i++) tmp[i] = L->table[i];
	free(L->table);
	L->table = tmp;
	return L;
}

//int main() {
//	List a = Listinit(20);
//	printf("%d\n", ListLength(a->maxsize));
//	List b = resize(a);
//	printf("%d\n", ListLength(b->maxsize));
//	return 0;
//}