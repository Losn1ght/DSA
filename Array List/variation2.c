#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef struct{
	int elem[MAX];
	int count;
}Etype, *EPtr;

void initialize(EPtr L){
	L->count = 0;
}
void insertPos(EPtr L, int data, int position){
	// array must be not full
	if(L->count == MAX){
		printf("Error! List is full!\n");
		return;
	}
	
	// position must be valid
	if(position < 0 || position > L->count){
		printf("Error! Invalid position!\n");
		return;
	}
	
	//shift elements to the right
	int i;
	for(i = L->count;i > position; i--){
		L->elem[i] = L->elem[i-1];
	}	
		
	L->elem[position] = data;	
	L->count++;	
}


void deletePos(EPtr L, int position){
	// position must be valid
	if(position < 0 || position > L->count){
		printf("Error! Invalid position!\n");
		return;
	}
	
	// shift elements to the left
	int i;
	for(i = position; i < L->count - 1; i++){
		L->elem[i] = L->elem[i+1];
	}
	
	L->count--;
}

int retrieve(EPtr L, int position){
	// position must be valid
	if(position < 0 || position > L->count){
		printf("Error! Invalid position!\n");
		return -1;
	}	
	
	return L->elem[position];	
}

void insertSorted(EPtr L, int data){
	// array must not be full
	if(L->count == MAX){
		printf("Error! Array is full!\n");
		return;
	}
	
	int pos = 0;
	while(pos < L->count && L->elem[pos] < data){
		pos++;
	}
	
	insertPos(L, data, pos);
}

int locate(EPtr L, int data){
	int i;
	for(i = 0; i < L->count; i++){
		if(L->elem[i] == data){
			return i;
		}
	}
	return -1;
}

void display(EPtr L){
	int i;
	// check if list is empty
	if(L->count == 0){
		printf("List is empty!\n");
		return;
	}
	printf("List: ");
	for(i = 0; i < L->count; i++){
		printf("%d ", L->elem[i]);
	}
	printf("\n");
}
void makeNULL(EPtr L){
	free(L);
}


int main(){
	EPtr L = (EPtr)malloc(sizeof(Etype));
	initialize(L);
	
	// Insert Position
	insertPos(L, 1, 0);
	insertPos(L, 2, 1);
	insertPos(L, 4, 2);
	insertPos(L, 6, 3);
	display(L);
	printf("\n");
	
	// Locate
	int found = locate(L, 1);
	if(found != -1){
		printf("Data found in index %d\n", found);
	}else{
		printf("Data not in List!");
	}
	printf("\n");
	
	// Retrieve
	int ret = retrieve(L, 0);
	printf("Index 0 has element %d\n", ret);
	printf("\n");
	
	// Insert Sorted
	insertSorted(L, 3);
	display(L);
	printf("\n");
	
	// Delete Position
	deletePos(L, 0);
	display(L);
	
	// free memory
	makeNULL(L);

	return 0;
}
