/**
 * 這是別人寫的hashtable範例
 * 架構上和一般的hashtable主要差在有沒有再多包一層(也就是有一個進入點，記憶體式在進入點內配置的)
 * 實際要透過該進入點才能再進去table內
 * 跟我之前寫過的linkedlist很像，較有物件的概念
 */

typedef struct{
	int key;
	int val; 
}DataType;
typedef struct{
	DataType data;
	struct HashNode *next; 
}HashNode;
typedef struct{
	int size;
	HashNode *table;
}HashMap,*hashmap;

//f1_createHashMap
HashMap *CreateHashMap(int *nums,int size){
	HashMap *hashmap=(HashMap*)malloc(sizeof(HashMap));
	hashmap->size=2*size;
	hashmap->table=(HashNode *)malloc(sizeof(HashNode)*hashmap->size);
	int j=0;
	for(j=0;j<hashmap->size;j++){
		hashmap->table[j].data.val=INT_MIN;
		hashmap->table[j].next=NULL;
	}
	int i=0;
	while(i<size){
		int pos=abs(nums[i])%hashmap->size;
		if(hashmap->table[pos].data.val==INT_MIN){
			hashmap->table[pos].data.key=i;
			hashmap->table[pos].data.val=nums[i];
		}
		else{
			HashNode *lnode=(HashNode*)malloc(sizeof(HashNode)),*hashnode;
			lnode->data.key=i;
			lnode->data.val=nums[i];
			lnode->next=NULL;
			hashnode=&(hashmap->table[pos]);
			while(hashnode->next!=NULL){
				hashnode=hashnode->next;
			}
			hashnode->next=lnode;
		}
		i++; 	
	}
	return hashmap;
}

//f2_PrintHashMap 
void PrintHashMap(HashMap* hashmap){
	int i=0;
	HashNode *pointer;
	while(i<hashmap->size){
		pointer=&(hashmap->table[i]);
		while(pointer!=NULL){
			printf("%10d",pointer->data.val);
			pointer=pointer->next;
		}
		i++;
		printf("\n");
	}
}
//f3_GetHashNode
int* Get(int value,HashMap hashmap){
	int pos=abs(value)%hashmap.size;
	HashNode *pointer=&(hashmap.table[pos]);
    int i=0;
	while(pointer!=NULL){
		if(pointer->data.val==value) 
			return pointer->data.key;
		else
			pointer=pointer->next;
			
	}
	 
	return -1;
}	
	
int* twoSum(int* nums, int numsSize, int target) {
   int *twosum=(int *)malloc(sizeof(int)*2);
   HashMap *hashmap=CreateHashMap(nums,numsSize);
   int i=0;
	while(i<numsSize){
		int goal=target-nums[i];
		if(Get(goal,*hashmap) != -1 && Get(goal,*hashmap) != i){
			twosum[0]=i<Get(goal,*hashmap)?i:Get(goal,*hashmap);
			twosum[1]=i>Get(goal,*hashmap)?i:Get(goal,*hashmap);
			break;
		}
		i++;  
	} 
   return  twosum;
}
