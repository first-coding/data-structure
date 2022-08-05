#include <stdio.h>
#include <stdlib.h>   

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如TRUE等 */

#define HASHSIZE 12 // 定义哈希表长为数组的长度
#define NULLKEY -32768 // 空关键字

typedef struct
{
	int *elem; // 数据元素存储基址，动态分配数组
	int count; //  当前数据元素个数
}HashTable;

int m = 0; // 哈希表表长，全局变量

Status initHashTable(HashTable *hash); // 初始化哈希表
// 构造哈希函数
int hashFun(int key);

// 初始化哈希表
Status initHashTable(HashTable *hash)
{
	int i;

	m = HASHSIZE;
	hash->count = m;
	hash->elem = (int *)malloc(m*sizeof(int));
	for (i = 0; i<m; i++)
		hash->elem[i] = NULLKEY;

	return TRUE;
}

// 构造哈希函数
int hashFun(int key)
{
	return key % m; // 构造方法为除留余数法
}

// 插入关键字进哈希表
void insertHash(HashTable *hash, int key)
{
	int addr = hashFun(key); // 求哈希地址
	while (hash->elem[addr] != NULLKEY) // 如果不为空，则冲突
	{
		addr = (addr + 1) % m; // 开放定址法的线性探测
	}
	hash->elem[addr] = key; // 直到有空位后插入关键字
}

// 哈希表查找关键字
Status searchHash(HashTable hash, int key, int *addr)
{
	*addr = hashFun(key); // 求哈希地址，如果后面的hash.elem[*addr] == key，则说明查找成功，直接返回
	while (hash.elem[*addr] != key) // 否则，使用开放定址法继续查找
	{
		*addr = (*addr + 1) % m; // 开放定址法的线性探测
		// 如果 查找到NULLKEY | 循环回到原点，则说明关键字不存在，返回FALSE
		if (hash.elem[*addr] == NULLKEY || *addr == hashFun(key))
			return FALSE;
	}

	return TRUE;
}

int main()
{
	int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34}; // 要插入关键字
	int key = 39; // 关键字
	int addr; // 哈希地址
	HashTable hash;

	// 初始化哈希表
	initHashTable(&hash);

	// 插入关键字到哈希表
	for (int i = 0; i<m; i++)
		insertHash(&hash, arr[i]);

	// 查找Key为39的关键字（会失败）
	int result = searchHash(hash, key, &addr);
	if (result)
		printf("查找 %d 的哈希地址为：%d \n\n", key, addr);
	else
		printf("查找 %d 失败。\n\n", key);

	// 遍历查找关键字（都会成功）
	
	for (int i = 0; i<m; i++)
	{
		key = arr[i];
		searchHash(hash, key, &addr);
		printf("查找 %d 的哈希地址为：%d \n", key, addr);
	}
	printf("\n");

	return 0;
}