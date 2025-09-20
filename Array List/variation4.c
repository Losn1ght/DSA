#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;

void initialize(List *L){
	L->elemPtr = (int *)malloc(LENGTH * sizeof(int));
	if(L->elemPtr == NULL){
		printf("Memory allocation failed!\n");	
		exit(1);
	}
	
	L->max = LENGTH;
	L->count = 0;
}
void resize(List *L){
	int newMax = L->max * 2;
	int *newArr = (int*)realloc(L->elemPtr, newMax * sizeof(int));
	if(newArr == NULL){
		printf("Reallocation failed!");
		exit(1);
	}
	L->elemPtr = newArr;
	L->max = newMax;
}

void insertPos(List *L, int data, int position){
	// position must be valid
	if(position < 0 || position > L->count){
		printf("Error! Invalid position!\n");
	}
	
	// check if array list is full 
	if(L->count == L->max){
		resize(L);
	}
	
	// shift elements to the right
	int i; 
	for(i = L->count; i > position; i-- ){
		L->elemPtr[i] = L->elemPtr[i-1];
	}
	
	L->elemPtr[position] = data;
	L->count++;
}



void deletePos(List *L, int position){
	// psotion must be valid
	if(position < 0 || position > L->count ){
		printf("Error! Invalid Position!\n");
		exit(1);
	}
	
	// shift elements to the left
	int i;
	for(i = position; i < L->count - 1; i++){
		L->elemPtr[i] = L->elemPtr[i+1];
	}
	
	L->count--;
}
int locate(List *L, int data){
	int i;
	for(i = 0; i < L->count; i++){
		if(L->elemPtr[i] == data){
			return i;
		}
	}
	
	return -1;
}

int retrieve(List *L, int position){
	// psoition must be valid
	if(position < 0 || position > L->count){
		printf("Error! Invalid position!\n");
		return -1;
	}
	
	return L->elemPtr[position];
}
void insertSorted(List *L, int data){
	if(L->count == L->max){
		resize(L);
	}	
	
	int pos = 0;
	while(pos < L->count && L->elemPtr[pos] < data){
		pos++;
	}

	insertPos(L, data, pos);
}


void display(List *L){
	int i;
	printf("List: ");
	for(i = 0; i < L->count; i++){
		printf("%d ", L->elemPtr[i]);
	}
	printf("Count: %d\n", L->count);
	printf("\n");
}



void makeNULL(List *L){
	if(L->elemPtr != NULL){
		free(L->elemPtr);
		printf("Memory freed!\n");	
	}else{
		printf("Memory leaked!\n");
	}
	L->count = 0;
	L->max = 0;
}

int main(){
	List L;
    initialize(&L);

    insertPos(&L, 1, 0);
    insertPos(&L, 3, 1);
    insertPos(&L, 2, 2);
    insertPos(&L, 5, 3);
    display(&L);

    insertPos(&L, 4, 2); // insert 4 at position 2
    display(&L);

    deletePos(&L, 1); // delete element at index 1
    display(&L);

    int pos = locate(&L, 5);
    printf("Locate 5: %d\n", pos);

    int val = retrieve(&L, 2);
    printf("Element at index 2: %d\n", val);

    List S;
    initialize(&S);

    insertPos(&S, 1, 0);
    insertPos(&S, 3, 1);
    insertPos(&S, 5, 2);
    insertPos(&S, 10, 3);
    display(&S);

    insertSorted(&S, 8);
    display(&S);

    makeNULL(&L);
    makeNULL(&S);

    return 0;
}
