#include <stdio.h>
#include <stdlib.h>   

#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;	/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��TRUE�� */

#define HASHSIZE 12 // �����ϣ��Ϊ����ĳ���
#define NULLKEY -32768 // �չؼ���

typedef struct
{
	int *elem; // ����Ԫ�ش洢��ַ����̬��������
	int count; //  ��ǰ����Ԫ�ظ���
}HashTable;

int m = 0; // ��ϣ�����ȫ�ֱ���

Status initHashTable(HashTable *hash); // ��ʼ����ϣ��
// �����ϣ����
int hashFun(int key);

// ��ʼ����ϣ��
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

// �����ϣ����
int hashFun(int key)
{
	return key % m; // ���췽��Ϊ����������
}

// ����ؼ��ֽ���ϣ��
void insertHash(HashTable *hash, int key)
{
	int addr = hashFun(key); // ���ϣ��ַ
	while (hash->elem[addr] != NULLKEY) // �����Ϊ�գ����ͻ
	{
		addr = (addr + 1) % m; // ���Ŷ�ַ��������̽��
	}
	hash->elem[addr] = key; // ֱ���п�λ�����ؼ���
}

// ��ϣ����ҹؼ���
Status searchHash(HashTable hash, int key, int *addr)
{
	*addr = hashFun(key); // ���ϣ��ַ����������hash.elem[*addr] == key����˵�����ҳɹ���ֱ�ӷ���
	while (hash.elem[*addr] != key) // ����ʹ�ÿ��Ŷ�ַ����������
	{
		*addr = (*addr + 1) % m; // ���Ŷ�ַ��������̽��
		// ��� ���ҵ�NULLKEY | ѭ���ص�ԭ�㣬��˵���ؼ��ֲ����ڣ�����FALSE
		if (hash.elem[*addr] == NULLKEY || *addr == hashFun(key))
			return FALSE;
	}

	return TRUE;
}

int main()
{
	int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34}; // Ҫ����ؼ���
	int key = 39; // �ؼ���
	int addr; // ��ϣ��ַ
	HashTable hash;

	// ��ʼ����ϣ��
	initHashTable(&hash);

	// ����ؼ��ֵ���ϣ��
	for (int i = 0; i<m; i++)
		insertHash(&hash, arr[i]);

	// ����KeyΪ39�Ĺؼ��֣���ʧ�ܣ�
	int result = searchHash(hash, key, &addr);
	if (result)
		printf("���� %d �Ĺ�ϣ��ַΪ��%d \n\n", key, addr);
	else
		printf("���� %d ʧ�ܡ�\n\n", key);

	// �������ҹؼ��֣�����ɹ���
	
	for (int i = 0; i<m; i++)
	{
		key = arr[i];
		searchHash(hash, key, &addr);
		printf("���� %d �Ĺ�ϣ��ַΪ��%d \n", key, addr);
	}
	printf("\n");

	return 0;
}