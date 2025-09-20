#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef struct{
	int *elemPtr;
	int count;
	int max;
}List;
List initialize(List L){
	L.elemPtr = (int *)malloc(LENGTH * sizeof(int));
	
	if(L.elemPtr == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	L.max = LENGTH;
	L.count = 0;
	return L;
}

List resize(List L){
	int newMax = L.max * 2;
	int *newArr = (int *)realloc(L.elemPtr, newMax * sizeof(int));
	
	if(newArr == NULL){
		printf("Memory allocation failed!\n");
		exit(1);
	}
	L.elemPtr = newArr;
	L.max = newMax;
	return L;
}

List insertPos(List L, int data, int position){
	//position must be valid
	if(position > L.count || position < 0){
		printf("Error! Position is invalid!\n");
		return L;
	}
	
	// check if list is full then call resize
	if(L.count == L.max){
		L = resize(L);
	}
	
	// shift elements to the right
	int i;
	for(i = L.count; i > position; i--){
		L.elemPtr[i] = L.elemPtr[i-1];
	}
	
	L.elemPtr[position] = data;
	L.count++;
	return L;
}
List deletePos(List L, int position){
	// position must be valid
	if(position < 0 || position > L.count){
		printf("Error! Position is invalid!\n");
		return L;
	}
	
	// shift elements to the left
	int i;
	for(i = position; i < L.count - 1; i++){
		L.elemPtr[i] = L.elemPtr[i+1];
	}
	
	L.count--;
	return L;	
}


List  insertSorted(List L, int data){
	// check if list is full then call resize
	if(L.count == L.max){
		L = resize(L);
	}
	
	int pos = 0;
	while(pos < L.count && L.elemPtr[pos] < data){
		pos++;
	}
	
	return insertPos(L, data, pos);
}

int locate(List L, int data){
	int i;
	for(i = 0; i < L.count; i++){
		if(L.elemPtr[i] == data){
			return i;
		}
	}
	return -1;
}

void display(List L){
	int i;	
	printf("List: ");
	for(i = 0; i < L.count; i++){
		printf("%d ", L.elemPtr[i]);
	}
	printf("\n");
	printf("Count: %d\n", L.count);
	printf("Max: %d\n", L.max);
}




int main(){
	List L;
	L = initialize(L);
	L = insertPos(L, 1, 0); 
    L = insertPos(L, 3, 1); 
    L = insertPos(L, 2, 2); 
    L = insertPos(L, 5, 3); 
    display(L);
    printf("\n");
    
	L = insertPos(L, 4, 2); 
	display(L);
	printf("\n");
	
	L = deletePos(L, 1); 
	display(L);
	printf("\n");
	
	int pos = locate(L, 5);
	printf("Locate 5: %d\n", pos);
	printf("\n");
	
	List S;
	S = initialize(S);
	S = insertPos(S, 1, 0);
	S = insertPos(S, 3, 1);
	S = insertPos(S, 5, 2);
	S = insertPos(S, 10, 3);
	display(S);
	printf("\n");
	
	S = insertSorted(S, 8);
	display(S);
	printf("\n");
	
	free(L.elemPtr);
	free(S.elemPtr);
	return 0;
}
