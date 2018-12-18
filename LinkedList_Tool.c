struct LinkedList {
	int val;
	struct LinkedList* next;
};

struct LinkedList* LinkedList_AddLast(struct LinkedList* root, int val) {
	struct LinkedList* preNode = NULL;
	struct LinkedList* node = root;
	
	while (node) {
		/*
		if (node->val == val) {
			return root;
		}
		*/
		preNode = node;
		node = node->next;
	}
	
	node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	node->val = val;
	node->next = NULL;

	if (preNode) {
		preNode->next = node;
		return root;
	}
	return node;
}

struct LinkedList* LinkedList_AddFirst(struct LinkedList* root, int val) {
	struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
	node->val = val;
	node->next = root;
	return node;
}

struct LinkedList* LinkedList_Clear(struct LinkedList* root) {
	struct LinkedList* node;
	while (root) {
		node = root;
		root = root->next;
		free(node);
	}
	return NULL;
}

struct LinkedList* LinkedList_Delete(struct LinkedList* root, int val) {
	struct LinkedList* preNode = NULL, *node = root;
	while (node && node->val != val) {
		preNode = node;
		node = node->next;
	}
	if (node) {
		if (preNode) {
			preNode->next = node->next;
		}else {
			root = node->next;
		}
		free(node);
	}

	return root;
}

void LinkedList_Traversal(struct LinkedList* node) {
	printf("LinkedList: ");
	while (node) {
		printf("%d, ", node->val);
		node = node->next;
	}
	printf("\n");
}


int main()
{
	//test
	const int n = 10;

	struct LinkedList* root = NULL;
	int arr[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 20;
		printf("%d ", arr[i]);
		root = LinkedList_AddFirst(root, arr[i]);
	}
	printf("\n");
	LinkedList_Traversal(root);

	//root = LinkedList_Clear(root);
	//test delete first
	while (1) {
		int x;
		scanf("%d", &x);
		if (x == -1) {
			break;
		}
		root = LinkedList_Delete(root, x);
		LinkedList_Traversal(root);
	}

	return 0;
}
