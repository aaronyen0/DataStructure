#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define HASHTABLESIZE 5

struct LinkedList {
	int val;
	struct LinkedList* next;
};

struct LinkedList* LinkedList_AddNew(struct LinkedList* root, int val) {
	struct LinkedList* preNode = NULL;
	struct LinkedList* node = root;

	while (node) {
		//已經在list內則退出
		if (node->val == val) {
			return root;
		}

		preNode = node;
		node = node->next;
	}

	node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	node->val = val;
	node->next = NULL;

	//若preNode有值，則掛在preNode下
	if (preNode) {
		preNode->next = node;
		return root;
	}

	//若preNode沒值，新node就是root
	return node;
}

void HashTable_Clear(struct LinkedList** table) {
	if (!table) {
		return;
	}

	struct LinkedList* root, *node;
	for (int i = 0; i < HASHTABLESIZE; ++i) {
		root = table[i];
		while (root) {
			node = root;
			root = root->next;
			free(node);
		}
		table[i] = NULL;
	}
	return;
}

void HashTable_Traversal(struct LinkedList** table) {
	if (!table) {
		return;
	}

	struct LinkedList* node;
	for (int i = 0; i < HASHTABLESIZE; ++i) {
		printf("Table[%4d] ", i);
		node = table[i];
		while (node) {
			printf("%d, ", node->val);
			node = node->next;
		}
		printf("\n");
	}
}
int main()
{
	const int n = 10;
	struct LinkedList* table[HASHTABLESIZE] = { NULL }; //注意要給初始值

	int a, b, i = 0;

	srand(time(NULL));
	while (i++ < n) {
		a = rand() % HASHTABLESIZE;
		b = rand() % 20;
		printf("hashNum = %3d, val = %d\n", a, b);
		table[a] = LinkedList_AddNew(table[a], b); //注意這版的linkedlist回傳值要用root去接
		HashTable_Traversal(table);
	}
	HashTable_Clear(table);
	return 0;
}
